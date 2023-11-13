#include "shell.h"
/**
 * _eputs - prints an input string
 * @str: the string to be printed
 *
 * Return: nothing
 */
void _eputs(char *str)
{
	int b = 0;

	if (!str)
		return;
	while (str[b] != '\0')
	{
		_eputchar(str[b]);
		b++;
	}
}
/**
 * _eputchar - writes the character c to stderr
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately
 */
int _eputchar(char c)
{
	static int a;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || a >= WRITE_BUF_SIZE)
	{
		write(2, buf, a);
		a = 0;
	}
	if (c != BUF_FLUSH)
		buf[a++] = c;
	return (1);
}
/**
 * _putfd - writes the character c to given fd
 * @c: The character to print
 * @fd: The filedescriptor to write to
 *
 * Return: ON success 1.
 * On error, -1 is returned, and errno is set appropriately
 */
int _putfd(char c, int fd)
{
	static int y;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || y >= WRITE_BUF_SIZE)
	{
		write(fd, buf, y);
	}
	if (c != BUF_FLUSH)
		buf[y++] = c;
	return (1);
}
/**
 * _putsfd - prints an input string
 * @str: the string to be printed
 * @fd: the filedescriptor to write to
 *
 * Return- the number of chars put
 */
int _putsfd(char *str, int fd)
{
	int y = 0;

	if (!str)
		return (0);
	while (*str)
	{
		y += _putfd(*str++, fd);
	}
	return (y);
}
