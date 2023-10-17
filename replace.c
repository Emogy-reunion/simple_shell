#include "shell.h"

/**
 * substitute_vars - replaces shell variables
 * @entry: the string to be replaced
 * Return: replaced input
 */
char *substitute_vars(char *entry)
{
	int quit_status = 0;
	pid_t session;
	char *outcome;
	char *processed_output;
	char *pointer;

	session = getpid();
	outcome = malloc(MAXIMUM_ENTRY_LENGTH);
	if (outcome == NULL)
	{
		perror("Failed to allocate memory");
		exit(EXIT_FAILURE);
	}
	processed_output = outcome;
	pointer = entry;
	while (*pointer)
	{
		if (pointer[0] == '$' && pointer[1] == '?')
		{
			snprintf(processed_output, 4, "%d", quit_status);
			processed_output += 2;
			pointer += 2;
		}
		else if (pointer[0] == '$' && pointer[1] == '$')
		{
			snprintf(processed_output, 10, "%d", session);
			processed_output += 4;
			pointer += 2;
		}
		else
			*processed_output++ = *pointer++;
	}
	*processed_output = '\0';
	return (outcome);
}

