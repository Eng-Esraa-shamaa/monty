#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
#define INSTRUCTIONS { \
		{"push", push},\
		{"pall", pall},\
		{"pint", pint},\
		{"pop", pop},\
		{"swap", swap},\
		{"add", _add},\
		{"nop", nop},\
		{NULL, NULL} \
		}
/**
*struct help - for opcode
*@data_struct: mode of stack
*@argument: argument of structure
*Description: structure to pass data
*/
typedef struct help
{
	int data_struct;
	char *argument;
} help;

extern help global;
extern int status;
void error_file(char *argv);
void error_use(void);
void push(stack_t **stack, unsigned int line_count);
void pall(stack_t **stack, unsigned int line_count);
void pint(stack_t **stack, unsigned int line_count);
void pop(stack_t **stack, unsigned int line_count);
void swap(stack_t **stack, unsigned int line_count);
void _add(stack_t **stack, unsigned int line_count);
void nop(stack_t **stack, unsigned int line_count);

int is_digit(char *str);

stack_t *add_node(stack_t **stack, const int n);
stack_t *queue_node(stack_t **stack, const int n);
void _free_stack(stack_t *stack);
size_t _print_stack(const stack_t *stack);
void opcode(stack_t **stack, char *str, unsigned int line_cnt);
ssize_t getline(char **lineptr, size_t *n, FILE *stream);
#endif
