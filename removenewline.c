#include "shell.h"

/**
 * reject_chars -finds length of string that doesnt contain
 * specified characters
 * @string: the input string
 * @reject: the character to remove
 * Return: length of substring
 */
size_t reject_chars(const char *string, const char *reject)
{
	int found;
	size_t counter = 0;
	const char *remove;

	while (*string)
	{
		remove = reject;
		found = 0;
		while (*remove)
		{
			if (*string == *remove)
			{
				found = 1;
				break;
			}
			remove++;
		}
		if (found)
			break;
		string++;
		counter++;
	}
	return (counter);
}

