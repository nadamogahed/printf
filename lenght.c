#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "main.h"
/**
 * length - lenght of string
 * @string: an array pointer
 * Return: int
 */
int length(const char *string)
{
	int len = 0;

	while (string[len] != '\0')
	{
		len++;
	}
	return (len);
}
