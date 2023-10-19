#include "monty.h"

/**
 * op_pstr - A function that prints a string out of the stack/queue.
 *
 * @stack: The head of the stack.
 *
 * Return: Nothing.
*/
void op_pstr(stack_t **stack, unsigned int line_number)
{
    stack_t *temp = *stack;
    (void) line_number;
    
    while (temp)
    {
        if (temp->n == 0 || temp->n < 0 || temp->n > 127)
			break;

		printf("%c", temp->n);
		temp = temp->next;
    }
    printf("\n");
}