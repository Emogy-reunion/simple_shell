#include "shell.h"

/**
 * separate_and_builtin - separtes commands
 * @number_arguments: number of arguments in the command
 * @arguments: the arguments
 */
void separate_and_builtin(int number_arguments, char *arguments[])
{
	int i = 0;
	int num_commands = 0;
	int k, j, z;
	char *commands[MAXIMUM_ARGUMENTS][MAXIMUM_ARGUMENTS + 1];

	while (i < number_arguments)
	{
		j = i;
		while (j < number_arguments && my_strcmp(arguments[j], ";") != 0)
			j++;
		if (j > i)
		{
			for (z = 0; z < j - i; z++)
				commands[num_commands][z] = arguments[i + z];
			commands[num_commands][j - 1] = NULL;
			num_commands++;
			i = j + i;
		}
		else
			i++;
	}
	for (k = 0; k < num_commands; k++)
	{
		if (my_strcmp(commands[k][0], "exit") == 0)
			custom_exit_handling(commands[k]);
		else if (my_strcmp(commands[k][0], "env") == 0)
			custom_env_handling();
		else if (my_strcmp(commands[k][0], "cd") == 0)
			custom_cd_handling(commands[k]);
		else if (my_strcmp(commands[k][0], "unsetenv") == 0)
			custom_unsetenv_handling(commands[k]);
		else if (my_strcmp(commands[k][0], "setenv") == 0)
			custom_setenv_handling(commands[k]);
		else
			search_run_directive(commands[k]);
	}
}
