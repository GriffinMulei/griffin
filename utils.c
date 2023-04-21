#include "shell.h"

/**
 * tokenize_command - tokenizes a command into args
 *
 * @command_with_args: string containing the command & args
 * @num_args: pointer to an int that stores the no. of args
 * @delimeter: delim
 *
 * Return: arr of strings that contains the args
 *         NULL if there is an error
 */

char **tokenize_command(char *command_with_args,char *delimeter, int *num_args)
{
	char *token;
	char **args;

	args = malloc((MAX_COMMAND_ARGS + 1) * sizeof(char *));
	if (args == NULL)
	{
		handle_error();
		return (NULL);
	}

	token = strtok(command_with_args, delimeter);
	
	while (token != NULL)
	{
		if (*num_args >= MAX_COMMAND_ARGS)
		{
			fprintf(stderr, "Error: too many arguements\n");
			free(args);
			return (NULL);
		}
		args[*num_args] = _strdup(token);
		(*num_args)++;
		token = strtok(NULL, delimeter);
	}
	args[*num_args] = NULL;

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
