#include "shell.h"

/**
 * carry_out_directive - function to execute a program
 * @directive: this will be the command which points to a character
 * @arguments: this will be an option which a double pointer to a character
 * Return: nothing
 */

void carry_out_directive(char *directive, char **arguments)
{
	pid_t child_pid;
	int wait_status;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("failed to fork");
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		if (execve(directive, arguments, NULL) == -1)
		{
			perror("failed to replace program");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		if (waitpid(child_pid, &wait_status, 0) == -1)
		{
			perror("failed to wait for child process");
			exit(EXIT_FAILURE);
		}
	}
}
