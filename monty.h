#ifndef MONTY_H
#define MONTY_H

#define USING_STACK 300
#define USING_QUEUE 301

/* Common errors */
#define UNKNOWN_INSTRUCTION 100 /*L%d: unknown instruction %s\n*/
#define BAD_MALLOC 101 /*Error: malloc failed\n*/

/* Interpreter errors */
#define USAGE_ERR 200 /*USAGE: monty file*/
#define PUSH_ERR 201 /*L%d: usage: push integer\n*/
#define PINT_ERR 202 /*L%d: can't pint, stack empty\n*/
#define POP_ERR 203 /*L%d: can't pop an empty stack\n*/
#define SWAP_ERR 204 /*L%d: can't swap, stack too short\n*/
#define ADD_ERR 205 /*L%d: can't add, stack too short\n*/
#define SUB_ERR 206 /*L%d: can't sub, stack too short\n*/
#define DIV_ERR 207 /*L%d: can't div, stack too short\n*/
#define DIV_ERR_ZERO 208 /*L%d: division by zero\n*/
#define MUL_ERR 209 /*L%d: can't mul, stack too short\n*/
#define MOD_ERR 210 /*L%d: can't mod, stack too short\n*/
#define PCHAR_ERR_USAGE 211 /*L%d: can't pchar, value out of range\n*/
#define PCHAR_ERR 212 /*L%d: can't mod, stack too short\n*/

#include <ctype.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *stack;

/* op-code Functions */
void op_push_start(stack_t **stack, unsigned int param);
void op_push_end(stack_t **stack, const int param);
void op_pall(stack_t **stack, unsigned int line_number);
void op_pint(stack_t **stack, unsigned int line_number);
void op_pop(stack_t **stack, unsigned int line_number);
void op_swap(stack_t **stack, unsigned int line_number);
void op_add(stack_t **stack, unsigned int line_number);
void op_nop(stack_t **stack, unsigned int line_number);
void op_sub(stack_t **stack, unsigned int line_number);
void op_div(stack_t **stack, unsigned int line_number);
void op_mul(stack_t **stack, unsigned int line_number);
void op_mod(stack_t **stack, unsigned int line_number);
void op_pchar(stack_t **stack, unsigned int line_number);
void op_pstr(stack_t **stack, unsigned int line_number);
void op_rotl(stack_t **stack, unsigned int line_number);
void op_rotr(stack_t **stack, unsigned int line_number);

/* Stack utilities */
void free_stack(stack_t *stack);
unsigned int count_stack(stack_t *stack);

/* File functions */
FILE *open_file(char *filename);
void access_rights(char *filename);

/* Handle error functions*/
void handle_error(int errno, char *op_code, unsigned int line, char *buff);
void handle_cerror(int errno, char *opcode, unsigned int line);
void handle_uerror(int errno, unsigned int line);
void handle_more_uerror(int errno, unsigned int line);

#endif