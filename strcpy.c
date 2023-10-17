#include <string.h>
#include <stdio.h>

/**
 * my_strcpy - function to copy string
 * @location: place where the string should be copied
 * @origin: place where the string was obtained
 * Return: nothing
 */

void my_strcpy(char *location, const char *origin)
{
	if (location == NULL || origin == NULL)
	{
		return;
	}
	while (*origin)
	{
		*location = *origin;
		origin++;
		location++;
	}
	*location = '\0';
}
