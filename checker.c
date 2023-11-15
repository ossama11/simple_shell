
#include "main.h"

/**
* checker - checks program running in interactive mode
*
* Return: 1 interactive mode, 0 otherwise
*/
int checker(void)
{
	return (isatty(STDIN_FILENO));
}
