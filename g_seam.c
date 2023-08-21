#include "shell.h"
/**
 * br_seam - assigns the line var for the get_line
 * @seamptr: Buffer that store the input str
 * @buff: str that is been called to line
 * @m: size of line
 * @y: size of buffer
 */
void br_seam(char **seamptr, size_t *m, char *buff, size_t y)
{
	if (*seamptr == NULL)
	{
		if (y > LOAD)
			*m = y;
		else
			*m = LOAD;
		*seamptr = buff;
	}
	else if (*m < y)
	{
		if (y > LOAD)
			*m = y;
		else
			*m = LOAD;
		*seamptr = buff;
	}
	else
	{
		_strcpy(*seamptr, buff);
		free(buff);
	}
}
/**
 * get_seam - read input from stream
 * @seamptr: buffer that stores the input
 * @m: size of lineptr
 * @strm: stream to read from
 * Return: number of bytes
 */
ssize_t get_seam(char **seamptr, size_t *m, FILE *strm)
{
	int x;
	static ssize_t intk;
	ssize_t rtval;
	char *buff;
	char tt = 'z';

	if (intk == 0)
		fflush(strm);
	else
		return (-1);
	intk = 0;

	buff = malloc(sizeof(char) * LOAD);
	if (buff == 0)
		return (-1);
	while (tt != '\n')
	{
		x = read(STDIN_FILENO, &tt, 1);

		if (x == -1 || (x == 0 && intk == 0))
		{
			free(buff);
			return (-1);
		}
		if (x == 0 && intk != 0)
		{
			intk++;
			break;
		}
		if (intk >= LOAD)
			buff = _realloc_(buff, intk, intk + 1);
		buff[intk] = tt;
		intk++;
	}
	buff[intk] = '\0';
	br_seam(seamptr, m, buff, intk);
	rtval = intk;
	if (x != 0)
		intk = 0;
	return (rtval);
}
