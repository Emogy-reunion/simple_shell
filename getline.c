#include "shell.h"

/**
 * custom_getline - gets the input from the user
 * @entry: buffer to store use inpuut
 * @length: length of the input
 * @fd: where to get the input
 * Return: the user's input
 */

ssize_t custom_getline(char **entry, size_t *length, int fd)
{
	size_t line_length = 0;
	ssize_t read_bytes = 0;
	char *line = NULL;

	create_buffer(entry, length);
	line = *entry;
	while (1)
	{
		if (line_length >= *length)
		{
			reallocate_buffer(entry, length);
			line = *entry;
		}
		read_bytes = read(fd, &line[line_length], 1);
		if (read_bytes < 0)
		{
			perror("Failed to read input");
			exit(1);
		} else if (read_bytes == 0)
		{
			if (line_length == 0)
			{
				return (-1);
			}
			else
			{
				line[line_length] = '\0';
				return (line_length);
			}
		}
		else
		{
			if (line[line_length] == '\n')
			{
				line[line_length] = '\0';
				return (line_length);
			}
			line_length++;
		}
	}
}

/**
 * create_buffer - initializes the buffer to store user input
 * @entry: the buffer to create
 * @length: the length of input
 */
void create_buffer(char **entry, size_t *length)
{
	if (*entry == NULL || *length == 0)
	{
		*length = MAXIMUM_BUFFER_SIZE;
		*entry = (char *)malloc(*length);
		if (*entry == NULL)
		{
			perror("Failed to allocate memory");
			exit(1);
		}
	}
}

/**
 * reallocate_buffer - resizes the bufferr
 * @entry: buffer to resize
 * @length:  the length of input
 */
void reallocate_buffer(char **entry, size_t *length)
{
	*length *= 2;
	*entry = (char *)realloc(*entry, *length);
	if (*entry == NULL)
	{
		perror("Memory reallocation failed");
		exit(1);
	}
}
