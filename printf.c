#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include "main.h"
/**
 * _printf - prints numbers & new line at the end
 * @format: string for  conversion specifiers
 * Return: the number of characters printed or 0
 */
int _printf(const char *format, ...)
{
    int i, x, j;
    char *string;

    va_list args;
    va_start(args, format);

    for (i = 0; format[i] != '\0'; i++)
    {
/* if the next char in the placeholder string is a 'd', extract the next
 * argument as an int and print it out
 */
        if (format[i] == '\0' )
        {
            continue;
        }
        else if (format[i] == '%' && (format[i + 1] == 's' || format[i + 1] == 'c'))
        {
                string = va_arg(args, char *);
                for (j = 0; string[j] != '\0'; j++) {
                    _putchar(string[j]);
                }
                i++;
                return(i);
        }
/* if the next char in the placeholder string is a 'd' or 'i', extract the next
 * argument as an int and print it out
 */
        else if (format[i] == '%' && (format[i + 1] == 'd' || format[i + 1] == 'i'))
        {
                x = va_arg(args, int);
                    if (x < 0) {
                        _putchar('-');
                        x = -x;
                    }
                    if (x / 10 > 0)
                    {
                        _putchar(x / 10);
                    }
                    _putchar(x % 10 + '0');
                    i++;
                    continue;
        }    
        else if (format[i] == '%' && format[i + 1] == '%')
        {
            _putchar(format[i]);
            i++;
            continue;
        }
        else if (format[i] == '\n')
        {
            _putchar(10);
        }
        else
        {
		_putchar(format[i]);
        }
    }
    va_end(args);
    return(0);
}
