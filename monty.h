#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>

/* Structures */

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

/**
 * strcut global_vars - global structure containing variables
 * @fifo: either stack or queue
 * @curr: this is the current line
 * @args: pointer to the second parameter in the current line
 * @buff: points to the inputed text
 * @head: points to head of the doubly linked list
 * @fd: points to the file descriptor
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct global_vars
{
	int fifo;
	unsigned int curr;
	char *args;
	char *buff;
	stack_t *head;
	FILE *fd;
} global_v;

extern global_v glo;

/* opcode_file.c */
void (*opcode_funs(char *op_code))(stack_t **stack, unsigned int line_number);

/* opcode_file2.c */
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);

/* opcode_file3.c */
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void div_op(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);

/* monty.c*/
void free_glo(void);
void glo_init(FILE *fd);
FILE *file_check(int ac, char *av[]);

/* linked_list.c */
stack_t *add_dnodeint(stack_t **head, const int n);
stack_t *add_dnodeint_end(stack_t **head, const int n);
void free_dlistint(stack_t *head);


#endif
