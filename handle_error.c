#include "shell.h"

/**
 * handle_error - handles errors
 *
 */
void handle_error(void)
{
	perror("Error: ");
	exit(EXIT_FAILURE);
}
