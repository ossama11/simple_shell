#include "main.h"

/**
* handle_exit - Handles the "exit" command
* @argv: array of command arguments
*
*/
void handle_exit(char **argv)
{
	if (my_strcmp(argv[0], "exit") == 0)
		exit(EXIT_SUCCESS);
}

/**
* get_full_path - Retrieves full path of command
* @argv: The array of command line arguments
*
* Return: full path of the command, or NULL if not found.
*/
char *get_full_path(char **argv)
{
	char *full_path = find_command(argv[0]);

	if (full_path == NULL)
	{
		write(STDERR_FILENO, argv[0], my_strlen(argv[0]));
		write(STDERR_FILENO, ": command not found\n", 20);
		return (NULL);
	}

	return (full_path);
}

/**
* handle_env - Handles "env" command
* @argv: The array of command line arguments
*
*/
void handle_env(char **argv)
{
	if (my_strcmp(argv[0], "env") == 0)
	{
		print_env();
	}
}

/**
* my_getenv - Retrieves value of environment variable
* @name: The name of the environment variable
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
