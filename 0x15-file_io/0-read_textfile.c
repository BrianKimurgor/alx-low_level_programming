#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
/**
 * read_textfile - read text file and print th POSIX standard output.
 * @filename: text file being read
 * @letters: number of letters to be read
 * Return: actual number of bytes read and printed
 *   0 when the function fails or is null
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t read_count, write_count;
	char *buffer;

	if(filename == NULL)
		return (0);

	fd = open(filename, O_RDONLY);
	 if (fd == -1)
        return (0);

    buffer = malloc(sizeof(char) * letters);
    if (buffer == NULL)
        return (0);

    read_count = read(fd, buffer, letters);
    if (read_count == -1)
        return (0);

    write_count = write(STDOUT_FILENO, buffer, read_count);
    if (write_count == -1 || write_count != read_count)
        return (0);

    close(fd);
    free(buffer);

    return (write_count);
}
