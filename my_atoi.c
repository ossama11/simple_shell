#include "main.h"

/**
 * my_atoi - Convert string to integer
 * @str: string to converte
 *
 * Return: converted integer
 */
int my_atoi(const char *str)
{
	int result = 0, sign = 1, i = 0;

	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;

	if (str[i] == '-' || str[i] == '+')
	{
		sign = (str[i] == '-') ? -1 : 1;
		i++;
	}

	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}

	return (result * sign);
}
