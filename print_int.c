#include "main.h"
/**
 * print_int_c - prints an integer
 * @x: input integer
 * Return: void
 */
int print_int_c(int x)
{
	int i = 0;

	if (x < 0)
	{
		i += _putchar('-');
		x = -x;
	}
	if (x / 10 > 0)
	{
		i += _printf("%d", x / 10);
	}
	i += _putchar(x % 10 + '0');
	return (i);
}
