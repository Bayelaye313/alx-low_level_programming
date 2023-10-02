#include "main.h"
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

void print_error(int fd)
void close_file(int fd);

/**
 * create_buffer - Allocates memory for a buffer.
 * @file: The name of the file buffer is storing chars for.
 *
 * Return: A pointer to the allocated buffer.
 */
void print_error(int fd)
{
	dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
	exit(100);
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

/**
 * main - Copies the contents of a file to another file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: If the argument count is incorrect - exit code 97.
 * If file_from does not exist or cannot be read - exit code 98.
 * If file_to cannot be created or written to - exit code 99.
 * If file_to or file_from cannot be closed - exit code 100.
 */
int main(int argc, char *argv[])
{
	int src, dest, r, w;
	char buffer[BUFFER_SIZE];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	src = open(argv[1], O_RDONLY);
	if (argv[1] == NULL || src < 0)
    	{
		dprintf(STDERR_FILENO,
			"Error: Can't read from file %s\n", argv[1]);
        	free(buffer);
        	exit(98);
	}
	dest = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	if (dest < 0)
    	{
        	dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
        	close_file(src);
        	free(buffer);
        	exit(99);
    	}

	r = read(src, buffer, 1024);
	w = write(dest, buffer, r);

	while(r > 0) {
        if (r != w)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", argv[2]);
			free(buffer);
			close_file(dest);
			close_file(src);
			exit(99);
		}
	}
		if (r < 0)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", argv[1]);
			free(buffer);
			exit(98);
		}


        if (close_file(src) < 0)
            print_error(src);
        if (close_file(dest) < 0)
            print_error(dest);
	return (0);
}
