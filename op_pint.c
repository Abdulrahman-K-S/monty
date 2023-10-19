#include "monty.h"

/**
 * op_pint - A function that prints the value of the top of the stack.
 * 
 * @stack: The head of the stack.
 * 
 * Return: Nothing.
*/
void op_pint(stack_t **stack, unsigned int line_number)
{
    if (*stack == NULL)
        handle_error(PINT_ERR, NULL, line_number, NULL);
    
    printf("%d\n", (*stack)->n);
}