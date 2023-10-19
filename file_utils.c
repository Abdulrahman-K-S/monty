#include "monty.h"

/**
 * open_file - A function that opens a given file if possible.
 *
 * @filename: The file to open.
 *
 * Return: The file.
*/
FILE *open_file(char *filename)
{
    FILE *fd = NULL;

    access_rights(filename);
    fd = fopen(filename, "r");

    if (!fd)
    {
        fprintf(stderr, "Error: Can't open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    return (fd);
}

/**
 * access_rights - A function that checks if the user has permission to open
 *                 the file.
 *
 * @filename: The filename.
 *
 * Return: Nothing.
*/
void access_rights(char *filename)
{
    if (access(filename, R_OK) == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
}