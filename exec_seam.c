#include "shell.h"

/**
 * exec_line - function is responsible for determining whether
 * the input command  is a built-in command or an external command
 * and then dispatching the appropriate action
 * @inpsh: pointer to the data structure (argt)
 * that holds command-related information
 * Return: 1 on success
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
