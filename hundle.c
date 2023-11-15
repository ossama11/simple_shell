#include "main.h"

void handle_exit(char **argv)
{

	if (strcmp(argv[0], "exit") == 0)
		exit(EXIT_SUCCESS);
}

void handle_env(char **argv)
{

	if (strcmp(argv[0], "env") == 0)
	{
		print_env();
	}
}


char *get_full_path(char **argv)
{
	char *full_path = find_command(argv[0]);

	if (full_path == NULL)
	{
		fprintf(stderr, "%s: command not found\n", argv[0]);
		return (NULL);
	}
	return (full_path);
}
