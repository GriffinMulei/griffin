#include "shell.h"
/**
 * print_env - prints environment variables
 *
 * Return: 0
 */

int print_env(void)
{
	char **env;

	for (env = environ; *env != NULL; env++)
	{
		printf("%s\n", *env);
	}

	return (0);
}
