#include "simpleshell.h"
#include <errno.h>

/**
 * execute_child_process - Executes the command in the child process.
 * @command: The command to be executed.
 */

void execute_child_process(char *command)
{
char *args[2];

args[0] = command;
args[1] = NULL;

if (execve(command, args, environ) == -1)
{
if (errno == ENOENT)

{
fprintf(stderr, "%s: command not found\n", command);
_exit(EXIT_FAILURE);
}
else
{
perror(command);
_exit(EXIT_FAILURE);
}
}
}
