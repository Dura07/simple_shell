#include "simpleshell.h"


#define MAX_COMMAND_LENGTH 100
/**
 * execute_child_process - Executes the command in the child process.
 * @command: The command to be executed.
 */
static void execute_child_process(char *command)
{
        char *args[2];

        args[0] = command;
        args[1] = NULL;

        if (execve(command, args, environ) == -1)
        {
                perror(command);
                _exit(EXIT_FAILURE);
        }
}



/**
 * display_prompt - Display a simple shell prompt
 *
 * Return: void
 */

void display_prompt(void)
{
        if (isatty(STDIN_FILENO))
        {
                printf("($) ");
                fflush(stdout);
        }
}

/**
 * execute_command - Forks a new process and executes the given command.
 * @command: The command to be executed.
 */
void execute_command(char *command)
{
        char *trimmed_command = trim_spaces(command);

        pid_t pid = fork();

        if (pid == -1)
        {
                perror("Fork failed");
                exit(EXIT_FAILURE);
        }
        else if (pid == 0)
                execute_child_process(trimmed_command);

        else
        {
                int status;

                if (waitpid(pid, &status, 0) == -1)
                {
                        perror("Waitpid failed");
                        exit(EXIT_FAILURE);
                }
        }
        free(trimmed_command);
}
/**
 * trim_spaces - Removes leading and trailing spaces from a string.
 * @str: The input string to be trimmed.
 * Return: A pointer to the trimmed string.
 */
char *trim_spaces(char *str)
{
        size_t len = strlen(str);
        size_t start = 0, end = len - 1;

        size_t trimmed_len = (end >= start) ? (end - start + 1) : 0;

        char *trimmed = (char *)malloc(trimmed_len + 1);

        if (!trimmed)
        {
                perror("Memory allocation failed");

                exit(EXIT_FAILURE);
        }

        while (start < len && str[start] == ' ')
                start++;

        while (end > start && str[end] == ' ')
                end--;

        strncpy(trimmed, str + start, trimmed_len);
        trimmed[trimmed_len] = '\0';

        return (trimmed);
}
