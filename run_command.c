#include "main.h"

/**
* run_command - executes a command
*
* @argv: the array containing the program and arguments
* @full_path: the full path of the program
*
* Return: 0 on success, 1 on error
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
		if (execve(full_path, argv, NULL) == -1)  /* Execute command */
			perror(argv[0]);
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(&status);  /* Wait for child process to finish */
	}

	return (0);
}
