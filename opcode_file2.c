#include "monty.h"

/**
 * push - pushes an element to the stack.
 * @stack: double pointer to the stack
 * @line_number: Line number of the opcode
 * Return: Nothing
 */
void push(stack_t **stack, unsigned int line_number)
{
	int value, i;

	if (!glo.args)
	{
		fprintf(stderr, "L%u: ", line_number);
		fprintf(stderr, "usage: push integer\n");
		free_glo();
		exit(EXIT_FAILURE);
	}
	for (i = 0; glo.args[i] != '\0'; i++)
	{
		if (!isdigit(glo.args[i]) && glo.args[i] != '-')
		{
			fprintf(stderr, "L%u: ", line_number);
			fprintf(stderr, "usage: push integer\n");
			free_glo();
			exit(EXIT_FAILURE);
		}
	}
	value = atoi(glo.args);
	if (glo.fifo == 1)
	{
		add_dnodeint(stack, value);
	}
	else
	{
		add_dnodeint_end(stack, value);
	}
}

/**
 * pall - Prints all the values on the stack
 * @stack: Pointer to the stack
 * @line_number: Line number of the opcode
 * Return: void
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
	(void)line_number;

	current = *stack;
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * pint - Prints the value at the top of the stack
 * @stack: Double pointer to the stack
 * @line_number: Line number of the opcode
 */
void pint(stack_t **stack, unsigned int line_number)
{
	/*(void)line_number; */
	
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		free_glo();
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
