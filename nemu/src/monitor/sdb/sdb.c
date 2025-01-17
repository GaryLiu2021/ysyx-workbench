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
#include <cpu/cpu.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "sdb.h"

#ifdef CONFIG_ITRACE
NMU_RINGBUF itrace_buf;
void nmu_ringbuf_init(NMU_RINGBUF* rb, int size);
void nmu_ringbuf_print(NMU_RINGBUF* rb);
void nmu_ringbuf_free(NMU_RINGBUF* rb);
#endif

static int is_batch_mode = false;

/* We use the `readline' library to provide more flexibility to read from stdin. */
static char* rl_gets() {
	static char* line_read = NULL;

	if (line_read) {
		free(line_read);
		line_read = NULL;
	}

	line_read = readline("(nemu) ");

	if (line_read && *line_read) {
		add_history(line_read);
	}

	return line_read;
}

static int cmd_c(char* args) {
	cpu_exec(-1);
	return 0;
}


static int cmd_q(char* args) {
	return -1;
}

static int cmd_help(char* args);

static int cmd_si(char* args) {
	char* endptr;
	if (args == NULL) {
		cpu_exec(1);
	}
	else {
		int cpu_exec_cycle = (word_t)(strtol(args, &endptr, 10));
		if (*endptr != '\0') {
			printf("Conversion failed. Non-numeric characters detected.\n");
			return -1;
		}
		cpu_exec(cpu_exec_cycle);
	}
	return 0;
}

static int cmd_info(char* args) {
	if (args == NULL) {
		printf("Need Args for info.\n");
		return -1;
	}
	else {
		if (*args == 'r') {
			isa_reg_display();
		}
		else if (*args == 'w') {
			print_wp();
		}
		else {
			printf("Invalid input format.\n");
			return -1;
		}
		return 0;
	}
}

static int cmd_x(char* args) {
	if (args == NULL) {
		printf("Need Args for info.\n");
		return -1;
	}
	else {
		int steps;
		uint32_t address;
		int result = sscanf(args, "%d %x", &steps, &address);

		if (result == 2) {
			printf("Steps: %d\n", steps);
			printf("Address: 0x%x\n", address);
			for (int i = 0; i < steps; i++) {
				printf("0x%x: %08x\n", address + i * 4, vaddr_ifetch(address + i * 4, 4));
			}
			return 0;
		}
		else {
			printf("Invalid input format.\n");
			return -1;
		}
	}
}

static int cmd_p(char* args) {
	if (args == NULL) {
		return -1;
	}
	else {
		bool success;
		word_t result = expr(args, &success);
		if (success == true)
			printf("$1 = %d\n", result);
		return (int)(success)-1;
	}
}

static int cmd_w(char* args) {
	if (args == NULL) {
		return -1;
	}
	else {
		bool success;
		new_wp(args, &success);
		return (int)(success)-1;
	}
}

static int cmd_d(char* args) {
	if (args == NULL) {
		return -1;
	}
	else {
		bool success;
		free_wp(atoi(args), &success);
		return (int)(success)-1;
	}
}

static struct {
	const char* name;
	const char* description;
	int (*handler) (char*);
} cmd_table[] = {
  { "help", "Display information about all supported commands", cmd_help },
  { "c", "Continue the execution of the program", cmd_c },
  { "q", "Exit NEMU", cmd_q },
  { "si", "execute CPU by steps(defaault 1)", cmd_si },
  { "info", "print information", cmd_info },
  { "x", "print memory", cmd_x },
  { "p", "print", cmd_p },
  { "w", "add a watchpoint", cmd_w },
  { "d", "delete a watchpoint", cmd_d },

  /* TODO: Add more commands */

};

#define NR_CMD ARRLEN(cmd_table)

static int cmd_help(char* args) {
	/* extract the first argument */
	char* arg = strtok(NULL, " ");
	int i;

	if (arg == NULL) {
		/* no argument given */
		for (i = 0; i < NR_CMD; i++) {
			printf("%s - %s\n", cmd_table[i].name, cmd_table[i].description);
		}
	}
	else {
		for (i = 0; i < NR_CMD; i++) {
			if (strcmp(arg, cmd_table[i].name) == 0) {
				printf("%s - %s\n", cmd_table[i].name, cmd_table[i].description);
				return 0;
			}
		}
		printf("Unknown command '%s'\n", arg);
	}
	return 0;
}

void sdb_set_batch_mode() {
	is_batch_mode = true;
}

void sdb_mainloop() {
	if (is_batch_mode) {
		cmd_c(NULL);
		return;
	}

	for (char* str; (str = rl_gets()) != NULL; ) {
		char* str_end = str + strlen(str);

		/* extract the first token as the command */
		char* cmd = strtok(str, " ");
		if (cmd == NULL) { continue; }

		/* treat the remaining string as the arguments,
		 * which may need further parsing
		 */
		char* args = cmd + strlen(cmd) + 1;
		if (args >= str_end) {
			args = NULL;
		}

#ifdef CONFIG_DEVICE
		extern void sdl_clear_event_queue();
		sdl_clear_event_queue();
#endif

		int i;
		for (i = 0; i < NR_CMD; i++) {
			if (strcmp(cmd, cmd_table[i].name) == 0) {
				if (cmd_table[i].handler(args) < 0) { return; }
				break;
			}
		}

		if (i == NR_CMD) { printf("Unknown command '%s'\n", cmd); }
	}
}

void init_sdb() {
	/* Compile the regular expressions. */
	init_regex();

	/* Initialize the watchpoint pool. */
    init_wp_pool();
    
#ifdef CONFIG_ITRACE
	/* Initialize Itrace buffer*/
    nmu_ringbuf_init(&itrace_buf, 100000);
#endif
}
