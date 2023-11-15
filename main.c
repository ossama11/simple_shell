#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

#define MAX_INPUT_SIZE 1024

int main(void)
{
	char input[MAX_INPUT_SIZE];

	char *args[10];

	int status;

	int i = 0;

	char *token;

	do {
		printf("$ ");
		fgets(input, sizeof(input), stdin);
		input[strcspn(input, "\n")] = '\0';

		token = strtok(input, " ");
		while (token != NULL && i < 10)
		{
			args[i++] = token;
			token = strtok(NULL, " ");
		}
		args[i] = NULL;

		status = execute(args);

	} while (status);

	return (0);
}
