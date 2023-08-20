#include "shell.h"
/**
 * g_signint - handle the ctrl + c call in prompt
 * @sym: signal handler
 */
void g_signint(int sym)
{
	(void)sym;
	write(STDOUT_FILENO, "\n$ ", 3);
}
