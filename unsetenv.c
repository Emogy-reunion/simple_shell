#include "shell.h"

/**
 * custom_unsetenv_handling - removes environment variables
 * @arguments: the command and its arguments
 */
void custom_unsetenv_handling(char **arguments)
{
	int outcome = 0;
	const char *message = "Usage: unsetenv VARIABLE\n";

	if (arguments[1] == NULL)
	{
		write(STDERR_FILENO, message, custom_string_length(message));
		return;
	}
	outcome = unsetenv(arguments[1]);
	if (outcome == -1)
		perror("Failed to unset variable");
}
