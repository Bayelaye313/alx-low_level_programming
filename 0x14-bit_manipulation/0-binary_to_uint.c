#include "main.h"

/**
 * binary_to_uint - converts a binary number to unsigned int
 * @b: string containing the binary number
 *
 * Return: the converted number
 */
unsigned int binary_to_uint(const char *b)
{
	int bit_position = 0;
	unsigned int result = 0;

	if (!b)
		return (0);

	while (b[bit_position] != '\0')
		bit_position++;

	for (int i = bit_position - 1; i >= 0; i--)
	{
		if (b[i] == '1')
			result |= (1 << (bit_position - 1 - i));
		else if (b[i] != '0')
			return (0);
	}

	return (result);
}
