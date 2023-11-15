#include "main.h"



void handle_exit(char **argv)
{

	if (my_strcmp(argv[0], "exit") == 0)
		exit(EXIT_SUCCESS);
}




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

void handle_env(char **argv)
{

	if (my_strcmp(argv[0], "env") == 0)
	{
		print_env();
	}
}

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
