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

/** struct info_s - contains info needed for shell operations
 * @buffer: pointer to input buffer
 * @argv: pointer to arr of args passed to the shell
 * @envp:
 * @status:
 * @err_num:
*/

typedef struct info_s
{
	char *buffer;
	char **argv;
	char **envp;
	int status;
	int err_num;
} info_t;

/*maximum file path length*/
#define FILE_PATH_MAX_LEN 1024

/*mamximum no. of args to be passed to a cmd*/
#define MAX_COMMAND_ARGS 128

/*function prototypes*/
void print_prompt(void);
char *read_input(void);
void execute_command(char *command_with_args);
void execute(char **args);
char **tokenize_command(char *command_with_args, char *delimeter, int *num_args);
void handle_error(void);

/*env prototypes*/
char *_find_command_path(char *cmd);
char *_getenv(const char *env_var);
char *_which(char *cmd);
char *_strdup(char *str);
char **_split(char *str, char *delim);

/*function prototypes for string functions*/
int _putchar(char ch);
void _put(char *s);
int _strlen(const char *str);
char *_strncopy(char *dest, const char *src, size_t num_chars);
int _strcmp(char *s1, char *s2);

/*prototype to exit shell*/
void exit_shell(void);

/**prototype to printf current env*/
int print_env(void);

/*arr of strings for env variables*/
extern char **environ;

#endif /*SHELL_H*/
