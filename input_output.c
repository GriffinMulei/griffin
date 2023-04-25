#include "shell.h"

#define USER_PROMPT "#cisfun$ "
/**
 * print_prompt - Prints the shell prompt
 *
 */

void print_prompt(void)
{
	printf("%s", USER_PROMPT);
}

/**
 * read_input - read a line of input from user
 *
 * Return: pointer to a string containing user_input
 *         NULL if there is an error
 */
char *read_input(void)
{
	char *user_input = NULL;
	size_t buffer_size = 0;
	ssize_t input_length;

	input_length = getline(&user_input, &buffer_size, stdin);

	if (input_length == -1)
	{
		handle_error();
		return (NULL);
	}

	if (user_input[input_length - 1] == '\n')
		user_input[input_length - 1] = '\0';

	return (user_input);
}
