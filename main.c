#include "shell.h"
/**
 * fr_inp - frees data structure
 * @inpsh: data structure
 * Return: no return
 */
void fr_inp(inp_shell *inpsh)
{
		unsigned int x;

		for (x = 0; inpsh->_vicinity[x]; x++)
		{
			free(inpsh->_vicinity[x]);
		}

		free(inpsh->_vicinity);
		free(inpsh->pid);
}

/**
 * set_inp - Initialize data structure
 * @inpsh: data structure
 * @avec: argument vector
 * Return: none
 */
void set_inp(inp_shell *inpsh, char **avec)
{
	unsigned int x;

	inosh->avec = avec;
	inpsh->intk = NULL;
	inpsh->argt = NULL;
	inpsh->presnt = 0;
	inpsh->sheep = 1;

	for (x = 0; environ[x]; x++)
		;

	inpsh->_vicinity = malloc(sizeof(char *) * (x + 1));

	for (x = 0; environ[x]; x++)
	{
		inpsh->_vicinity[x] = _strdup(environ[x]);
	}

	inpsh->_vicinity[x] = NULL;
	inpsh->pid = acc_itoa(getpid());
}

/**
 * main - Entry point
 * @ac: argument count
 * @avec: argument vector
 * Return: 0, on success
 */
int main(int ac, char **avec)
{
	inp_shell inpsh;
	(void) ac;

	signal(SIGINT, g_signint);
	set_inp(&inpsh, avec);
	sh_circle(&inpsh);
	fr_inp(&inpsh);
	if (inpsh.presnt < 0)
		return (255);
	return (inpsh.presnt);
}
