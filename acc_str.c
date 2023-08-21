#include "shell.h"

/**
 * _strspn - function that calculates the length of a prefix substring
 * containing only characters from specified set
 * @t: ...
 * @take: ...
 * Return: ...
 */
int _strspn(char *t, char *take)
{
	int x, y, bool;

	for (x = 0; *(t + x) != '\0'; x++)
	{
		bool = 1;
		for (y = 0; *(take + y) != '\0'; y++)
		{
			if (*(t + x) == *(take + y))
			{
				bool = 0;
				break;
			}
		}
		if (bool == 1)
			break;
	}
	return (x);
}

/**
 * _strchr - function to searches for the 1st occurrence of a character
 * in a string
 * @t: ...
 * @c1: ...
 * Return: ...
 */
char *_strchr(char *t, char c1)
{
	unsigned int x = 0;

	for (; *(t + x) != '\0'; x++)
		if (*(t + x) == c1)
			return (t + x);
	if (*(t + x) == c1)
		return (t + x);
	return ('\0');
}

/**
 * _strcmp - function that compartes 2 strings lexicographically
 * @t1: ...
 * @t2: ...
 * Return: ...
 */
int _strcmp(char *t1, char *t2)
{
	int x;

	for (x = 0; t1[x] == t2[x] && t1[x]; x++)
		;
	if (t1[x] > t2[x])
		return (1);
	if (t1[x] < t2[x])
		return (-1);
	return (0);
}

/**
 * _strcpy - function that copies the content of 1 string to another
 * @des: ...
 * @sr: ...
 * Return: ...
 */
char *_strcpy(char *des, char *sr)
{
	size_t ad;

	for (ad = 0; sr[ad] != '\0'; ad++)
		des[ad] = sr[ad];
	des[ad] = '\0';

	return (des);
}

/**
 * _strcat - function to concatenate 2 strings by appending the
 * content of the source string to the end of the destination string
 * @des: ...
 * @sr: ...
 * Return: ...
 */
char *_strcat(char *des, const char *sr)
{
	int x, y;

	for (x = 0; des[x] != '\0'; x++)
		;

	for (y = 0; sr[y] != '\0'; y++)
	{
		des[x] = sr[y];
		x++;
	}
	des[x] = '\0';
	return (des);
}
