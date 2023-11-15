#include "main.h"


/**
* checker - checks if the shell is in interactive mode
*
* Return: 1 if in interactive mode, 0 otherwise
*/
int checker(void)
{
	return (isatty(STDIN_FILENO));
}

