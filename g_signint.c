#include "shell.h"

/**
 * g_signint - function to handle the 'SIGNINT',
 * the ctrl + c call in prompt
 * @sym: signal handler
 * Return: Nothing
 */
void g_signint(int sym)
{
	(void)sym;
	write(STDOUT_FILENO, "\n$ ", 3);
}
