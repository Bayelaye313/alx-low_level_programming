#include "main.h"
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void print_error(int fd);
void close_file(int fd);

/**
 * print_error - Print file close error.
 * @fd: The file descriptor.
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
        print_error(fd);
    }
}

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
        dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
        exit(98);
    }

    dest = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
    if (dest < 0)
    {
        dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
        close_file(src);
        exit(99);
    }

    do
    {
        r = read(src, buffer, BUFFER_SIZE);
        if (r == -1)
        {
            dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
            close_file(src);
            close_file(dest);
            exit(98);
        }

        w = write(dest, buffer, r);
        if (w == -1 || w != r)
        {
            dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
            close_file(src);
            close_file(dest);
            exit(99);
        }

    } while (r > 0);

    close_file(src);
    close_file(dest);

    return 0;
}
