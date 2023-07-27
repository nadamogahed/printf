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
    char *ch;
    int unsupported_specifier_displayed = 0;

    va_list args;
    va_start(args, format);

    for (i = 0; format[i] != '\0'; i++)
    {
/* if the next char in the placeholder string is a 'd', extract the next
 * argument as an int and print it out
 */
        if (format[i] == '%')
        {
            switch(format[i + 1]) {
            case 'c':
            ch =  va_arg(args, char *);
            _putchar(ch[0]);
            case 's':
                
                string = va_arg(args, char *);
                for (j = 0; string[j] != '\0'; j++) {
                    _putchar(string[j]);
                }
                break;
/* if the next char in the placeholder string is a 'd' or 'i', extract the next
 * argument as an int and print it out
 */
            case 'd':
            case 'i':
                x = va_arg(args, int);
                    if (x < 0) {
                        _putchar('-');
                        x = -x;
                    }
                    if (x / 10 > 0)
                    {
                        _printf("%d", x / 10);
                    }
                    _putchar(x % 10 + '0');
                
                break;
            default:
                if (!unsupported_specifier_displayed)
                        {
                            write(1, "Unsupported format specifier", 29);
                            unsupported_specifier_displayed = 1;
                        }
                break;
            }
            
        }
        else if (format[i] == '\n')
        {
                _putchar(10);
            
        }
    }
    va_end(args);
    return(0);
}
