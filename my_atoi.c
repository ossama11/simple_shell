#include "main.h"

/**
* my_atoi - Convert string to integer
* @str: string to convert
*
* Return: converted integer value
*/

int my_atoi(char *str)
{
	int result = 0, sign = 1, i = 0;

	if (str == NULL || str[0] == '\0')
		return (0);

	if (str[0] == '-')
	{
		sign = -1;
		i++;
	}

	for (; str[i] != '\0'; i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			result = result * 10 + (str[i] - '0');
		}
		else
		{
			break;
		}
	}

	result *= sign;

	if (str[i] != '\0')
	{
		return (0);
	}

	return (result);
}
