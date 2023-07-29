#include "main.h"
/**
 * print_int_c - prints an integer
 * @x: input integer
 * Return: void
 */
void print_int_c(int x)
{
	if (x < 0)
	{
		_putchar('-');
		x = -x;
	}
	if (x / 10 > 0)
	{
		_printf("%d", x / 10);
	}
	_putchar(x % 10 + '0');
}
