#include "main.h"

/**
* run_command - execute command
* @argv: array.
* @full_path: full path
*
* Return: 0 on success
*/
int run_command(char **argv, char *full_path)
{
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror(argv[0]);
		return (1);
	}
	if (child_pid == 0)
	{
		if (execve(full_path, argv, NULL) == -1)
		{
			perror(argv[0]);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);

	}

	return (0);
}
