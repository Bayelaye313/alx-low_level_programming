#include "main.h"

#define BUF_SIZE 1024

/**
 * main - Copies the content of a file to another file.
 * @argc: Argument count.
 * @argv: Argument vector.
 * Return: 0 on success, or an error code on failure.
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to, rd, wr;
	char buffer[BUF_SIZE];

	if (argc != 3)
	{
		dprintf(2, "Usage: cp file_from file_to\n");
		exit(97);
	}
	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
	{
		dprintf(2, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}

    fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
    if (fd_to == -1)
    {
        dprintf(2, "Error: Can't write to %s\n", argv[2]);
        exit(99);
    }

    do
    {
        rd = read(fd_from, buffer, BUF_SIZE);
        if (rd == -1)
        {
            dprintf(2, "Error: Can't read from file %s\n", argv[1]);
            exit(98);
        }

        wr = write(fd_to, buffer, rd);
        if (wr == -1)
        {
            dprintf(2, "Error: Can't write to %s\n", argv[2]);
            exit(99);
        }
    } while (rd == BUF_SIZE);

    if (close(fd_from) == -1 || close(fd_to) == -1)
    {
        dprintf(2, "Error: Can't close fd %d\n", (fd_from == -1) ? fd_to : fd_from);
        exit(100);
    }

    return (0);
}
