/***************************************************************************************
* Copyright (c) 2014-2022 Zihao Yu, Nanjing University
*
* NEMU is licensed under Mulan PSL v2.
* You can use this software according to the terms and conditions of the Mulan PSL v2.
* You may obtain a copy of Mulan PSL v2 at:
*          http://license.coscl.org.cn/MulanPSL2
*
* THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
* EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
* MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
*
* See the Mulan PSL v2 for more details.
***************************************************************************************/

#include <isa.h>

/* We use the POSIX regex functions to process regular expressions.
 * Type 'man regex' for more information about POSIX regex functions.
 */
#include <regex.h>

enum {
  TK_NOTYPE = 256, TK_EQ,

  /* TODO: Add more token types */

  TK_PLUS,         // 加号
  TK_MINUS,        // 减号
  TK_MUL,          // 乘号
  TK_DIV,          // 除号
  TK_LT,           // 小于
  TK_GT,           // 大于
  TK_LE,           // 小于等于
  TK_GE,           // 大于等于
  TK_NEQ,          // 不等于
  TK_AND,          // 逻辑与
  TK_OR,           // 逻辑或
  TK_LPAREN,       // 左括号
  TK_RPAREN,       // 右括号
  TK_NUM,          // 数字
  TK_DEREF,        // 解引用
  TK_REV,          // 负数
  TK_REG,
  TK_HEX,

};

static struct rule {
  const char *regex;
  int token_type;
} rules[] = {

    /* TODO: Add more rules.
     * Pay attention to the precedence level of different rules.
     */

    {" +", TK_NOTYPE},  // spaces
    {"<=", TK_LE},      // 小于等于
    {">=", TK_GE},      // 大于等于
    {"<", TK_LT},       // 小于
    {">", TK_GT},       // 大于
    {"==", TK_EQ},      // equal
    {"!=", TK_NEQ},     // 不等于
    {"&&", TK_AND},     // 逻辑与
    {"\\|\\|", TK_OR},  // 逻辑或
    {"\\(", TK_LPAREN}, // 左括号
    {"\\)", TK_RPAREN}, // 右括号
    {"\\+", TK_PLUS},   // 加号
    {"-", TK_MINUS},    // 减号
    {"\\*", TK_MUL},    // 乘号
    {"/", TK_DIV},      // 除号
    {"0x[0-9a-fA-F]+", TK_HEX},
    {"[0-9]+", TK_NUM},   // 数字
    {"$[a-z$][0-9a-z][0-9a-z]", TK_REG},

};

#define NR_REGEX ARRLEN(rules)

static regex_t re[NR_REGEX] = {};

/* Rules are used for many times.
 * Therefore we compile them only once before any usage.
 */
void init_regex() {
  int i;
  char error_msg[128];
  int ret;

  for (i = 0; i < NR_REGEX; i ++) {
    ret = regcomp(&re[i], rules[i].regex, REG_EXTENDED);
    if (ret != 0) {
      regerror(ret, &re[i], error_msg, 128);
      panic("regex compilation failed: %s\n%s", error_msg, rules[i].regex);
    }
  }
}

typedef struct token {
  int type;
  char str[32];
} Token;

static Token tokens[32] __attribute__((used)) = {};
static int nr_token __attribute__((used))  = 0;

static bool make_token(char *e) {
  int position = 0;
  int i;
  regmatch_t pmatch;

  nr_token = 0;

  while (e[position] != '\0') {
    /* Try all rules one by one. */
    for (i = 0; i < NR_REGEX; i ++) {
      if (regexec(&re[i], e + position, 1, &pmatch, 0) == 0 && pmatch.rm_so == 0) {
        char *substr_start = e + position;
        int substr_len = pmatch.rm_eo;

        Log("match rules[%d] = \"%s\" at position %d with len %d: %.*s",
            i, rules[i].regex, position, substr_len, substr_len, substr_start);

        position += substr_len;

        /* TODO: Now a new token is recognized with rules[i]. Add codes
         * to record the token in the array `tokens'. For certain types
         * of tokens, some extra actions should be performed.
         */

        switch (rules[i].token_type) {
          case TK_LE:
          case TK_GE:
          case TK_LT:
          case TK_GT:
          case TK_EQ:
          case TK_NEQ:
          case TK_AND:
          case TK_OR:
          case TK_PLUS:
          case TK_DIV:
            tokens[nr_token].type = rules[i].token_type;
            nr_token++;
            break;
          case TK_MINUS:
            if (i == 0 || (tokens[i - 1].type != TK_NUM && tokens[i - 1].type != TK_RPAREN))
              tokens[nr_token].type = TK_REV;
            else
              tokens[nr_token].type = rules[i].token_type;
            nr_token++;
            break;
          case TK_MUL:
            if (i == 0 || (tokens[i - 1].type != TK_NUM && tokens[i - 1].type != TK_RPAREN))
              tokens[nr_token].type = TK_DEREF;
            else
              tokens[nr_token].type = rules[i].token_type;
            nr_token++;
            break;
          case TK_REG:
          case TK_HEX:
          case TK_NUM:
            tokens[nr_token].type = rules[i].token_type;
            strncpy(tokens[nr_token].str, substr_start, substr_len);
            nr_token++;
            break;
          case TK_NOTYPE:
            break;
          case TK_LPAREN:
          case TK_RPAREN:
            tokens[nr_token].type = rules[i].token_type;
            nr_token++;
            break;
          default:
            printf("Unknown token at position %d: %.*s\n", position, substr_len, substr_start);
            return false;
        }

        break;
      }
    }

    if (i == NR_REGEX) {
      printf("no match at position %d\n%s\n%*.s^\n", position, e, position, "");
      return false;
    }
  }

  return true;
}

