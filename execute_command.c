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

	args = tokenize_command(command_with_args, &num_args);
	if (args == NULL)
		return;

	pid = fork();
	if (pid == -1)
	{
		handle_error();
		free(args);
		return;
	}

	if (pid == 0)
	{
		execute(args);
	}
	else
		wait(NULL);
	free(args);
}
