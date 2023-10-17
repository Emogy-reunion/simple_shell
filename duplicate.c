#include "shell.h"

/**
 * string_dup - duplicates a string
 * @string: string to be duplicated
 * Return: duplicated string
 */

char *string_dup(const char *string)
{
	size_t len = 0;
	char *dup = NULL;

	if (string == NULL)
		return (NULL);
	len = custom_string_length(string) + 1;
	dup = (char *)malloc(len);
	if (dup != NULL)
	{
		my_strcpy(dup, string);
	}
	return (dup);
}

/**
 * custom_string_length - finds the length of a string
 * @string: string to calculate length
 * Return: length of string
 */
size_t custom_string_length(const char *string)
{
	size_t len = 0;

	while (string[len] != '\0')
		len++;
	return (len);
}
