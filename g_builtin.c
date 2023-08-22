#include "shell.h"

/**
 * get_builtin - function to check if a given command matches
 * any of the built-in command in the arg
 * @cmd: command for which to determine if it's
 * a built-in command
 * Return: function pointer of the built-in command
 * (e.g. '_env', 'exit_sh', '_setenv', etc)
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

	/**
	 * iterates through the array comparing 'cmd' with
	 * with the names of built-in commands in the array using '_strcmp
	 */
	for (x = 0; builtin[x].nick; x++)
	{
		if (_strcmp(builtin[x].nick, cmd) == 0)
			break;
	}

	return (builtin[x].pf);
}
