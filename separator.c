#include "shell.h"

/**
 * separate_and_builtin - handles multiple commands
 * @number_arguments: numberr of commands
 * @arguments: the commands and their arguments
 */
void separate_and_builtin(int number_arguments, char *arguments[])
{
	char *directives[MAXIMUM_ARGUMENTS][MAXIMUM_ARGUMENTS + 1];
	int num_directives = 0;
	int i = 0;
	int j, k, z;

	while (i < number_arguments)
	{
		j = i;
		while (j < number_arguments && my_strcmp(arguments[j], ";") != 0)
			j++;
		if (j > i)
		{
			for (k = 0; k < j - i; k++)
				directives[num_directives][k] = arguments[i + k];
			directives[num_directives][j - i] = NULL;
			num_directives++;
			i = j + 1;
		}
		else
			i++;
	}
	for (z = 0; z < num_directives; z++)
	{
		if (my_strcmp(directives[z][0], "exit") == 0)
			custom_exit_handling(directives[z]);
		else if (my_strcmp(directives[z][0], "cd") == 0)
			custom_cd_handling(directives[z]);
		else if (my_strcmp(directives[z][0], "setenv") == 0)
			custom_setenv_handling(directives[z]);
		else if (my_strcmp(directives[z][0], "env") == 0)
			custom_env_handling();
		else if (my_strcmp(directives[z][0], "unsetenv") == 0)
			custom_unsetenv_handling(directives[z]);
		else
			search_run_directive(directives[z]);
	}
}
