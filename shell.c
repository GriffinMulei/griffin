#include "shell.h"

#define USER_PROMPT "$ "

/**
 *  main - main entry point of the shell
 *
 * Return: 0 Success, non zero for failure
 */

int main(void)

{
	char *user_input;
	size_t buffer_size = 0;
	ssize_t input_length;
	pid_t pid;

	while (1)
	{
		printf("%s", USER_PROMPT);
		input_length = getline(&user_input, &buffer_size, stdin);

		if (input_length == -1)
		{
			putchar('\n');
			break;
		}
		if (user_input[input_length - 1] == '\n')
			user_input[input_length - 1] = '\0';

		pid = fork();
		if (pid == -1)
		{
			perror("Error: failed to create child process");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			if (execl(user_input, user_input, (char *)NULL) == -1)
			{
				perror("Error: failed to execute command");
				exit(EXIT_FAILURE);
			}
		}
		else
			wait(NULL);
	}
	free(user_input);
	exit(EXIT_SUCCESS);
}
