#include "monty.h"

/**
 * mod - computes the rest of the division of the second top element
 * of the stack by the top element of the stack.
 * @stack: Double pointer to the stack
 * @line_number: Line number of the opcode
 */
void mod(stack_t **stack, unsigned int line_number)
{
	int mod_result;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: ", line_number);
		fprintf(stderr, "can't mod, stack too short\n");
		free_glo();
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		free_glo();
		exit(EXIT_FAILURE);
	}
	mod_result = (*stack)->next->n % (*stack)->n;
	pop(stack, line_number);
	(*stack)->n = mod_result;
}

/**
 * pchar - Prints the char at the top of the stack
 * @stack: Double pointer to the stack
 * @line_number: Line number of the opcode
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		free_glo();
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%u: ", line_number);
		fprintf(stderr, "can't pchar, value out of range\n");
		free_glo();
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->n);
}

/**
 * pstr - Prints the string starting at the top of the stack
 * @stack: Double pointer to the stack
 * @line_number: Line number of the opcode
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;
	while (current != NULL && current->n != 0 &&
		current->n >= 0 && current-> <= 127)
	{
		printf("%c", current->n);
		current = current->next;
	}
	printf("\n");
}
