#include "monty.h"

/**
 * op_swap - A function that swaps the top 2 elements together.
 *
 * @stack: The head of the stack.
 * 
 * Return: Nothing.
*/
void op_swap(stack_t **stack, unsigned int line_number)
{
    unsigned int temp = 0, length = 0;

    length = count_stack(*stack);
    if (length < 2)
        handle_error(SWAP_ERR, NULL, line_number, NULL);

    if ((*stack)->next != NULL)
    {
        temp = (*stack)->n;
        (*stack)->n = (*stack)->next->n;
        (*stack)->next->n = temp;
        return;
    }
}