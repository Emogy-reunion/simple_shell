#include "shell.h"

/**
 * main - entry point
 * @argc: number of arguments
 * @argv: comand line arguments
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
	if (argc == 2)
		get_file(argv[1]);
	else
		interactive_mode();
	return (0);
}
