#include "monty.h"

/**
  * handle_error - Manages the printing of interpreter errors
  *
  * @errno: The error code to manage
  * @opcode: The operation code to manage
  * @line: The line on which the error occurred
  * @buff: The reserved error line buffer
  *
  * Return: Nothing
*/
void handle_error(int errno, char *opcode, unsigned int line, char *buff)
{
	if (errno >= 100 && errno < 200)
		handle_cerror(errno, opcode, line);
	else if (errno >= 200 && errno <= 210)
		handle_uerror(errno, line);
	else if (errno >= 211 && errno <= 220)
		handle_more_uerror(errno, line);
	else
		return;

	frees_stack();

	if (buff)
		free(buff);

	exit(EXIT_FAILURE);
}

/**
  * handle_cerror - Manages common interpreter errors
  * @errno: The error code to manage
  * @opcode: The operation code to manage
  * @line: The line on which the error occurred
  *
  * Return: Nothing
*/
void handle_cerror(int errno, char *opcode, unsigned int line)
{
	switch (errno)
	{
		case UNKNOWN_INSTRUCTION:
			fprintf(stderr, "L%d: unknown instruction %s\n", line, opcode);
			break;
		case BAD_MALLOC:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		default:
			break;
	}
}

/**
  * handle_uerror - Manages interpreter usage errors
  *
  * @errno: The error code to manage
  * @line: The line on which the error occurred
  *
  * Return: Nothing
*/
void handle_uerror(int errno, unsigned int line)
{
	switch (errno)
	{
		case USAGE_ERR:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case PUSH_ERR:
			fprintf(stderr, "L%d: usage: push integer\n", line);
			break;
		case PINT_ERR:
			fprintf(stderr, "L%d: can't pint, stack empty\n", line);
			break;
		case POP_ERR:
			fprintf(stderr, "L%d: can't pop an empty stack\n", line);
			break;
		case SWAP_ERR:
			fprintf(stderr, "L%d: can't swap, stack too short\n", line);
			break;
		case ADD_ERR:
			fprintf(stderr, "L%d: can't add, stack too short\n", line);
			break;
		case SUB_ERR:
			fprintf(stderr, "L%d: can't sub, stack too short\n", line);
			break;
		case DIV_ERR:
			fprintf(stderr, "L%d: can't div, stack too short\n", line);
			break;
		case DIV_ERR_ZERO:
			fprintf(stderr, "L%d: division by zero\n", line);
			break;
		case MUL_ERR:
			fprintf(stderr, "L%d: can't mul, stack too short\n", line);
			break;
		case MOD_ERR:
			fprintf(stderr, "L%d: can't mod, stack too short\n", line);
			break;
		default:
			break;
	}   
}

/**
  * handle_more_uerror - Manages interpreter usage errors
  *
  * @errno: The error code to manage
  * @line: The line on which the error occurred
  *
  * Return: Nothing
*/
void handle_more_uerror(int errno, unsigned int line)
{
	switch (errno)
	{
		case PCHAR_ERR_USAGE:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", line);
			break;
		case PCHAR_ERR:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", line);
			break;
		default:
			break;
	}
}