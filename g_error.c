#include "shell.h"

/**
 * g_err - calls the error according the builtin, syntax or permission
 * @inpsh: ...
 * @datash: data structure that contains arguments
 * @eval: error value
 * Return: error
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
			if (_strcmp("exit", inpsh->argt[0] == 0)
				err = err_exit_shell(inpsh);
			else if (_strcmp("cd", inpsh->argt[0] == 0)
				err = err_g_cd(inpsh);
			break;
	}

	if (err)
	{
		write(STDERR_FILENO, err, _strlen(err));
		free(err);
	}

	inpsh->present = eval;
	return (eval);
}
