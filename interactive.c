#include "shell.h"

/**
 * interactive_mode - gets user input
 */
void interactive_mode(void)
{
	char *splinters = NULL;
	int interactive;
	char *entry = NULL;
	size_t length = 0;
	int number_arguments;
	char *arguments[MAXIMUM_ARGUMENTS + 1];
	char *substituted_entry = NULL;

	interactive = isatty(STDIN_FILENO);
	while (1)
	{
		if (interactive)
		{
			write(STDOUT_FILENO, "SHELL$ ", 7);
			fflush(stdout);
		}
		if (custom_getline(&entry, &length, 0) == -1)
			break;
		if (entry[0] == '#')
			continue;
		substituted_entry = substitute_vars(entry);
		number_arguments = 0;
		splinters = strtok(substituted_entry, " \t\n");
		while (splinters != NULL && number_arguments < MAXIMUM_ARGUMENTS)
		{
			arguments[number_arguments] = splinters;
			splinters = strtok(NULL, " \t\n");
			number_arguments++;
		}
		arguments[number_arguments] = NULL;
		if (number_arguments == 0)
			continue;
		separate_and_builtin(number_arguments, arguments);
		free(substituted_entry);
	}
	free(entry);
}
