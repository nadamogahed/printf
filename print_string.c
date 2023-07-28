#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "main.h"
void print_string(char *string, int count)
{
    char *ptr;
    int j = 0;
    ptr = (char *) malloc((count + 1) * sizeof(char));
    if (ptr == NULL) 
    {
        return;
    }
    for (j = 0; j < count; j++) 
    {
        ptr[j] = string[j];
    }
    ptr[count] = '\0';
    write(STDOUT_FILENO, ptr, count);
    free(ptr);
}
