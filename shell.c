#include "shell.h"

/**
 * print_args - prints command line args
 * @argc: no. of args
 * @argv: arr of strings containing args
 *
*/
void print_args(int argc, char **argv)
{
	int i;

	for (i = 1; i < argc; i++)
	{
		printf("Arg %d: %s\n", i, argv[i]);
	}
}

/**
 * shell_loop - main loop of the shell
 * @program_name: name of program
 *
*/
void shell_loop(char *program_name)
{
	char *user_input = NULL;
	size_t input_size = 0;
	ssize_t num_chars_read;
	int line_number = 1;
	int interactive = isatty(STDIN_FILENO);

	while (1)
	{
		if (interactive)
		{
			print_prompt();
		}

		num_chars_read = getline(&user_input, &input_size, stdin);

		if (num_chars_read == -1)
		{
			if (errno == EINTR)
			{
				continue;
			}
			putchar('\n');
			break;
		}
		user_input[strcspn(user_input, "\n")] = '\0';

		if (_strcmp(user_input, "exit") == 0)
		{
			free(user_input);
			exit_shell();
			exit(EXIT_SUCCESS);
		}
		else if (_strcmp(user_input, "printenv") == 0)
		{
			print_env("PATH");
		}
		execute_command(user_input, program_name, line_number);
	}
	free(user_input);
}

/**
 * main - main entry point of the shell
 * @argc: No. of args passed
 * @argv: Arr of strings
 *
 * Return: 0 success
 *         else fail
*/
int main(int argc, char **argv)
{
	if (argc > 1)
	{
		print_args(argc, argv);
	}
	shell_loop(argv[0]);

	return (EXIT_SUCCESS);
}
