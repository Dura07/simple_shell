#include "simpleshell.h"
#include <stdio.h>

/**
 * main - runs simple shell
 *
 * Return:success
 */
int main(void)

{
	char input[MAX_COMMAND_LENGTH];

	initialize_environ();

	while (1)

	{
		display_prompt();

		if (fgets(input, MAX_COMMAND_LENGTH, stdin) == NULL)

		{
			perror("Error reading command");
			exit(EXIT_FAILURE);
		}


		input[strcspn(input, "\n")] = '\0';

		if (strcmp(input, "exit") == 0)

		{
			printf("Exiting shell.\n");
			break;
		}

		execute_command(input);
	}

	return (0);
}
