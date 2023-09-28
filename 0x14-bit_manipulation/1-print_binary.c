#include "main.h"

/**
 * print_binary - prints the binary equivalent of a decimal number
 * @n: number to print in binary
 */
void print_binary(unsigned long int n)
{
        unsigned long int current_bit;
        int i;

        /* Gérez le cas où n est 0 */
        if (n == 0)
        {
                _putchar('0');
                return;
        }

        for (i = 63; i >= 0; i--)
        {
                current_bit = n >> i;

                /* Vérifiez si le bit actuel est 1 ou 0 */
                if (current_bit & 1)
                {
                        _putchar('1');
                }
                else
                {
                        _putchar('0');
                }
        }
}
