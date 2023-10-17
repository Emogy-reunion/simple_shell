#include "shell.h"

/**
 * custom_atoi - converts string to numbers
 * @string: the string to convert
 * Return: converted string
 */
int custom_atoi(const char *string)
{
	int sign;
	int outcome = 0;

	sign = 1;
	while (*string == ' ' || *string == '\t' || *string == '\n')
		string++;
	if (*string == '-')
	{
		sign = -1;
		string++;
	}
	else if (*string == '+')
		string++;
	while (*string >= '0' && *string <= '9')
	{
		outcome = outcome * 10 + (*string - '0');
		string++;
	}
	return (outcome * sign);
}

