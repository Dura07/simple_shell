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

void initialize_environ(void);
char **get_environ(void);
void display_prompt(void);
void execute_command(char *command);
char *trim_spaces(char *str);
void execute_child_process(char *command);
void child_process(int pipe_fd[2], char *command);
void parent_process(int pipe_fd[2]);

extern char **environ;
#endif /* SIMPLE_SHELL_H */
