#include "monty.h"

/**
 * op_pchar - A function that prints the ascii value of the top element.
 *
 * @stack: The head of the stack.
 *
 * Return: Nothing. 
*/
void op_pchar(stack_t **stack, unsigned int line_number)
{
    if (*stack == NULL)
        handle_error(PCHAR_ERR, NULL, 0, NULL);
    
    if ((*stack)->n >= 0 && (*stack)->n <= 127)
		printf("%c\n", (*stack)->n);
	else
		handle_error(PCHAR_ERR_USAGE, NULL, line_number, NULL);
}