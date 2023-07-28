#include <stdarg.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include "main.h"
/**
 * _printf - prints numbers & new line at the end
 * @format: string for  conversion specifiers
 * Return: the number of characters printed or 0
 */
int _printf(const char *format, ...)
{
	int count = 0, i = 0, len, value;
	char buffer[12];
	va_list args;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					count += _putchar(va_arg(args, int));
					break;
				case 's':
					len = strlen(va_arg(args, char *));
					count += write(STDOUT_FILENO, va_arg(args, char *), len);
					break;
				case 'd':
				case 'i':
					{
						value = va_arg(args, int);
						if (value < 0)
						{
							count += _putchar('-');
							value = -value;
						}
						do {
							buffer[i++] = (value % 10) + '0';
							value /= 10;
						} while (value != 0);
						while (i-- > 0)
							count += _putchar(buffer[i]);
						break;
					}
				case '%':
					count += _putchar('%');
					break;
				default:
					count += _putchar('%');
					count += _putchar(*format);
					break;
			}
		}
		else
			count += _putchar(*format);
		format++;
	}
	va_end(args);
	return (count);
}
