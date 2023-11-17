#include "main.h"


/**
* handle_exit - Handles the "exit" command
* @argv: array of command arguments
* @cmd : free cmd
*/
void handle_exit(char *cmd, char **argv)
{
	if (my_strcmp(argv[0], "exit") == 0)
	{
		int status = 0;

		if (argv[1] != NULL)
			status = my_atoi(argv[1]);

		free(cmd);
		exit(status);
	}
}

/**
* get_full_path - Retrieve path command
* @argv: Array of arguments
*
* Return: Full path
*/
char *get_full_path(char **argv)
{
	char *full_path = find_command(argv[0]);

	if (!full_path && my_strcmp(argv[0], "env")
	&& my_strcmp(argv[0], "unsetenv")
	&& my_strcmp(argv[0], "setenv"))
	{
		write(STDERR_FILENO, argv[0], my_strlen(argv[0]));
		write(STDERR_FILENO, ": No such file or directory\n", 28);
		return (NULL);
	}

	return (full_path);
}

/**
* handle_env - "env" command
* @argv: array.
*
*/
void handle_env(char **argv)
{
	if (my_strcmp(argv[0], "env") == 0)
	{
		print_env();
	}
	else if (my_strcmp(argv[0], "unsetenv") == 0)
	{
		if (argv[1] == NULL)
		{
			write(STDERR_FILENO, "Invalid unsetenv command\n", 25);
		}
		else
		{
			if (my_unsetenv(argv[1]) == -1)
			{
				write(STDERR_FILENO, "Failed to unset environment variable\n", 37);
			}
		}
	}
	else if (my_strcmp(argv[0], "setenv") == 0)
	{
		if (argv[1] == NULL || argv[2] == NULL)
		{
			write(STDERR_FILENO, "Invalid setenv command\n", 23);
		}
		else
		{
			if (setenv(argv[1], argv[2], 1) == -1)
			{
				write(STDERR_FILENO, "Failed to set environment variable\n", 35);
			}
		}
	}
}
/**
* my_getenv - value environment variable
* @name: name.
*
* Return: value of the environment variable, or NULL if not found.
*/
char *my_getenv(const char *name)
{
	int i;

	size_t len = my_strlen(name);

	for (i = 0; environ[i] != NULL; i++)
	{
		if (my_strncmp(environ[i], name, len) == 0 && environ[i][len] == '=')
			return (&environ[i][len + 1]);
	}

	return (NULL);
}
