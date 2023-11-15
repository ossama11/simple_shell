#include "main.h"
#include <stdbool.h>


/**
* my_is_numeric - Check.
* @str: string to check
*
* Return: true numeric, false otherwise
*/
bool my_is_numeric(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] < '0' || str[i] > '9')
		{
			return (false);
		}
	}
	return (true);
}

/**
* handle_exit - "exit" command
* @argv: array.
*
*/
void handle_exit(char **argv)
{
	if (my_strcmp(argv[0], "exit") == 0)
	{
		if (argv[1] != NULL)
		{
			int status;

			if (my_is_numeric(argv[1]))
			{
				status = my_atoi(argv[1]);
			}
			else
			{
				write(STDERR_FILENO, "Invalid exit status: ", 21);
				write(STDERR_FILENO, argv[1], my_strlen(argv[1]));
				write(STDERR_FILENO, "\n", 1);
				return;
			}
			exit(status % 256);
		}
		else
		{
			exit(EXIT_SUCCESS);
		}
	}
}

/**
* get_full_path - Retrieve path command
* @argv: array.
*
* Return: full path
*/
char *get_full_path(char **argv)
{
	char *full_path = find_command(argv[0]);

	if (full_path == NULL)
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
