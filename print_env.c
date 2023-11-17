#include "main.h"

/**
* get_environ - get environment
*
* Return: pointer the environment
*/
char **get_environ(void)
{
	return (environ);
}

/**
* print_env - print current environment
*
*/
void print_env(void)
{
	char **environ = get_environ();

	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		write(STDOUT_FILENO, environ[i], my_strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
}

/**
* my_unsetenv - Unset an environment variable.
* @name: name of the variable to unset
*
* Return: 0 on success.
*/
int my_unsetenv(char *name)
{
	char **env;
	char **dst;

	if (name == NULL)
		return (-1);

	env = environ;

	dst = env;

	while (*env != NULL)
	{
		if (my_strcmp(name, *env) != 0)
		{
			*dst = *env;
			dst++;
		}

		env++;
	}
	*dst = NULL;

	return (0);
}
