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
    int len_str;
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
                ch = va_arg(args, int);
                len_str += _putchar(ch);
            }
            else if (format[i] == 's')
            {
                string = va_arg(args, char*);
                if (string == NULL)
                {
                    len_str += write(STDOUT_FILENO, "(null)", 6);
                }
                else 
                {
                    count = length(string);
                    len_str += print_string(string, count);
                }
            }
            else if (format[i] == 'd' || format[i] == 'i')
            {
                x = va_arg(args, int);
                print_int_c (x);
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
    return(len_str);
}
