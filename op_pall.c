#include "monty.h"

/**
 * op_pall - A function that prints the dlistint and returns
 *                  the length of the list.
 *
 * @stack: The head of the stack.
 *
 * Return: Nothing.
*/
void op_pall(const stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;
	(void) line_number;

	if (*stack)
	{
		temp = *stack;
		while (temp != NULL)
		{
			printf("%d\n", temp->n);
			temp = temp->next;
		}
	}
}