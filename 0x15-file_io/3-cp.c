#include "main.h"

#define BUFFER_SIZE 1024

char *allocate_buffer(void);
void close_file_descriptor(int fd);

/**
 * allocate_buffer - Allocates memory for a buffer.
 *
 * Return: A pointer to the allocated buffer.
 */
char *allocate_buffer(void)
{
	char *buffer = malloc(BUFFER_SIZE);

	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Unable to allocate buffer memory\n");
		exit(EXIT_FAILURE);
	}
	return (buffer);
}

/**
 * close_file_descriptor - Closes a file descriptor.
 *
 * @fd: The file descriptor to be closed.
 */
void close_file_descriptor(int fd)
{
	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Unable to close file descriptor %d\n", fd);
		exit(EXIT_FAILURE);
	}
}
int main(int argc, char *argv[])
{
	int src_fd, dest_fd, t, w;
	char *buffer;

/** Check if the correct number of arguments is provided */
	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(EXIT_FAILURE);
	}
	buffer = allocate_buffer();

/** Open source file for reading */
	src_fd = open(argv[1], O_RDONLY);
	if (src_fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		free(buffer);
		exit(EXIT_FAILURE);
	}
/** Open destination file for writing (truncate if it already exists) */
	dest_fd = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	if (dest_fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		free(buffer);
		close_file_descriptor(src_fd);
		exit(EXIT_FAILURE);
	}

/** Copy data from source to destination */
	do
	{
		t = read(src_fd, buffer, BUFFER_SIZE);
		if (t == -1)
		{
			dprintf(STDERR_FILENO, "Error: Unable to read from file %s\n", argv[1]);
			free(buffer);
			close_file_descriptor(src_fd);
			close_file_descriptor(dest_fd);
			exit(EXIT_FAILURE);
		}
		w = write(dest_fd, buffer, t);
		if (w == -1)
		{
			dprintf(STDERR_FILENO, "Error: Unable to write to %s\n", argv[2]);
			free(buffer);
			close_file_descriptor(src_fd);
			close_file_descriptor(dest_fd);
			exit(EXIT_FAILURE);
		}
	} while (t > 0);
	free(buffer);
/** Close file descriptors */
	close_file_descriptor(src_fd);
	close_file_descriptor(dest_fd);
	return EXIT_SUCCESS;
}
