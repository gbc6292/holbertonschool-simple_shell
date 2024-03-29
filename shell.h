#ifndef SHELL_H
#define SHELL_H

/* Macros */
#define PROMPT "$ "
#define MAX_COMMAND_LEN 256
#define MAX_NUM_ARGS 64

/* Libraries */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <stdarg.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

/* Prototypes */
int is_builtin(char *command);
void execute_builtin(char *command, char **args);
char *command_exists(char *command);
void execute_command(char *command);
char **split_line(char *line);
void display_prompt();

/* Global */
extern char **environ;
#endif
