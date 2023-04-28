#include "shell.h"
int child_exit_status = 0;

/**
 * execute_command - function to execute a command
 *
 * @command_with_args: string containing command to execute
 * @program_name: program name running the shell
 * @line_number: line number where the command was read
 *
 * Return: 0 on success, 1 on failure
 */
int execute_command(char *command_with_args,
		char *program_name, int line_number)
{
	char **args;
	int num_args = 0;
	int exit_code;

	if (command_with_args[0] == '#')
		return (0);

	command_with_args[strcspn(command_with_args, "\n")] = '\0';

	args = tokenize_command(command_with_args, " ", &num_args);
	if (args == NULL)
		return (1);
	exit_code = _execute(args, program_name, line_number);

	free(args);
	return (exit_code);
}

/**
 * _execute - func to execute a command & handle process creation
 *
 * @args: list of command args
 * @program_name: program name
 * @line_number: line no. where the command was read
 *
 * Return: 0 on success, 1 on failure
 */
int _execute(char **args, char *program_name, int line_number)
{
	pid_t pid;
	int status = 0;

	if (args[0] == NULL)
	{
		fprintf(stderr, "%s: %d: no command entered\n",
			program_name, line_number);
		return (1);
	}
	if (_strcmp(args[0], "exit") == 0)
	{
		exit_shell();
	}
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
		if (WIFEXITED(status))
		{
			child_exit_status = WEXITSTATUS(status);
		}
	}

	return (0);
}
