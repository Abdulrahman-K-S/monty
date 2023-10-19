#include "monty.h"

/**
  * op_pop - Remove the first node of a doubly linked list
  *
  * @stack: The head of the doubly linked list
  *
  * Return: Nothing
*/
void op_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack, *temp = NULL;

	if (*stack == NULL)
		handle_error(POP_ERR, NULL, line_number, NULL);

	temp = current;
	if (current->next)
	{
		current = current->next;
		current->prev = temp->prev;
		*stack = current;
	}
	else
	{
		*stack = NULL;
	}

	free(temp);
}