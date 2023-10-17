#include "shell.h"

/**
 * custom_env_handling - function that handles the environment
 * Return: nothing
 */
void custom_env_handling(void)
{
	char **env;

	env = environ;
	while (*env)
	{
		printf("%s\n", *env);
		env++;
	}
}
