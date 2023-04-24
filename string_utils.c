#include "shell.h"

/**
 * _putchar - writes a character to the standard output
 * @ch: character to be written
 *
 * Return: number of characters written else -1
*/

int _putchar(char ch)
{
	return (write(1, &ch, 1));
}

/**
 * _put - prints a string followed by anewline
 * @s: pointer to the string to be printed
 *
 * Return: void
*/

void _put(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		_putchar('\n');
	}
}

/**
 * _strlen - func to calculate length of string
 * @str: pointer to the string
 *
 * Return: Length of the string
 */

int _strlen(const char *str)
{
	int length = 0;

	while (*str != '\0')
	{
		length++;
		str++;
	}
	return (length);
}

/**
 * _strncopy - func to copy a string
 * @dest: pointer to destination string
 * @src: pointer to source string
 * @num_chars: no. of characters to copy
 *
 * Return: pointer to destination string
 */

char *_strncopy(char *dest, const char *src, size_t num_chars)
{
	size_t i;

	for (i = 0; i < num_chars && src[i]; i++)
	{
		dest[i] = src[i];
	}
	for (; i < num_chars; i++)
	{
		dest[i] = '\0';
	}
	return (dest);
}

/**
 * _strcmp - function that compares two strings
 * @s1: first string to be comparedd
 * @s2: second string to be compared
 * Return: 0;
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] == s2[i])
	{
		if (s1[i] == '\0')
		{
			return (0);
		}
		i++;
	}
	return (s1[i] - s2[i]);
}
