#include "simpleshell.h"
#include <errno.h>

/**
 * execute_child_process - Executes the command in the child process.
 * @command: The command to be executed.
 */

void execute_child_process(char *command)
{
	FILE *fp;

	char output_line[MAX_COMMAND_LENGTH];


	fp = popen(command, "r");
	if (fp == NULL)
	{
		perror("Error opening pipe");
		exit(EXIT_FAILURE);
	}


	while (fgets(output_line, MAX_COMMAND_LENGTH, fp) != NULL)

	{
		printf("%s", output_line);
	}

			if (pclose(fp) == -1)

			{
				perror("Error closing pipe");
				exit(EXIT_FAILURE);

			}

			exit(EXIT_SUCCESS);
}
