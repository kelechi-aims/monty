#include "monty.h"

/**
 * opcode_funs - gives the correct opcode based on input comparison
 * @op_code: points to the input opcode
 * Return: opcode function
 */
void (*opcode_funs(char *op_code))(stack_t **stack, unsigned int line_number)
{
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", div_op},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{"stack", stack},
		{"queue", queue},
		{NULL, NULL}
	};
	int i;

	for (i = 0; instructions[i].opcode; i++)
	{
		if (strcmp(instructions[i].opcode, op_code) == 0)
			break;
	}
	return (instructions[i].f);
}

/**
 * stack - Sets the format of the data to a stack (LIFO)
 * @stack: Double pointer to the stack
 * @line_number: Line number of the opcode
 */
void stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	glo.fifo = 1; /* Set FIFO flag to 1 for LIFO behavior */

}

/**
 * queue - Sets the format of the data to a stack (FIFO)
 * @stack: Double pointer to the stack
 * @line_number: Line number of the opcode
 */
void queue(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	glo.fifo = 0; /* Set FIFO flag to 0 for FIFO behavior */

}
