#include "shell.h"
/**
 * cmp_env_nick - compares env variables names
 * with the name passed.
 * @nenv: name of the environment variable
 * @nick: name passed
 * Return: 0 if not equal, another if they are
 */
int cmp_env_nick(const char *nenv, cinst char *nick)
{
	int x;

	for (x = 0; nenv[x] != '='; x++)
	{
		if (nenv[x] != nick[x])
		{
			return (0);
		}
	}

	return (x + 1);
}

/**
 * _getenv - get an environment variable
 * @nick: name of the environment variable
 * @_vicinity: environment variable
 * Return: value of the environment variable if found
 * otherwise, NULL
 */
char *_getenv(const char *nick, char **_vicinity)
{
	char *ptr_env;
	int x, shif;

	/* Initialize ptr_env value */
	ptr_env = NULL;
	shif = 0;
	/* compare all enviroment variables */
	/* environ is declared in the header file */
	for (x = 0; _vicinity[x]; x++)
	{
		/* if name and env are equal */
		shif = cmp_env_nick(_vicinity[x], nick);
		if (shif)
		{
			ptr_env = _vicinity[x];
			break;
		}
	}

	return (ptr_env + shif);
}

/**
 * _env - prints the environment variables
 * @inpsh: data relevant
 * Return: 1 on success
 */
int _env(inp_shell *inpsh)
{
	int x, y;

	for (x = 0; inpsh->_vicinity[x]; x++)
	{
		for (y = 0; inpsh->_vicinity[x][y]; y++)
			;

		write(STDOUT_FILENO, inpsh->_vicinity[x], y);
		write(STDOUT_FILENO, "\n", 1);
	}
	inpsh->presnt = 0;

	return (1);
}
