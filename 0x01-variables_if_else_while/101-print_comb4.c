#include <stdio.h>

/**
 * main - Entry point
 *
 * Description:  prints all possible combinations of,
 *		two numbers.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int num1, num2, num3;

	for (num1 = 0; num1 <= 7; num1++)
	{
		for (num2 = num1 + 1; num2 <= 8; num2++)
		{
			for (num3 = num2 + 1; num2 <= 9; num3++)
				putchar(num1 + '0');
				putchar(num2 + '0');
				putchar(num3 + '0');
		}
		putchar(',');
		putchar(' ');
	}
	putchar('\n');
	return (0);
}
