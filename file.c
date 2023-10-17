#include "shell.h"

/**
 * file_input - gets input from files
 * @file_name: file containing input
 */
void file_input(const char *file_name)
{
	int fd;
	char *entry = NULL;
	char *replaced_input;
	char *arguments[MAXIMUM_ARGUMENTS + 1];
	char *token;
	size_t length = 0;
	int number_arguments;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		perror("Failed to open the file");
		exit(EXIT_FAILURE);
	}
	while (custom_getline(&entry, &length, fd) != -1)
	{
		entry[reject_chars(entry, "\n")] = '\0';
		if (entry[0] == '#')
			continue;
		number_arguments = 0;
		replaced_input = substitute_vars(entry);
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
		builtin(arguments);
		free(replaced_input);
	}
	close(fd);
	free(entry);
}
