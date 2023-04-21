#include "shell.h"

/**
 * execute_command - executes a command
 *
 * @command_with_args: A string containg command to execute
 *
 */

void execute_command(char *command_with_args)
{
	char **args;
	int num_args = 0;
	pid_t pid;

	args = tokenize_command(command_with_args," ",&num_args);
	if (args == NULL)
		return;

	pid = fork();
	if (pid == -1)
	{
		perror("Fork failed");
		exit(EXIT_FAILURE);
	}

	if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
		{
			perror("Exec failed");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(NULL);
	}

	free(args);
}
