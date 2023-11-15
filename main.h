#ifndef MAIN_H
#define MAIN_H



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>


#define MAX_CMD_LEN 100
#define MAX_NUM_ARGS 10
#define PROMPT "$ "

extern char **environ;



int main(void);
void parse_command(char *cmd, char **argv);
int checker(void);
char *find_command(char *cmd);
void print_env(void);
int run_command(char **argv, char *full_path);



void handle_env(char **argv);
char *get_full_path(char **argv);
void handle_exit(char **argv);

#endif
