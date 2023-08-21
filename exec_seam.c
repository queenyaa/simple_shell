#include "shell.h"

/**
 * exec_line - finds builtins and commands
 * @inpsh: relevant data? (argt)
 * Return: 1
 */
int exec_line(inp_shell *inpsh)
{
	int (*builtin)(inp_shell *inpsh);

	if (inpsh->argt[0] == NULL)
		return (1);

	builtin = get_builtin(inpsh->argt[0]);

	if (builtin != NULL)
		return (builtin(inpsh));

	return (cmd_execut(inpsh));
}
