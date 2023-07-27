#include "main.h"
/**
 * _printf - produces output according to a format.
 * @format: is a character string.
 * The format string is composed of
 * zero or more directives.
 * @...: the characters.
 * Return: no of the printed characters.
 */
int _printf(const char *format, ...)
{
	int i, x, counter, j, num_args = strlen(format);
	va_list args;
	char c, ch;

	va_start(args, format);
	if (format == NULL)
		return (-1);
	for (i = 0; i < num_args; i++)
	{
		if (format[i] == '%' && (format[i + 1] == 'd' || format[i + 1] == 'i'))
		{
			x = va_arg(args, int);
			write(1, &x, 1);
			counter++;
		}
		else if (format[i] == '%' && (format[i + 1] == 'c' || format[i + 1] == 's'))
		{
			c = (char)va_arg(args, int);
			write(1, &c, 1);
			counter++;
		}
		else if (format[i] == '%' && format[i + 1] == '%')
		{
			for (j = i + 1; j < num_args; j++)
			{
				ch = format[x];
				write(1, &ch, 1);
				counter++;
			}
		}
	}
	va_end(args);
	return (counter);
}
