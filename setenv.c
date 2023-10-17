#include "shell.h"

/**
 * custom_setenv_handling - setes environment variables
 * @arguments: the arguments to setenv
 */
void custom_setenv_handling(char **arguments)
{
	int outcome = 0;
	const char *message = "Usage: setenv VARIABLE VALUE\n";

	if (arguments[1] == NULL || arguments[2] == NULL)
	{
		write(STDERR_FILENO, message, custom_string_length(message));
		return;
	}
	outcome = setenv(arguments[1], arguments[2], 1);
	if (outcome == -1)
		perror("Failed to set environment");
}
