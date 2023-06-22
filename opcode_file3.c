#include "monty.h"

/**
 * add - Adds the top two elements of the stack
 * @stack: Double pointer to the stack
 * @line_number: Line number of the opcode
 */
void add(stack_t **stack, unsigned int line_number)
{
	int sum = 0;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: ", line_number);
		fprintf(stderr, "can't add, stack too short\n");
		free_glo();
		exit(EXIT_FAILURE);
	}
	sum = (*stack)->n + (*stack)->next->n;
	pop(stack, line_number);
	(*stack)->n = sum;
}

/**
 * nop - Doesn't do anything
 * @stack: Double pointer to the stack
 * @line_number: Line number of the opcode
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * sub - Subtracts the top element of the stack from the second top element
 * @stack: Double pointer to the stack
 * @line_number: Line number of the opcode
 */
void sub(stack_t **stack, unsigned int line_number)
{
	int sub_result;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: ", line_number);
		fprintf(stderr, "can't sub, stack too short\n");
		free_glo();
		exit(EXIT_FAILURE);
	}
	sub_result = (*stack)->next->n - (*stack)->n;
	pop(stack, line_number);
	(*stack)->n = sub_result;
}
