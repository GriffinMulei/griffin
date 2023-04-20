#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

/*function prototypes*/
void print_prompt(void);
char *read_input(void);
void execute_command(char *command_with_args);
void handle_error(void);

#endif /*SHELL_H*/

