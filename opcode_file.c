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
