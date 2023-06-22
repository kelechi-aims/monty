#include "monty.h"


/**
 * *add_dnodeint - adds a new node at the beginning of a dlistint_t list
 * @head: pointer to a pointer to the head of the list
 * @n: value to be assigned to the new node
 * Return: the address of the new element, or NULL if it fails
 */
stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *newnode;

	if (head == NULL)
	{
		return (NULL);
	}
	newnode = malloc(sizeof(stack_t));
	if (newnode == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_glo();
		exit(EXIT_FAILURE);
	}
	newnode->n = n;
	newnode->prev  = NULL;
	newnode->next = *head;
	if (*head != NULL)
	{
		(*head)->prev = newnode;
	}
	*head = newnode;
	return (newnode);
}

/**
 *add_dnodeint_end - adds a node at the end of a dlistint_t list
 * @head: double pointer to the head node of the list
 * @n: value of the node to be added
 * Return: the address of the new element, or NULL if it failed
 */
stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *newnode, *temp;

	if (head  == NULL)
	{
		return (NULL);
	}
	newnode = malloc(sizeof(stack_t));
	if (newnode == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_glo();
		exit(EXIT_FAILURE);
	}
	newnode->n = n;
	newnode->next = NULL;
	if (*head == NULL)
	{
		newnode->prev = NULL;
		*head = newnode;
		return (newnode);
	}
	temp = *head;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = newnode;
	newnode->prev = temp;
	return (newnode);
}

/**
 * free_dlistint - frees a dlistint_t list
 * @head: points to the head node of the list
 * Return: nothing
 */
void free_dlistint(stack_t *head)
{
	stack_t *temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}
