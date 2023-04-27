#include "shell.h"

/**
 * execute_command - func to execute a command
 *
 * @command_with_args: string containing command to execute
 * @program_name: Program name running the shell
 * @line_number: No. of line where the command was read
 *
 * Return: 0 Success
 */
int execute_command(char *command_with_args,
		char *program_name, int line_number)
{
	char **args;
	int num_args = 0;
	int status = 0;
	pid_t pid;

	command_with_args[strcspn(command_with_args, "\n")] = '\0';

	args = tokenize_command(command_with_args, " ", &num_args);
	if (args == NULL)
		return (1);

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
			fprintf(stderr, "%s: %d: %s: not found\n",
				program_name, line_number, args[0]);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		if (wait(&status) == -1)
		{
			perror("wait");
			exit(EXIT_FAILURE);
		}
		if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
			return (1);
	}

	free(args);
	return (0);
}
