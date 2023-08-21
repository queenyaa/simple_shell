#include "shell.h"

/**
 * get_builtin - builtin that pais the command in the arg
 * @cmd: command
 * Return: function pointer of the builtin command
 */
int (*get_builtin(char *cmd))(inp_shell *)
{
	inher_u builtin[] = {
		{ "env", _env },
		{ "exit", exit_sh },
		{ "setenv", _setenv },
		{ "unsetenv", _unsetenv },
		{ "cd", cd_shell },
		{ "help", g_help },
		{ NULL, NULL }
	};
	int x;

	for (x = 0; builtin[x].nick; x++)
	{
		if (_strcmp(builtin[x].nick, cmd) == 0)
			break;
	}

	return (builtin[x].pf);
}
