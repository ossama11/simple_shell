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
