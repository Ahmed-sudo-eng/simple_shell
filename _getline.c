#include "main.h"

/**
 * _getline - reads an entire line from stream, storing the address of the
 * buffer containing the text into *lineptr, The buffer is null-terminated
 * and includes the newline character, if one was found
 * @lineptr: a null-terminated buffer that _gertline will use to store the text
 * @n: the size of the buffer
 * @stream: a pointer to an open file that _getline will read
 *
 * Return: On Success, getline return the number of characters read, including
 * the delimiter charcter, but not including the terminating null byte ('\0')
 * and return -1 on failure to read a line (including end-of-file condition).
 */
int _getline(char **lineptr, __attribute__((unused))size_t *n, FILE *stream)
{
	int c;
	int i = 0;
	char *buf = malloc(1024);


	while (c != 10)
	{
		c = getc(stream);
		if (c == EOF)
			return (-1);
		buf[i] = c;
		i++;
	}
	*lineptr = buf;

	return (i);
}
