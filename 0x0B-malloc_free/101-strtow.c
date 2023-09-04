#include <stdlib.h>
#include "main.h"

/**
 * countWords - Helper function to count the number of words in a string
 * @s: String to evaluate
 *
 * Return: Number of words
 */
int countWords(char *s)
{
	int flag, charIndex, wordCount;

	flag = 0;
	wordCount = 0;

	for (charIndex = 0; s[charIndex] != '\0'; charIndex++)
	{
		if (s[charIndex] == ' ')
			flag = 0;
		else if (flag == 0)
		{
			flag = 1;
			wordCount++;
		}
	}

	return (wordCount);
}

/**
 * strtow - Splits a string into words
 * @str: String to split
 *
 * Return: Pointer to an array of strings (Success) or NULL (Error)
 */
char **strtow(char *str)
{
	char **wordMatrix, *tempWord;
	int i, wordIndex = 0, strLength = 0, wordCount, charIndex = 0, start, end;

	while (str[strLength])
		strLength++;
	wordCount = countWords(str);

	if (wordCount == 0)
		return (NULL);

	wordMatrix = (char **)malloc(sizeof(char *) * (wordCount + 1));

	if (wordMatrix == NULL)
		return (NULL);
	for (i = 0; i <= strLength; i++)
	{
		if (str[i] == ' ' || str[i] == '\0')
		{
			if (charIndex)
			{
				end = i;
				tempWord = (char *)malloc(sizeof(char) * (charIndex + 1));

				if (tempWord == NULL)
					return (NULL);
				while (start < end)
					*tempWord++ = str[start++];
				*tempWord = '\0';
				wordMatrix[wordIndex] = tempWord - charIndex;
				wordIndex++;
				charIndex = 0;
			}
		}
		else if (charIndex++ == 0)
			start = i;
	}
	wordMatrix[wordIndex] = NULL;
	return (wordMatrix);
}
