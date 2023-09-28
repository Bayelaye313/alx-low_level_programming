#include "main.h"

/**
 * print_binary - prints the binary equivalent of a decimal number
 * @n: number to print in binary
 */
void print_binary(unsigned long int n)
{
	unsigned long int current_bit;
	int bit_index, bit_count = 0;

	for (bit_index = 63; bit_index >= 0; bit_index--)
	{
		bit_count = num >> bit_index;

		if (bit_count & 1)
		{
			_putchar('1');
			bit_count++;
		}
		else if (bit_count)
			_putchar('0');
	}
	if (bit_count)
		_putchar('0');
}
