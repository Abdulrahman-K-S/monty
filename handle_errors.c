#include "monty.h"

/**
  * handle_error - Manages the printing of interpreter errors
  * @errorno: The error code to manage
  * @opcode: The operation code to manage
  * @line: The line on which the error occurred
  * @buff: The reserved error line buffer
  *
  * Return: Nothing
  */
void handle_error(int errorno, char *opcode, unsigned int line, char *buff)
{
	if (errorno >= 100 && errorno < 200)
		handle_cerror(errorno, opcode, line);
	else if (errorno >= 200 && errorno <= 210)
		handle_uerror(errorno, line);
	else if (errorno >= 211 && errorno <= 220)
		handle_more_uerror(errorno, line);
	else
		return;

	frees_stack();

	if (buff)
		free(buff);

	exit(EXIT_FAILURE);
}

/**
  * handle_cerror - Manages common interpreter errors
  * @errorno: The error code to manage
  * @opcode: The operation code to manage
  * @line: The line on which the error occurred
  *
  * Return: Nothing
  */
void handle_cerror(int errorno, char *opcode, unsigned int line)
{
	switch (errorno)
	{
		case ERR_BAD_INST:
			fprintf(stderr, "L%d: unknown instruction %s\n", line, opcode);
			break;
		case ERR_BAD_MALL:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		default:
			break;
	}
}

/**
  * handle_uerror - Manages interpreter usage errors
  * @errno: The error code to manage
  * @line: The line on which the error occurred
  *
  * Return: Nothing
  */
void handle_uerror(int errorno, unsigned int line)
{
	switch (errorno)
	{
		case ERR_ARG_USG:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case ERR_PUSH_USG:
			fprintf(stderr, "L%d: usage: push integer\n", line);
			break;
		case ERR_PINT_USG:
			fprintf(stderr, "L%d: can't pint, stack empty\n", line);
			break;
		case ERR_POP_USG:
			fprintf(stderr, "L%d: can't pop an empty stack\n", line);
			break;
		case ERR_SWAP_USG:
			fprintf(stderr, "L%d: can't swap, stack too short\n", line);
			break;
		case ERR_ADD_USG:
			fprintf(stderr, "L%d: can't add, stack too short\n", line);
			break;
		case ERR_SUB_USG:
			fprintf(stderr, "L%d: can't sub, stack too short\n", line);
			break;
		case ERR_DIV_USG:
			fprintf(stderr, "L%d: can't div, stack too short\n", line);
			break;
		case ERR_DIV_ZRO:
			fprintf(stderr, "L%d: division by zero\n", line);
			break;
		case ERR_MUL_USG:
			fprintf(stderr, "L%d: can't mul, stack too short\n", line);
			break;
		case ERR_MOD_USG:
			fprintf(stderr, "L%d: can't mod, stack too short\n", line);
			break;
		default:
			break;
	}
}

/**
  * handle_more_uerror - Manages interpreter usage errors
  * @errorno: The error code to manage
  * @line: The line on which the error occurred
  *
  * Return: Nothing
  */
void handle_more_uerror(int errorno, unsigned int line)
{
	switch (errorno)
	{
		case ERR_PCH_USG:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", line);
			break;
		case ERR_PCH_EMP:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", line);
			break;
		default:
			break;
	}
}