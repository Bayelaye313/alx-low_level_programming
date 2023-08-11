#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: prints the lowercase alphabet in reverse
 *		using the putchar function.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char lowercase;

	for (lowercase = 'z'; lowercase <= 'a'; lowercase--)
	{
		putchar(lowercase);
	}
	putchar('\n');
	return (0);
}
