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
 * cp_chars - function to compare characters of a string with
 * characters from a delimiter string
 * @str: ...
 * @shrt: ...
 * Return: ...
 */
int cp_chars(char str[], const char *shrt)
{
	unsigned int x, y, z;

	for (x = 0, z = 0; str[x]; x++)
	{
		for (y = 0; str[y]; y++)
		{
			if (str[x] == shrt[y])
			{
				z++;
				break;
			}
		}
	}
	if (x == z)
		return (1);
	return (0);
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
		if (cp_chars(str, shrt))
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

/**
 * _strlen - function to calculate length of string
 * @t: ...
 * Return: ...
 */
int _strlen(const char *t)
{
	int len;

	for (len = 0; t[len] != 0; len++)
	{
	}
	return (len);
}

/**
 * _strdup - function to duplicate a given string in heap memory
 * @t: ...
 * Return: ...
 */
char *_strdup(const char *t)
{
	char *nw;
	size_t len;

	len = _strlen(t);
	nw = malloc(sizeof(char) * (len + 1));
	if (nw == NULL)
		return (NULL);
	_memcpy(nw, t, len + 1);
	return (nw);
}
