#include "monty.h"

void check_arg_num(int argc)
{
    if (argc != 2)
        handle_error(USAGE_ERR, NULL, 0, NULL);
}