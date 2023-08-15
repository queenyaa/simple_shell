#include "shell.h"

/**
 * exit_sh - function to handle the "exit" command.
 * @inpsh: ...
 * Return: ...
 */
int exit_sh(inp_shell *inpsh)
{
	unsigned int ustat;
	int is_dig;
	int str_len;
	int bnum;

	if (insp->argt[1] != NULL)
	{
		ustat = _atoi(inpsh->argt[1]);
		is_dig = _isdigit(inpsh->argt[1]);
		str_len = _strlen(inpsh->argt[1]);
		bnum = ustat > (unsigned int)INT_MAX;
		if (!is_dig || str_len > 10 || bnum)
		{
			g_err(inpsh, 2);
			inpsh->presnt = 2;
			return (1);
		}
		inpsh->presnt = (ustat % 256);
	}
	return (0);
}
