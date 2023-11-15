#include "main.h"

/**
* find_command - finds the command in the PATH
*
* @cmd: the command to find
*
* Return: a string containing the full path.
*/
char *find_command(char *cmd)
{
	char *PATH;

	char *path_copy;

	char *dir;

	char *full_path = malloc(MAX_CMD_LEN);

	/* If cmd is already an absolute path, just return it */
	if (cmd[0] == '/')
		return (strdup(cmd));

	PATH = getenv("PATH");
	path_copy = strdup(PATH);  /* Make a copy of PATH */
	dir = strtok(path_copy, ":");

	while (dir != NULL)
	{
		sprintf(full_path, "%s/%s", dir, cmd);
		if (access(full_path, X_OK) == 0)  /* Check if the command is executable */
		{
			free(path_copy);
			return (full_path);
		}
		dir = strtok(NULL, ":");
	}

	free(path_copy);
	free(full_path);
	return (NULL);
}

