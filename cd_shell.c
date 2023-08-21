#include "shell.h"

/**
 * cd_shell - changes the current directory based on the input
 * @inpsh: ...
 * Return: ...
 */
int cd_shell(inp_shell *inpsh)
{
	char *dir;
	int ihome, ihome2, iddash;

	dir = inpsh->argt[1];

	if (dir != NULL)
	{
		ihome = _strcmp("$HOME", dir);
		ihome2 = _strcmp("~", dir);
		iddash = _strcmp("--", dir);
	}

	if (dir == NULL || !ihome || !ihome2 || !iddash)
	{
		cd_to_home(inpsh);
		return (1);
	}
	if (_strcmp("-", dir) == 0)
	{
		cd_previous(inpsh);
		return (1);
	}
	if (_strcmp(".", dir) == 0 || _strcmp("..", dir) == 0)
	{
		cd_dt(inpsh);
		return (1);
	}
	cd_to(inpsh);

	return (1);
}
