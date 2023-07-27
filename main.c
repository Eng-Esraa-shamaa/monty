#include "monty.h"
help global;
int status = 0;
/**
 *main - main function
 *@argv: arguments vector
 *@argc: count of arguments
 *Return: nothing
*/
int main(int argc, char **argv)
{
	FILE *file;
	size_t buffer_length = 0;
	char *buff = NULL, *str = NULL;
	stack_t *stack = NULL;
	unsigned int line_count = 1;

	global.data_struct = 1;
	if (argc != 2)
		error_use();
	file = fopen(argv[1], "r");
	if (!file)
		error_file(argv[1]);
	while (getline(&buff, &buffer_length, file) != -1)
	{
		if (status)
		break;
		if (*buff == '\n')
		{
			line_count++;
			continue;
		}
		str = strtok(buff, " \t\n");
		if ((str == NULL) || (*str == '#'))
		{
			line_count++;
			continue;
		}
		global.argument = strtok(NULL, " \t\n");
		opcode(&stack, str, line_count);
		line_count++;
	}
	free(buff);
	_free_stack(stack);
	fclose(file);
	exit(status);
}
