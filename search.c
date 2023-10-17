#include "shell.h"

/**
 * search_run_directive - function to handle the run command
 * @arguments: double pointer to a character which is an argument)
 * Return: nothing
 */

void search_run_directive(char **arguments)
{
	char *route_copy;
	char *route;
	char *route_token;
	char dir_rou[MAXIMUM_ENTRY_LENGTH];

	if (arguments[0][0] == '/')
	{
		if (access(arguments[0], X_OK) == 0)
			carry_out_directive(arguments[0], arguments);
		else
		{
			fprintf(stderr, "command not found: %s\n", arguments[0]);
		}
	}
	else
	{
		route = getenv("PATH");
		route_copy = string_dup(route);
		route_token = strtok(route_copy, ":");

		while (route_token != NULL)
		{
			snprintf(dir_rou, sizeof(dir_rou), "%s/%s", route_token, arguments[0]);
			if (access(dir_rou, X_OK) == 0)
			{
				carry_out_directive(dir_rou, arguments);
				break;
			}
			route_token = strtok(NULL, ":");
		}
		free(route_copy);
		if (route_token == NULL)
		{
			fprintf(stderr, "Command not found: %s\n", arguments[0]);
		}
	}
}
