#include "monty.h"

/**
 * free_stack - A function that frees that stack.
 *
 * @stack: The head of the stack.
*/
void free_stack(stack_t *stack)
{
	stack_t *temp;

	if (stack == NULL)
		return;

	temp = stack->next;
	free(stack);
	free_stack(temp);
}

/**
  * count_stack - Counts the number of elements in the stack
  * @stack: The stack to count
  *
  * Return: Number of elements in the stack
  */
unsigned int count_stack(stack_t *stack)
{
	stack_t *current = stack;
	unsigned int lenght = 0;

	while (current != NULL)
	{
		++lenght;
		current = current->next;
	}

	return (lenght);
}