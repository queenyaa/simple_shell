#include "shell.h"

/**
 * g_help - function that retrieves help messages according builtin
 * @inpsh: dta structure (args and input)
 * Return: Return 0
 */
int g_help(inp_shell *inpsh)
{
	if (inpsh->argt[1] == 0)
		acc_help_general();
	else if (_strcmp(inpsh->argt[1], "setenv") == 0)
		acc_help_setenv();
	else if (_strcmp(inpsh->argt[1], "env") == 0)
		acc_help_env();
	else if (_strcmp(inpsh->argt[1], "unsetenv") == 0)
		acc_help_unsetenv();
	else if (_strcmp(inpsh->argt[1], "help") == 0)
		acc_help();
	else if (_strcmp(inpsh->argt[1], "exit") == 0)
		acc_help_exit();
	else if (_strcmp(inpsh->argt[1], "cd") == 0)
		acc_help_cd();
	else if (_strcmp(inpsh->argt[1], "alias") == 0)
		acc_help_alias();
	else
		write(STDERR_FILENO, inpsh->argt[0],
			_strlen(inpsh->argt[0]));

	inpsh->presnt = 0;
	return (1);
}
