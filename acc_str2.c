#include "shell.h"

/**
 * _isdigit - function to check if a string has only numeric digits
 * @t: ...
 * Return: ...
 */
int _isdigit(const char *t)
{
	unsigned int x;

	for (x = 0; t[x]; x++)
	{
		if (t[x] < 48 || t[x] > 57)
			return (0);
	}
	return (1);
}

/**
 * _strtok - function that splits a string into tokens using
 * as specified delimiter.
 * @str: ...
 * @shrt: ...
 * Return: ...
 */
char *_strtok(char str[], const char *shrt)
{
	static char *dvd, *str_l;
	char *str_b;
	unsigned int x, bool;

	if (str != NULL)
	{
		if (cmp_chars(str, shrt))
			return (NULL);
		dvd = str;
		x = _strlen(str);
		str_l = &str[x];
	}
	str_b = dvd;
	if (str_b == str_l)
		return (NULL);

	for (bool = 0; *dvd; dvd++)
	{
		if (dvd != str_b)
			if (*dvd && *(dvd - 1) == '\0')
				break;
		for (x = 0; shrt[x]; x++)
		{
			if (*dvd == shrt[x])
			{
				*dvd = '\0';
				if (dvd == str_b)
					str_b++;
				break;
			}
		}
		if (bool == 0 && *dvd)
			bool = 1;
	}
	if (bool == 0)
		return (NULL);
	return (str_b);
}
