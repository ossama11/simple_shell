#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "main.h"

int execute(char **args)
{

	pid_t pid;
	int status;

	pid = fork();
	if (pid == -1)
	{
		perror("fork error");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
		{
			perror("execvp error");
			exit(EXIT_FAILURE);
		}
	}
	else
	{

		wait(&status);
	}

	return (status);
}
