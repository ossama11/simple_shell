#include "main.h"

/**
* parse_input - Parses user input
* @input: User input
*
* Return: Array of arguments
*/
char **parse_input(char *input)
{
	int i = 0;

	char **args = malloc(sizeof(char *) * 64);

	char *token;

	if (!args)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}

	token = strtok(input, " \t\r\n\a");
	while (token != NULL)
	{
		args[i] = token;
		i++;

		token = strtok(NULL, " \t\r\n\a");
	}
	args[i] = NULL;

	return (args);
}
