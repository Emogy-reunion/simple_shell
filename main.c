#include "shell.h"

/**
 * main - function that enables shell interactive and non-interactive mode
 * @argc: argument character
 * @argv: double pointer to a character that is an agrument vector
 * Return: Always 0 Sucess
 */

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		file_input(argv[1]);
	}
	else
	{
		interactive_mode();
	}
	return (0);
}
