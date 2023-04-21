#include "shell.h"

/**
 * _find_command_path - func to search for a command in the PATH
 *                      env variable
 * @cmd: name of command to search for
 *
 * Return: pointer to the full path of te command
 *         NULL if not found
 */

char *_find_command_path(char *cmd)
{
	char *path = _getenv("PATH");
	char *path_copy = _strdup(path);
	char *dir_name = strtok(path_copy, ":");
	char full_path[FILE_PATH_MAX_LEN];
	struct stat file_info;

	while (dir_name != NULL)
	{

		snprintf(full_path, FILE_PATH_MAX_LEN, "%s/%s", dir_name, cmd);
		if (stat(full_path, &file_info) == 0 && (file_info.st_mode & S_IXUSR))
		{
			free(path_copy);
			return (_strdup(full_path));
		}
		dir_name = strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}

/**
 * _getenv - func to get environment var
 * @env_var: name of var to get
 *
 * Return: Value of var,
 *         Null if not found
*/

char *_getenv(const char *env_var)
{
	int env_i, env_j;

	for (env_i = 0; environ[env_i] != NULL; env_i++)
	{
		for (env_j = 0; env_var[env_j] != '\0'; env_j++)
			if (environ[env_i][env_j] != env_var[env_j])
				break;
		if (environ[env_i][env_j] == '=')
			return (&environ[env_i][env_j] + 1);
	}
	return (NULL);
}

/**
 * _strdup - duplicate a string
 * @str: String to duplicate
 *
 * Return: pointer to the duplicated string,
 *         NULL if mem allocation fails
*/

char *_strdup(char *str)
{
	char *duplicate_str;
	int i, str_len;

	while (str[str_len])
		str_len++;

	/**allocate mem*/
	duplicate_str = malloc(sizeof(char) * (str_len + 1));
	if (duplicate_str == NULL)
		return (NULL);

	for (i = 0; str[i]; i++)
		duplicate_str[i] = str[i];

	duplicate_str[str_len] = '\0';
	return (duplicate_str);
}

/**
 * _split - split a str into an arr of strings
 * @str: string to split
 * @delim: delimeter to split on
 *
 * Return: pointer to the arr of strings,
 *         NULL if mem allocation fails
*/

char **_split(char *str, char *delim)
{
	char **split_str;
	int i, elem_count = 0;
	char *token;

	str = _strdup(str);
	if (str == NULL)
		return (NULL);

	token = strtok(str, delim);
	while (token != NULL)
	{
		elem_count++;
		token = strtok(NULL, delim);
	}
	free(str);

	split_str = malloc(sizeof(char *) * (elem_count + 1));
	if (split_str == NULL)
		return (NULL);

	str = _strdup(str);
	if (str == NULL)
		return (NULL);

	token = strtok(str, delim);
	for (i = 0; token != NULL; i++)
	{
		split_str[i] = _strdup(token);
		token = strtok(NULL, delim);
	}
	split_str[i] = NULL;
	free(str);

	return (split_str);
}

/**
 * _which - finds full path of a command
 * @cmd: command to find the path for
 *
 * Return: string containing full path to the command,
 *         Else NULL
*/

char *_which(char *cmd)
{
	char *path;
	char *cmd_path;
	char **path_dirs;
	int i;
	struct stat file_info;

	if (cmd[0] == '/')
		return (_strdup(cmd));

	path = _getenv("PATH");
	if (path == NULL)
		return (NULL);

	path_dirs = _split(path, ":");
	if (path_dirs == NULL)
		return (NULL);

	cmd_path = malloc(sizeof(char) * (strlen(cmd) + strlen(path) + 2));
	if (cmd_path == NULL)
		return (NULL);

	for (i = 0; path_dirs[i] != NULL; i++)
	{
		strcpy(cmd_path, path_dirs[i]);
		strcat(cmd_path, "/");
		strcat(cmd_path, cmd);
		if (stat(cmd_path, &file_info) == 0 && file_info.st_mode & S_IXUSR)
			break;
	}
	free(path_dirs);
	if (path_dirs[i] == NULL)
		return (NULL);

	return (_strdup(cmd_path));
}
