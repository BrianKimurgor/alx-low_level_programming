#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * create_file - Creates a file.
 * @filename: A pointer to the name of the file to create.
 * @text_content: A pointer to a string to write to the file.
 *
 * Return: If the function fails - -1.
 *         Otherwise - 1.
 */
int create_file(const char *filename, char *text_content)
{
	int fd;
	ssize_t len = 0;

	if (!filename)
		return (-1);
	if (text_content)
	{
		while (text_content[len])
		       	len++;
		 if (write(fd, text_content, len) == -1)
        {
            close(fd);
            return (-1);
        }
    }
	close(fd);
	return (1);
}
