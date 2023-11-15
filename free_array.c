#include "main.h"

/**
* free_array - Frees a 2D array
* @array: The array to free
*/
void free_array(char **array)
{
	int i;

	for (i = 0; array[i] != NULL; i++)
	{
		free(array[i]);
	}

	free(array);
}
