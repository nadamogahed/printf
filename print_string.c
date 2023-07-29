#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "main.h"
/**
 * print_string - prints a string
 * @string: an arry pointer
 * @count: count the lenght
 * Return: void
 */
int print_string(char *string)
{
	if (string == NULL)
	{
		return(write(STDOUT_FILENO, "(null)", 6));
	}
	else
	{
		return(write(STDOUT_FILENO, string, length(string)));
	}
}
