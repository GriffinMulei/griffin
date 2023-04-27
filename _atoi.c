#include "shell.h"

/**
 * _atoi - convert string to interger
 * @s: pointer to convert
 * Return: an integer
 */
int _atoi(char *s)

{
	int i = 0;
	unsigned int result = 0;
	int sign = 1;
	int hasDigits = 0, output;

	while (s[i])
	{
		if (s[i] == '-')
		{
			sign *= -1;
		}
		while (s[i] >= '0' && s[i] <= '9')
		{
			hasDigits = 1;
			result *=  10;
			result	+= (s[i] - '0');
		}
		if (hasDigits == 1)
			hasDigits = 2;
	}
	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}

/**
 *  _isalpha - checks if a character is alphabetic
 *  @c: the character to be checked
 *
 *  Return: 1 if c is a letter, lowercase or uppercase, 0 otherwise
 */
int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
