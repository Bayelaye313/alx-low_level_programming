#include "main.h"
#include <stdlib.h>

/**
 * argstostr - Concatenate program arguments into a single string
 * @ac: The number of arguments
 * @av: The array of argument strings
 * Return: A pointer to the concatenated string or NULL on failure
 */
char *argstostr(int ac, char **av)
{
    int i, j, total_length = 0;
    char *result;

    if (ac == 0 || av == NULL)
        return (NULL);

    for (i = 0; i < ac; i++)
    {
        for (j = 0; av[i][j]; j++)
        {
            total_length++;
        }
        total_length++;
    }

    result = malloc(sizeof(char) * (total_length + 1));
    if (result == NULL)
        return (NULL);

    int k = 0;
    for (i = 0; i < ac; i++)
    {
        for (j = 0; av[i][j]; j++)
        {
            result[k++] = av[i][j];
        }
        result[k++] = '\n';
    }
    result[k] = '\0';

    return (result);
}
