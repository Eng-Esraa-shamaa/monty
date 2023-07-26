#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"
/**
 *opcode - opcode function
 *@stack: stack given
 *@str: string
 *@line_count: count of lines
 *Return: nothing
*/
void opcode(stack_t **stack, char *str, unsigned int line_count)
{
	int i = 0;

	instruction_t op[] = INSTRUCTIONS;

	if (!strcmp(str, "stack"))
	{
		global.data_struct = 1;
		return;
	}
	if (!strcmp(str, "queue"))
	{
		global.data_struct = 0;
		return;
	}
	while (op[i].opcode)
	{
		if (strcmp(op[i].opcode, str) == 0)
		{
			op[i].f(stack, line_count);
			return;
		}
		i++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_count, str);
	status = EXIT_FAILURE;
}
