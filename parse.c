#include "main.h"

/**
* parse_command - parse command
* @cmd: string to parse
* @argv: array.
*/
void parse_command(char *cmd, char **argv)
{
	char *token;

	int i = 0;

	if (cmd == NULL || argv == NULL)
		return;

	token = strtok(cmd, " \n\t\r");
	while (token != NULL && i < MAX_NUM_ARGS - 1)
	{
		argv[i] = token;
		i++;

		token = strtok(NULL, " \n\t\r");
	}

	argv[i] = NULL;
}
