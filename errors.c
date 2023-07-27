#include "monty.h"
/**
 *error_use - print error use msg
 *Return: nothing
*/
void error_use(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}
/**
 *error_file - prints error msg in case of error file
 *@argv: arguments vector
 *Return: nothing
*/
void error_file(char *argv)
{
	fprintf(stderr, "Error: Can't open file %s\n", argv);
	exit(EXIT_FAILURE);
}
