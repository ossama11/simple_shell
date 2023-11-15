#include "main.h"


/**
* checker - checks mode
*
* Return: 1 in inter mode, 0 other
*/
int checker(void)
{
	return (isatty(STDIN_FILENO));
}

