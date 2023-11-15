#ifndef MAIN_H
#define MAIN_H

/* Libraries */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>



/* Function prototypes */
int execute(char *args[]);
char **parse_input(char *input);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
void free_array(char **array);

#endif

