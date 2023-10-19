#include "monty.h"

/**
 * op_add - A function that adds the top two elements.
 *
 * @stack: The head of the stack.
 *
 * Return: Nothing.
*/
void op_add(stack_t **stack, unsigned int line_number)
{
    unsigned int temp = 0, length = 0;

    length = count_stack(*stack);
    if (length < 2)
        handle_error(ADD_ERR, NULL, line_number, NULL);

    if ((*stack)->next != NULL)
    {
        temp = (*stack)->n + (*stack)->next->n;
        (*stack)->next->n = temp;
        op_pop(stack, line_number);
        return;
    }
}