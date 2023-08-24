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

	intk = malloc(sizeof(char)); /*allocate at least 1 byte*/
	if (intk == NULL)
	{
		perror("malloc");
		*x_eof = 1; /*set EOF indicator*/
		return (NULL);
	}
	intk[0] = '\0';

	*x_eof = getline(&intk, &load, stdin);

	return (intk);
}
