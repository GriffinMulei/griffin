#include "shell.h"
/**
 * print_env - prints environment variables
 * @keep_var: name of env var to keep
 * Return: 0
 */

int print_env(const char *keep_var)
{
	char **env;
	size_t keep_var_length = strlen(keep_var);

	for (env = environ; *env != NULL; ++env)
	{
		if (strncmp(*env, keep_var, keep_var_length) != 0 ||
			(*env)[keep_var_length] != '=')
		{
			if (unsetenv(*env) == -1)
			{
				perror("unsetenv");
				return (-1);
			}
		}
	}

	if (execlp("env", "env", (char *)NULL) == -1)
	{
		fprintf(stderr, "execlp failed: %s\n", strerror(errno));
		return (-1);
	}

	return (0);
}
