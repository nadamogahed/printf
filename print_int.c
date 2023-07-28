#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "main.h"
void print_int_c (int x)
{
    if (x < 0) {
                    _putchar('-');
                    x = -x;
                }
                if (x / 10 > 0)
                {
                    _printf("%d", x / 10);
                }
                _putchar(x % 10 + '0');
}
