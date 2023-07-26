#include "monty.h"
/**
 *print_stack - prints the contents of a stack_t stack
 *@stack: stack
 *Return: number of elements in list
*/
size_t print_stack(const stack_t *stack)
{
size_t i = 0;

while (stack != NULL)
{
printf("%d\n", stack->n);
stack = stack->next;
i++;
}
return (i);
}
/**
 *free_stack - frees a linked list
 *@stack: list head
 *Return: nothing
 */
void free_stack(stack_t *stack)
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
