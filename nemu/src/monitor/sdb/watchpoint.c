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

#include "sdb.h"
#include "utils.h"

#define NR_WP 32

static WP wp_pool[NR_WP] = {};
static WP *head = NULL, *free_ = NULL;
static word_t wp_value[NR_WP] = {};

void init_wp_pool() {
  int i;
  for (i = 0; i < NR_WP; i ++) {
    wp_pool[i].NO = i;
    wp_pool[i].next = (i == NR_WP - 1 ? NULL : &wp_pool[i + 1]);
  }

  head = NULL;
  free_ = wp_pool;
}

/* TODO: Implement the functionality of watchpoint */

WP* new_wp(char *exp, bool *success) {
  if(free_ == NULL) {
    fprintf(stderr, "No more free watchpoints available.\n");
    *success = false;
    return NULL;
  }

  WP *wp = free_;
  strcpy(wp->expr, exp);
  word_t result = expr(wp->expr, success);
  if(*success) {
    wp_value[wp->NO] = result;
    printf("Initial value: %d\n", wp_value[wp->NO]);
  }
  else {
    wp = NULL;
    printf("Invalid expr: %s\n", exp);
    *success = false;
    return NULL;
  }

  free_ = free_->next;
  wp->next = head;
  head = wp;

  *success = true;
  return wp;
}

void free_wp(int num, bool *success) {

  if(head == NULL) {
    printf("No watchpoints now.\n");
    *success = false;
    return;
  }

  WP *prev = head;
  WP *pres = head;

  if (head->NO == num) {
    head = head->next;
    prev->next = free_;
    free_ = prev;
  } else {
    pres = prev->next;
    while (pres != NULL && pres->NO != num) {
      prev = pres;
      pres = pres->next;
    }
    if (pres == NULL) {
      printf("Watch point not found.\n");
      *success = false;
      return;
    } else {
      prev->next = pres->next;
      pres->next = free_;
      free_ = pres;
    }
  }
  printf("Watchpoint %s removed.\n", pres->expr);
  *success = true;
  return;
}

void print_wp() {
  WP *wp = head;
  printf("Watchpoints:\n");
  while (wp != NULL) {
    printf("NO.%d: %s = %d\n", wp->NO, wp->expr, wp_value[wp->NO]);
    wp = wp->next;
  }
}

void check_watchpoint(int *state) {
  WP *wp = head;
  bool success;
  bool flag = true;
  while (wp != NULL) {
    word_t result = expr(wp->expr, &success);
    if(result != wp_value[wp->NO]) {
      printf("Watchpoint %s changed: %d --> %d\n", wp->expr, wp_value[wp->NO], result);
      flag = false;
    }
  }
  if(!flag) {
    *state = NEMU_STOP;
  }
}
