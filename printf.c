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
    int i, x, count;
    char ch;
    char *string;
    int len = 0;
    va_list args;
    va_start(args, format);

    len = length(format);
    if (format == NULL)
    {
        return -1;
    }
    for (i = 0; format[i] != '\0'; i++)
    {
        
        if (format[i] == '%')
        {
            
            i++;
            if (format[i] == 'c')
            {
                ch = va_arg(args, int);
                _putchar(ch);
            }
            else if (format[i] == 's')
            {
                string = va_arg(args, char*);
                count = length(string);
                print_string(string, count);
            }
            else if (format[i] == 'd' || format[i] == 'i')
            {
                x = va_arg(args, int);
                print_int_c (x);
            }    
            else if (format[i] == '%')
            {
                _putchar('%');
            }
            else
            {
                write(1, &format[i], 1);
            }
        }
        else if (format[i] == '\\' && format[i+1] == '\n')
        {
            _putchar(10);
        }
        else
        {
		    write(1, &format[i], 1);
        }
    }
    va_end(args);
    return(len);
}


