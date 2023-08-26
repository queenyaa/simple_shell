#include "shell.h"
/**
 * rd_seam - reads the input string
 * @x_eof: return value of getline function
 * Return: input string
 */
char *rd_seam(int *x_eof)
{
	char *intk = NULL;
	size_t load = 0;

	*x_eof = getline(&intk, &load, stdin);

	return (intk);
}
