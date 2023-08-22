#include "shell.h"

/**
 * g_err - function thatcalls the error according the built-in,
 * syntax or permission
 * @inpsh: data structure containing arguments and other relevant data
 * @eval: error value
 * Return: error (eval)
 */
int g_err(inp_shell *inpsh, int eval)
{
	char *err;

	switch (eval)
	{
		case -1:
			err = err_env(inpsh);
			break;
		case 126:
			err = err_path_126(inpsh);
			break;
		case 127:
			err = err_nfound(inpsh);
			break;
		case 2:
			if (_strcmp("exit", inpsh->argt[0]) == 0)
				err = err_exit_shell(inpsh);
			else if (_strcmp("cd", inpsh->argt[0]) == 0)
				err = err_g_cd(inpsh);
			break;
	}

	if (err)
	{
		write(STDERR_FILENO, err, _strlen(err));
		free(err);
	}

	inpsh->presnt = eval;
	return (eval);
}
