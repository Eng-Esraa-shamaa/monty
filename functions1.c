#include <ctype.h>
#include "monty.h"
/**
 *is_digit - checks if it is digit
 *@str: str for check
 *Return: 1 when success or 0
*/
int is_digit(char *str)
{
	if ((str == NULL) || *str == '\0')
		return (0);
	if (*str == '-')
		str++;
	while (*str)
	{
		if (isdigit(*str) == 0)
			return (0);
		str++;
	}
	return (1);
}
/**
 *isnumber - checks if it is a number
 *@str: the string
 *Return: 1 or 0.
*/
