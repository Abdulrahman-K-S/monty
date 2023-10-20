#include "monty.h"

/**
  * pick_func - Select the function that relates to the Monty instruction
  * @s: The instruction to be executed
  *
  * Return: A pointer to the function to be executed or
  * NULL if the function don't exists
  */
void (*pick_func(char *s))(stack_t **, unsigned int)
{
	instruction_t insts[] = {
		{ "push", op_push },
		{ "push_queue", op_push_queue },
		{ "pall", op_pall },
		{ "pint", op_pint },
		{ "pop", op_pop },
		{ "swap", op_swap },
		{ "add", op_add },
		{ "nop", op_nop },
		{ "sub", op_sub },
		{ "div", op_divide },
		{ "mul", op_mul },
		{ "mod", op_mod },
		{ "pchar", op_pchar },
		{ "pstr", op_pstr },
		{ "rotl", op_rotl },
		{ "rotr", op_rotr },
		{ NULL, NULL }
	};
	int i = 0;

	while (insts[i].opcode)
	{
		if (strcmp(s, insts[i].opcode) == 0)
			return (insts[i].f);

		++i;
	}

	return (NULL);
}