#include "shell.h"

/**
 * rv_string - function that reverses the characters in a string
 * @t: ...
 * Return: ...
 */
void rv_string(char *t)
{
	int flip = 0, x, y;
	char *str, tmp;

	while (flip >= 0)
	{
		if (t[flip] == '\0')
			break;
		flip++;
	}
	str = t;

	for (x = 0; x < (flip - 1); x++)
	{
		for (y = x + 1; y > 0; y--)
		{
			tmp = *(str + y);
			*(str + y) = *(str + (y - 1));
			*(str + (y - 1)) = tmp;
		}
	}
}
