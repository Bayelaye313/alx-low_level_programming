#include <stdlib.h>
#include "main.h"

/**
 * _memset - Fills memory with a constant byte.
 * @dest: Pointer to the memory area to be filled.
 * @byte: The constant byte to be written.
 * @n: The number of bytes to be written.
 *
 * Return: Pointer to the filled memory area @dest.
 */
char *_memset(char *dest, char byte, unsigned int n)
{
    unsigned int i;

    for (i = 0; i < n; i++)
    {
	    dest[i] = byte;
    }
    return (dest);
}

/**
 * _calloc - Allocates memory for an array.
 * @nmemb: Number of elements in the array.
 * @size: Size of each element.
 *
 * Return: Pointer to allocated memory.
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *ptr;

	if (nmemb == 0 || size == 0)
		return (NULL);
	ptr = malloc(size * nmemb);
	if (ptr == NULL)
		return (NULL);
	_memset(ptr, 0, nmemb * size);
	return (ptr);
}
