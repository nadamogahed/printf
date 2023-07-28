#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int _printf(const char *format, ...)
{
    int count = 0;
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
                    count += write(STDOUT_FILENO, va_arg(args, char *), strlen(va_arg(args, char *)));
                    break;
                case 'd':
                case 'i':
                    {
                        int value = va_arg(args, int);
                        char buffer[12];
                        int i = 0;
                        if (value < 0) {
                            count += _putchar('-');
                            value = -value;
                        }
                        do {
                            buffer[i++] = (value % 10) + '0';
                            value /= 10;
                        } while (value != 0);
                        while (i-- > 0) {
                            count += _putchar(buffer[i]);
                        }
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
        {
            count += _putchar(*format);
        }
        format++;
    }

    va_end(args);

    return count;
}

int _putchar(char c)
{
    return write(STDOUT_FILENO, &c, 1);
}
