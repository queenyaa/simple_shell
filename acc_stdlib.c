#include "main.h"

/**
 * _atoi - function to convert a string to an integer
 * @t: ...
 * Return: ...
 */
int _atoi(char *t)
{
	unsigned int flip = 0, sz = 0, mi = 0, mp = 1, p = 1, x;

	while (*(t + flip) != '\0')
	{
		if (sz > 0 && (*(t + flip) < '0' || *(t + flip) > '9'))
			break;

		if (*(t + flip) == '-')
			mp *= -1;
		if ((*(t + flip) >= '0') && (*(t + flip) <= '9'))
		{
			if (sz > 0)
				p *= 10;
			sz++;
		}
		flip++;
	}
	for (x = flip - sz; x < flip; x++)
	{
		mi = mi + ((*(t + x) - 48) * p);
		p /= 10;
	}
	return (mi * mp);
}

/**
 * acc_itoa - function converts an integer to a string
 * @m: ...
 * Return: ...
 */
char *acc_itoa(int m)
{
	unsigned int m1;
	int lght = g_len(m);
	char *buff;

	buff = malloc(sizeof(char) * (lght + 1));
	if (buff == 0)
		return (NULL);

	*(buff + lght) = '\0';

	if (m < 0)
	{
		m1 = m * -1;
		buff[0] = '-';
	}
	else
		m1 = m;
	lght--;
	do {
		*(buff + lght) = (m1 % 10) + '0';
		m1 = m1 / 10;
		lght--;
	}
	while (m1 > 0)
		;
	return (buff);
}

/**
 * g_len - function that calculates the length of an integer
 * when it is represented as a string
 * @m: ...
 * Return: ...
 */
int g_len(int m)
{
	unsigned int m1;
	int lght = 1;

	if (m < 0)
	{
		lght++;
		m1 = m * -1;
	}
	else
		m1 = m;
	while (m1 > 9)
	{
		lght++;
		m1 = m1 / 10;
	}
	return (lght);
}
