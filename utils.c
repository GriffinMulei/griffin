#include "shell.h"

/**
 * tokenize_command - tokenizes a command into args
 *
 * @command_with_args: string containing the command & args
 * @num_args: pointer to an int that stores the no. of args
 *
 * Return: arr of strings that contains the args
 *         NULL if there is an error
 */

char **tokenize_command(char *command_with_args, int *num_args)
{
	char *token;
	char **args;
	int i;

	token = strtok(command_with_args, " ");
	while (token != NULL)
	{
		(*num_args)++;
		token = strtok(NULL, " ");
	}

	args = malloc(((*num_args) + 1) * sizeof(char *));

	if (args == NULL)
	{
		handle_error();
		return (NULL);
	}
	token = strtok(command_with_args, " ");

	for (i = 0; i < (*num_args); i++)
	{
		args[i] = token;
		token = strtok(NULL, " ");
	}

	args[(*num_args)] = NULL;

	return (args);
}

/**
 * execute - executes a command
 *
 * @args: an arr of args
 */

void execute(char **args)
{
	if (execvp(args[0], args) == -1)

	{
		handle_error();
		exit(EXIT_FAILURE);
	}
}
