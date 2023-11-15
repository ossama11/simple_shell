#include "main.h"


/**
* _strcmp - Compares two strings
* @s1: First string
* @s2: Second string
*
* Return: Difference between the first non-matching characters
*/
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] && s2[i]; i++)
	{
		if (s1[i] != s2[i])
			break;
	}

	return (s1[i] - s2[i]);
}

/**
* _strlen - Returns the length of a string
* @s: String
*
* Return: Length of the string
*/
int _strlen(char *s)
{
	int i;

	for (i = 0; s[i]; i++)
		;

	return (i);
}
