#include "main.h"

/**
* my_memcpy - Copy memory area from source to destination
* @dest: Pointer to the destination memory area
* @src: Pointer to the source memory area
* @n: Number of bytes to copy
*
* Return: Pointer to the destination memory area
*/
void *my_memcpy(void *dest, const void *src, size_t n)
{
	char *cdest = (char *)dest;

	const char *csrc = (const char *)src;

	size_t i;

	for (i = 0; i < n; i++)
		cdest[i] = csrc[i];

	return (dest);
}
