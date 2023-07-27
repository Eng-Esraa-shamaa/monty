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
	int j = 0;

	instruction_t op[] = OPERATIONS;

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
	while (op[j].opcode)
	{
		if (strcmp(op[j].opcode, str) == 0)
		{
			op[j].f(stack, line_count);
			return;
		}
		j++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_count, str);
	status = EXIT_FAILURE;
}
