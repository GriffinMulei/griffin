#include "shell.h"

/**
 * main - main entry point of the shell
 * @argc: No. of args passed in the program
 * @argv: arr of strings
 *
 * Return: 0 Success, non zero for failure
 */

int main(int argc, char **argv)

{
	char *user_input;
	int i;

	if (argc > 1)
	{
		for (i = 1; i < argc; i++)
		{
			printf("Arg %d: %s\n", i, argv[i]);
		}
	}

	while (1)
	{
		print_prompt();
		user_input = read_input();

		if (user_input == NULL)
		{
			putchar('\n');
			break;
		}
		execute_command(user_input);
		free(user_input);
	}
	return (EXIT_SUCCESS);
}
