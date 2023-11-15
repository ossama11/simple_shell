#include "main.h"

/**
* get_environ - gets the environment
*
* Return: pointer to the environment
*/
char **get_environ(void)
{
	return (environ);
}

/**
* print_env - prints the current environment
*
* Return: void
*/
void print_env(void)
{
	char **environ = get_environ();

	int i;

	for (i = 0; environ[i] != NULL; i++)
		printf("%s\n", environ[i]);
}
