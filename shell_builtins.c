#include "shell.h"

/**
 * exit_shell - Exit the shell
 *
 * Return: void
 */

void exit_shell(void)
{
	if (child_exit_status != 0)
	{
		exit(child_exit_status);
	}
	exit(EXIT_SUCCESS);
}
