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
* Return: void
*/
void print_env(void)
{
	char **environ = get_environ();

	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		puts(environ[i]);
	}
}
