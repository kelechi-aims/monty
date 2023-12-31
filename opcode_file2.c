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

/**
 * pop - Removes the top element of the stack
 * @stack: Double pointer to the stack
 * @line_number: Line number of the opcode
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: ", line_number);
		fprintf(stderr, "can't pop an empty stack\n");
		free_glo();
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	*stack = (*stack)->next;
	if (*stack != NULL)
	{
		(*stack)->prev = NULL;
	}
	free(temp);
}

/**
 * swap - Swaps the top two elements of the stack
 * @stack: Double pointer to the stack
 * @line_number: Line number of the opcode
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *top1, *top2;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: ", line_number);
		fprintf(stderr, "can't swap, stack too short\n");
		free_glo();
		exit(EXIT_FAILURE);
	}
	top1 = *stack;
	top2 = top1->next;
	top1->next = top2->next;
	if (top2->next != NULL)
	{
		top2->next->prev = top1;
	}
	top2->prev = NULL;
	top2->next = top1;
	top1->prev = top2;
	*stack = top2;
}
