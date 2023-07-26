#include "monty.h"
/**
 *push - push into the stack
 *@stack: stack given
 *@line_count: count of lines
 *Return: nothing
*/
void push(stack_t **stack, unsigned int line_count)
{
	char *n = global.argument;

	if ((is_digit(n)) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_count);
		status = EXIT_FAILURE;
		return;
	}
	if (global.data_struct == 1)
	{
		if (add_node(stack, atoi(global.argument)) == NULL)
		{
			return;
			status = EXIT_FAILURE;
		}
	}
	else
	{
		if (queue_node(stack, atoi(global.argument)) == NULL)
		{
			return;
			status = EXIT_FAILURE;
		}
	}
}
