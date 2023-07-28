#include <unistd.h>
/*
 * _putchar - prints a character
 * @c: a char
 * Return: an ascii value
 */
int _putchar(char c)
{
	return (write(STDOUT_FILENO, &c, 1));
}
