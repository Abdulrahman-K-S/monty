#ifndef _MONTY_
#define _MONTY_

/* Constants */
#define SUCSS_OP		0
#define VALID_PARM		0
#define MIN_ARGS		2
#define METH_STACK		300
#define METH_QUEUE		301

/* Common Errors */
#define UNKNOWN_INSTRUCTION	100
#define BAD_MALLOC	101
#define USAGE_ERR	102

/* Usage Errors */
#define ERR_ARG_USG		200
#define PUSH_ERR	201
#define PINT_ERR	202
#define POP_ERR		203
#define SWAP_ERR	204
#define ADD_ERR		205
#define SUB_ERR		206
#define DIV_ERR		207
#define DIV_ERR_ZERO		208
#define MUL_ERR		209
#define MOD_ERR		210
#define PCHAR_ERR_USAGE		211
#define PCHAR_ERR		212

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
 * for stack, queues, LIFO, FIFO Holberton project
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
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;

void check_args_num(int argn);
FILE *open_file(char *filename);
void check_access_rights(char *filename);
int check_push_param(char *param);
int check_digits(char *s);

/* Stack utilities */
void frees_stack(void);
unsigned int count_stack(stack_t *stack);

/* Error handlers */
void handle_error(int errno, char *opcode, unsigned int line, char *buff);
void handle_cerror(int errno, char *opcode, unsigned int line);
void handle_uerror(int errno, unsigned int line);
void handle_more_uerror(int errno, unsigned int line);

/* Execution functions */
int handle_execution(char *op_code, char *op_param, unsigned int line, int m);
void (*pick_func(char *s))(stack_t **, unsigned int);

/* op_codes Functions */
void op_push(stack_t **stack, unsigned int param);
void op_push_queue(stack_t **stack, unsigned int param);
void op_pall(stack_t **stack, unsigned int line_number);
void op_pint(stack_t **stack, unsigned int line_number);
void op_pop(stack_t **stack, unsigned int line_number);
void op_swap(stack_t **stack, unsigned int line_number);
void op_add(stack_t **stack, unsigned int line_number);
void op_nop(stack_t **stack, unsigned int line_number);
void op_sub(stack_t **stack, unsigned int line_number);
void op_divide(stack_t **stack, unsigned int line_number);
void op_mul(stack_t **stack, unsigned int line_number);
void op_mod(stack_t **stack, unsigned int line_number);
void op_pchar(stack_t **stack, unsigned int line_number);
void op_pstr(stack_t **stack, unsigned int line_number);
void op_rotl(stack_t **stack, unsigned int line_number);
void op_rotr(stack_t **stack, unsigned int line_number);

#endif