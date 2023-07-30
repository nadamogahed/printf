#include "main.h"
/**
 * print_int_c - prints an integer
 * @x: input integer
 * Return: void
 */
int print_int_c(int x)
{
	int i = 0;
	if (x == INT_MIN)
	{
		i += _putchar('-');
		i += _putchar('2');
		x %= 1000000000;
		x = -x;
	}
	else  if (x < 0)
	{
		i += _putchar('-');
		x = -x;
	}
	if (x / 10 > 0)
	{
		i += print_int_c(x / 10);
	}
	i += _putchar(x % 10 + '0');
	return(i);
}
