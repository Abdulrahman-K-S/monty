#include "monty.h"

/**
 * op_div - A function that divides the top two elements.
 *
 * @stack: The head of the stack.
 *
 * Return: Nothing.
*/
void op_div(stack_t **stack, unsigned int line_number)
{
    unsigned int temp = 0, length = 0;

    length = count_stack(*stack);
    if (length < 2)
        handle_error(DIV_ERR, NULL, line_number, NULL);

    if ((*stack)->n == 0)
        handle_error(DIV_ERR_ZERO, NULL, line_number, NULL);

    if ((*stack)->next != NULL)
    {
        temp = (*stack)->next->n / (*stack)->n;
        (*stack)->next->n = temp;
        op_pop(stack, line_number);
        return;
    }
}