#include <stdio.h>
#include <string.h>

/**
 * my_strcmp - function to compare two strings
 * @word1: first string
 * @word2: second string
 * Return: Always Success
 */

int my_strcmp(const char *word1, const char *word2)
{
	while (*word1 && *word2 && *word1 == *word2)
	{
		word1++;
		word2++;
	}
	return (*word1 - *word2);
}
