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
    int i, x;
    char ch;
    char *string, *ptr;
    int len = 0;
    va_list args;
    va_start(args, format);

    while (format[len] != '\0')
    {
        len++;
    }
    if (format == NULL)
    {
        return -1; // or whatever error code is appropriate
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
                char *string = va_arg(args, char*);
                int count = 0;
                while (string[count] != '\0') {
                    count++;
                }
                char *ptr = (char *) malloc((count + 1) * sizeof(char));
                if (ptr == NULL) {
                    // Error handling code
                    return -1;
                }
                for (int j = 0; j < count; j++) {
                    ptr[j] = string[j];
                }
                ptr[count+1] = '\0';
                write(STDOUT_FILENO, ptr, count);
                free(ptr);
            }
            else if (format[i] == 'd' || format[i] == 'i')
            {
                x = va_arg(args, int);
                if (x < 0) {
                    putchar('-');
                    x = -x;
                }
                if (x / 10 > 0)
                {
                    _printf("%d", x / 10);
                }
                putchar(x % 10 + '0');
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

