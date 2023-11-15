#include "main.h"

/**
* find_command - finds the command in the PATH
*
* @cmd: the command to find
*
* Return: string containing full path.
*/
char *find_command(char *cmd)
{
	char *PATH, *path_copy, *dir, *full_path;

	if (cmd[0] == '/')
		return (my_strdup(cmd));

	PATH = my_getenv("PATH");
	if (PATH == NULL)
		return (NULL);

	path_copy = my_strdup(PATH);
	dir = my_strtok(path_copy, ":");

	while (dir != NULL)
	{
		full_path = malloc(MAX_CMD_LEN);
		if (full_path == NULL)
		{
			free(path_copy);
			return (NULL);
		}

		my_strncpy(full_path, dir, MAX_CMD_LEN);
		my_strncat(full_path, "/", MAX_CMD_LEN - my_strlen(full_path) - 1);
		my_strncat(full_path, cmd, MAX_CMD_LEN - my_strlen(full_path) - 1);

		if (access(full_path, X_OK) == 0)
		{
			free(path_copy);
			return (full_path);
		}

		free(full_path);
		dir = my_strtok(NULL, ":");
	}

	free(path_copy);
	return (NULL);
}
