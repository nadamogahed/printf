#include "main.h"
/**
 * print_string - prints a string
 * @string: an arry pointer
 * Return: void
 */
int print_string(char *string)
{
	if (string == NULL)
	{
		return (write(STDOUT_FILENO, "(null)", 6));
	}
	else
	{
		return (write(STDOUT_FILENO, string, length(string)));
	}
}

