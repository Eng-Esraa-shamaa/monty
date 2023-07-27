#include "monty.h"
/**
 *_print_stack - prints the contents of a stack_t stack
 *@stack: stack
 *Return: number of elements in list
*/
size_t _print_stack(const stack_t *stack)
{
size_t i;

for (i = 0; stack != NULL; i++)
{
printf("%d\n", stack->n);
stack = stack->next;
}
return (i);
}
/**
 *_free_stack - frees a linked list
 *@stack: list head
 *Return: nothing
 */
void _free_stack(stack_t *stack)
{
	stack_t *current_list = stack;
	stack_t *next;

	if (stack)
	{
		next = stack->next;
		while (current_list != NULL)
		{
			free(current_list);
			current_list = next;
			if (next != NULL)
			{
				next = next->next;
			}
		}
	}
}
