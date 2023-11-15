#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100

void display_prompt(void);
void execute_command(char *command);
char *trim_spaces(char *str);

extern char **environ;
#endif /* SIMPLE_SHELL_H */