// 定义一个栈结构
typedef struct
{
  word_t data[32];
  int top;
} Stack;

// 初始化栈
void init_stack(Stack *stack)
{
  stack->top = -1;
}

// 将元素压入栈
void push(Stack *stack, word_t value)
{
  stack->data[++stack->top] = value;
}

// 从栈中弹出元素
word_t pop(Stack *stack)
{
  assert(stack->top != -1);
  return stack->data[stack->top--];
}

int precedence(int type){
  switch (type) {
    case TK_REV:
    case TK_DEREF:
      return 3;
    case TK_LE:
    case TK_GE:
    case TK_LT:
    case TK_GT:
    case TK_EQ:
    case TK_NEQ:
    case TK_AND:
    case TK_OR:
      return 2;
    case TK_MUL:
    case TK_DIV:
      return 1;
    case TK_PLUS:
    case TK_MINUS:
      return 0;
    default:
      panic("precedence error: Unknown type %d\n", type);
    }
}

word_t perform_operation(word_t op1, word_t operator, word_t op2, bool *success) {
  *success = true;
  switch (operator) {
    case TK_LE:
      return op1 <= op2;
    case TK_GE:
      return op1 >= op2;
    case TK_LT:
      return op1 < op2;
    case TK_GT:
      return op1 > op2;
    case TK_EQ:
      return op1 = op2;
    case TK_NEQ:
      return op1 != op2;
    case TK_AND:
      return op1 && op2;
    case TK_OR:
      return op1 || op2;
    case TK_PLUS:
      return op1 + op2;
    case TK_MINUS:
      return op1 - op2;
    case TK_MUL:
      return op1 * op2;
    case TK_DIV:
      if(op2 == 0) {
        printf("div 0 is not allowed!\n");
        *success = false;
        return 0;
      } 
      else {
        return op1 / op2;
      }
    default:
      printf("perform error: Unknown type %d\n", operator);
      *success = false;
      return 0;
    }
}

word_t expr(char *e, bool *success)
{
  if (!make_token(e))
  {
    *success = false;
    return 0;
  }

  Stack operand_stack;  // 操作数栈
  Stack operator_stack; // 操作符栈

  init_stack(&operand_stack);
  init_stack(&operator_stack);

  int pos = 0;

  while (pos < nr_token)
  {
    Token token = tokens[pos];

    switch (token.type) {
      word_t result;
      case TK_REV:
      case TK_DEREF:
        push(&operator_stack, token.type);
        break;
      case TK_REG:
        result = isa_reg_str2val(token.str, success);
        if(*success) {
          while (operator_stack.top >= 0 && operator_stack.data[operator_stack.top] == TK_REV) {
            pop(&operator_stack);
            result = (word_t)(-result);
          }
          push(&operand_stack, result);
          break;
        }
        else {
          return 0;
        }
      case TK_HEX:
        sscanf(token.str, "%x", &result);
        while (operator_stack.top >= 0 && operator_stack.data[operator_stack.top] == TK_REV) {
          pop(&operator_stack);
          result = (word_t)(-result);
        }
        push(&operand_stack, result);
        break;
      case TK_NUM:
        result = atoi(token.str);
        while (operator_stack.top >= 0 && operator_stack.data[operator_stack.top] == TK_REV) {
          pop(&operator_stack);
          result = (word_t)(-result);
        }
        push(&operand_stack, result);
        break;
      case TK_LE:
      case TK_GE:
      case TK_LT:
      case TK_GT:
      case TK_EQ:
      case TK_NEQ:
      case TK_AND:
      case TK_OR:
      case TK_PLUS:
      case TK_MINUS:
      case TK_MUL:
      case TK_DIV:
        while (operator_stack.top >= 0 && operator_stack.data[operator_stack.top] != TK_LPAREN &&
              precedence(token.type) <= precedence(operator_stack.data[operator_stack.top])) {
          word_t op2 = pop(&operand_stack);
          word_t op1 = pop(&operand_stack);
          word_t operator= pop(&operator_stack);
          result = perform_operation(op1, operator, op2, success);
          if(*success) {
            push(&operand_stack, result);
          }
          else {
            return 0;
          }
        }
        push(&operator_stack, token.type);
        break;

      case TK_LPAREN:
        push(&operator_stack, token.type);
        break;

      case TK_RPAREN:
        while (operator_stack.top >= 0 && operator_stack.data[operator_stack.top] != TK_LPAREN) {
          word_t op2 = pop(&operand_stack);
          word_t op1 = pop(&operand_stack);
          word_t operator= pop(&operator_stack);
          result = perform_operation(op1, operator, op2, success);
          if(*success) {
            push(&operand_stack, result);
          }
          else {
            return 0;
          }
        }
        assert(operator_stack.data[operator_stack.top] == TK_LPAREN);
        pop(&operator_stack);
        break;

      default:
        assert(1);
        break;
    }
    pos++;
  }

  // 处理剩余的操作符和操作数
  while (operator_stack.top >= 0)
  {
    word_t operator= pop(&operator_stack);
    if(operator == TK_LPAREN) {
      printf("')' expected in expression\n");
      *success = false;
      return 0;
    }
    word_t op2 = pop(&operand_stack);
    word_t op1 = pop(&operand_stack);
    word_t result = perform_operation(op1, operator, op2, success);
    if(*success) {
      push(&operand_stack, result);
    }
    else {
      return 0;
    }
  }

  // 最终结果在操作数栈中
  if (operand_stack.top == 0) {
    *success = true;
    return operand_stack.data[0];
  }
  else {
    printf("Check the expression!\n");
    *success = false;
    return 0;
  }
}