#include "shell.h"

/**
 * custom_exit_handling - function to handle the exit builtin
 * @arguments: double pointer to a character which is an argument
 * Return: nothing
 */

void custom_exit_handling(char **arguments)
{
	int quit_status = 0;

	if (arguments[1] != NULL)
	{
		quit_status = custom_atoi(arguments[1]);
	}
	exit(quit_status);
}
