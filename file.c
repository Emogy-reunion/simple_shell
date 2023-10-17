#include "shell.h"

/**
 * get_file - function to open a file
 * @filedesignate: points to a character
 * Return: nothing
 */

void get_file(const char *filedesignate)
{
	char *line = NULL;
	size_t length = 0;
	char *substitute = NULL;
	char *strpart = NULL;
	int number;
	FILE *file;
	char *arg[MAXIMUM_ARGUMENTS + 1];

	file = fopen(filedesignate, "r");
	if (file == NULL)
	{
		perror("failed to open and read the file");
		exit(EXIT_FAILURE);
	}
	while (getline(&line, &length, file) != -1)
	{
		line[reject_chars(line, "\n")] = '\0';
		if (line[0] == '#')
		{
			continue;
		}
		substitute = substitute_vars(line);
		number = 0;
		strpart = strtok(substitute, "\t\n");
		while (strpart != NULL && number < MAXIMUM_ARGUMENTS)
		{
			arg[number] = strpart;
			strpart = strtok(NULL, "\t\n");
			number++
		}
		arg[number] = NULL;
		if (number == 0)
		{
			continue;
		}
		handle_builtin(arg);
		free(substitute);
	}
	fclose(file);
}
