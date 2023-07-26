#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "monty.h"
help global;
int status = 0;
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
/**
 *main - main function
 *@argv: arguments vector
 *@argc: count of arguments
 *Return: nothing
*/
int main(int argc, char **argv)
{
	FILE *file;
	size_t buf_len = 0;
	char *buffer = NULL, *str = NULL;
	stack_t *stack = NULL;
	unsigned int line_count = 1;

	global.data_struct = 1;
	if (argc != 2)
		error_use();
	file = fopen(argv[1], "r");
	if (!file)
		error_file(argv[1]);
while (getline(&buffer, &buf_len, file) != -1)
{
if (status)
break;
if (*buffer == '\n')
{
line_count++;
continue;
}
str = strtok(buffer, " \t\n");
if ((str == NULL) || (*str == '#'))
{
line_count++;
continue;
}
global.argument = strtok(NULL, " \t\n");
opcode(&stack, str, line_count);
line_count++;
}
free(buffer);
free_stack(stack);
fclose(file);
exit(status);
}
