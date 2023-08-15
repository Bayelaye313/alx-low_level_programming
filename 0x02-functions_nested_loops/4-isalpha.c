#include "main.h"

/**
 * _isalpha - check if char is a letter
 * @c: is the char to be checked
 * Return: 1 if char is letter, otherwise 0.
 */
int _islower(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}
