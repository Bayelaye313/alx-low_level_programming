#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: prints all the numbers of base 16,
 *		in lowercase.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char lowercase;

	for (lowercase = 0; lowercase <= 9; lowercase++)
	{
		putchar(lowercase);
	}
	for (lowercase = 'a'; lowercase <= 'f'; lowercase++)
	{
		putchar(lowercase);
	}
	putchar('\n');
	return (0);
}
