#include "shell.h"
/**
 * interactive_mode - takes commands from user
 */
void interactive_mode(void)
{
	char *input = NULL;
	char *token = NULL;
	char *replaced_input = NULL;
	int number_arguments;
	size_t length = 0;
	char *arguments[MAXIMUM_ARGUMENTS + 1];

	while (1)
	{
		write(1, "SHELL$ ", 7);
		fflush(stdout);
		if (custom_getline(&input, &length, 1) != -1)
			break;
		if (input[0] == '#')
			continue;
		replaced_input = substitute_vars(input);
		number_arguments = 0;
		token = strtok(replaced_input, " \t\n");
		while (token != NULL && number_arguments < MAXIMUM_ARGUMENTS)
		{
			arguments[number_arguments] = token;
			token = strtok(NULL, " \t\n");
			number_arguments++;
		}
		arguments[number_arguments] = NULL;
		if (number_arguments == 0)
			continue;
		separate_and_builtin(number_arguments, arguments);
		free(replaced_input);
	}
	free(input);
}


