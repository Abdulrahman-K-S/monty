#include "monty.h"

/**
 * op_push_start - A function that adds a new node at the beginning of the list.
 *
 * @stack: The head of the stack.
 * @param: The int to store in the node.
 *
 * Return: Nothing.
*/
void op_push_start(stack_t **stack, unsigned int param)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (!node)
		handle_error(BAD_MALLOC, NULL, 0, NULL);

	node->n = param;
	if (*stack)
	{
		node->next = *stack;
		node->prev = (*stack)->prev;
		(*stack)->prev = node;
		*stack = node;
		return;
	}

	node->next = *stack;
	node->prev = NULL;
	*stack = node;
}

/**
 * op_push_end - A function that adds a new node at the end of the list.
 *
 * @stack: The head of the stack.
 * @param: The int to store in the node.
 *
 * Return: Nothing.
*/
void op_push_end(stack_t **stack, const int param)
{
	stack_t *node = NULL, *temp = NULL;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		handle_error(BAD_MALLOC, NULL, 0, NULL);

	node->n = param;
	if (*stack)
	{
		temp = *stack;
		while (temp->next != NULL)
			temp = temp->next;

		node->next = NULL;
		node->prev = temp;
		temp->next = node;
		return;
	}

	node->next = *stack;
	node->prev = NULL;
	*stack = node;
}