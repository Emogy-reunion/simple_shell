#include "shell.h"

/**
 * custom_cd_handling - finction to handle cd builtin
 * @arguments: double pointer to a character which is an argument
 * Return: nothing
 */

void custom_cd_handling(char **arguments)
{
	char *fresh_folder = NULL;
	char working_directory[MAXIMUM_ENTRY_LENGTH];
	char fresh_working_folder[MAXIMUM_ENTRY_LENGTH];

	fresh_folder = arguments[1];
	if (fresh_folder == NULL)
		fresh_folder = getenv("HOME");
	if (my_strcmp(fresh_folder, "-") == 0)
		fresh_folder = getenv("OLDPWD");
	if (getcwd(working_directory, sizeof(working_directory)) == NULL)
	{
		perror("EXECUTION OF getcwd failed");
		return;
	}
	if (chdir(fresh_folder) == -1)
	{
		perror("failde to change directory");
		return;
	}
	setenv("OLDPWD", working_directory, 1);
	if (getcwd(fresh_working_folder, sizeof(fresh_working_folder)) == NULL)
	{
		perror("FAILED TO GET THE CURRENT WORKING DIR");
		return;
	}
	setenv("PWD", fresh_working_folder, 1);
}
