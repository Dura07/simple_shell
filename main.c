#include "simpleshell.h"
#include <stdio.h>

/**
 * main - runs simple shell
 *
 * Return:success
 */
int main(void)
{
	char command[MAX_COMMAND_LENGTH];

	while (1)
	{
		display_prompt();

		if (fgets(command, sizeof(command), stdin) == NULL)
		{
			if (isatty(STDIN_FILENO))
			{
				printf("\n");
			}
			break;
		}

		command[strcspn(command, "\n")] = '\0';

		execute_command(command);
	}
	return (0);
}
