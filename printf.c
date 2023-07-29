#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "main.h"
/**
 * _printf - prints numbers & new line at the end
 * @format: string for  conversion specifiers
 * Return: the number of characters printed or 0
 */
int _printf(const char *format, ...)
{
	int i, len_str = 0;
	va_list args;

	va_start(args, format);
	if (format == NULL)
	{
		va_end(args);
		return (0);
	}
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
			{
				len_str += _putchar(va_arg(args, int));
			}
			else if (format[i] == 's')
			{
				len_str += print_string(va_arg(args, char*));
			}
			else if (format[i] == '%')
			{
				len_str += write(1, &format[i], 1);
			}
			else if (format[i] == 'd' || format[i] == 'i')
			{
				print_int_c(va_arg(args, int));
			}
			else
			{
				
				len_str += write(1, &format[i - 1], 1);
				len_str += write(1, &format[i], 1);
			}
		}
		else if (format[i] == '\\' && format[i + 1] == '\n')
			_putchar(10);
		else
		{
			len_str += write(1, &format[i], 1);
		}
	}
	va_end(args);
	return (len_str);
}
