#include "shell.h"

/**
 * handle_builtin - function to handle builtins
 * @arguments: an array taht points to a string
 * Return : nothing
 */

void handle_builtin(char *arguments[])
{
	if (my_strcmp(arguments[0], "exit") == 0)
		custom_exit_handling(arguments);
	else if (my_strcmp(arguments[0], "env") == 0)
		custom_env_handling();
	else if (my_strcmp(arguments[0], "cd") == 0)
		custom_cd_handling(arguments);
	else if (my_strcmp(arguments[0], "unsetenv") == 0)
		custom_unsetenv_handling(arguments);
	else if (my_strcmp(arguments[0], "setenv") == 0)
		custom_setenv_handling(arguments);
	else
		search_run_directive(arguments);
}
