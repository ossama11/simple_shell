#include "main.h"

/**
* parse_command - parses the command into program and arguments
*
* @cmd: the command to parse
* @argv: the array to store the program and arguments
*/
void parse_command(char *cmd, char **argv)
{
	char *token;

	int i = 0;

	token = my_strtok(cmd, " ");
	while (token != NULL && i < MAX_NUM_ARGS - 1)
	{
		argv[i] = token;
		i++;
		token = my_strtok(NULL, " ");
	}
	argv[i] = NULL;
}
