#include "main.h"
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

/**
 * create_buffer - Allocates memory for a buffer.
 * @file: The name of the file buffer is storing chars for.
 *
 * Return: A pointer to the allocated buffer.
 */
char *create_buffer(char *file)
{
	char *buffer = malloc(BUFFER_SIZE);
	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO,
			"Error: Unable to allocate buffer memory for %s\n", file);
		exit(99);
	}
	return (buffer);
}

/**
 * close_file - Closes a file descriptor.
 * @fd: The file descriptor to be closed.
 */
void close_file(int fd)
{
	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

int main(int argc, char *argv[])
{
	int src, dest, r, w;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	buffer = create_buffer(argv[1]);
	src = open(argv[1], O_RDONLY);
	dest = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	if (src == -1 || dest == -1)
	{
		dprintf(STDERR_FILENO, "Error: Unable to open files\n");
		free(buffer);
		exit(98);
	}

	r = read(src, buffer, BUFFER_SIZE);

	while (r > 0)
	{
		w = write(dest, buffer, r);
		if (w == -1)
		{
			dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", argv[2]);
			free(buffer);
			exit(99);
		}

		r = read(src, buffer, BUFFER_SIZE);
	}

	free(buffer);
	close_file(src);
	close_file(dest);

	return (0);
}
