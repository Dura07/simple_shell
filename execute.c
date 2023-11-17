#include "simpleshell.h"
#include <errno.h>

/**
 * execute_child_process - Executes the command in the child process.
 * @command: The command to be executed.
 */
void execute_child_process(char *command)
{
	pid_t child_pid;
	int pipe_fd[2];

	if (pipe(pipe_fd) == -1)
	{
		perror("Error creating pipe");
		exit(EXIT_FAILURE);
	}

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error forking");
		exit(EXIT_FAILURE);
	}

	if (child_pid == 0)

		child_process(pipe_fd, command);

	else
		parent_process(pipe_fd);

}

/**
 * child_process - Code executed by the child process.
 * @pipe_fd: The file descriptors of the pipe.
 * @command: The command to be executed.
 */
void child_process(int pipe_fd[2], char *command)
{
	close(pipe_fd[0]);
	dup2(pipe_fd[1], STDOUT_FILENO);

	if (execl("/bin/sh", "/bin/sh", "-c", command, (char *)NULL) == -1)
	{
		perror("Error executing command");
		exit(EXIT_FAILURE);
	}
}


/**
 * parent_process - Code executed by the parent process.
 * @pipe_fd: The file descriptors of the pipe.
 */
void parent_process(int pipe_fd[2])
{
	char buffer[MAX_COMMAND_LENGTH];
	ssize_t bytesRead;

	while ((bytesRead = read(pipe_fd[0], buffer, sizeof(buffer))) > 0)
		write(STDOUT_FILENO, buffer, bytesRead);

	close(pipe_fd[0]);
}
