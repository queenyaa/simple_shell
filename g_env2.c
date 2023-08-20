#include "shell.h"
/**
 * cp_info - copies info to create a new env or alias
 * @nick: name (env or alias)
 * @value: value (env or alias)
 * Return: new env or alias
 */
char *cp_info(char *nick, char *value)
{
	char *nw;
	int len_nick, len_value, len;

	len_nick = _strlen(nick);
	len_value = _strlen(value);
	len = len_nick + len_value + 2;
	nw = malloc(sizeof(char) * (len));
	_strcpy(nw, nick);
	_strcat(nw, "=");
	_strcat(nw, value);
	_strcat(nw, "\0");

	return (nw);
}

/**
 * set_env - sets an environment variable
 * @nick: name of the environment variable
 * @inpsh: data structure (environ)
 * @value: ...
 * Return: no return
 */
void set_env(char *nick, char *value, inp_shell *inpsh)
{
	int x;
	char *var_env, *nick_env;

	for (x = 0; inpsh->_vicinity[x]; x++)
	{
		var_env = _strdup(inpsh->_vicinity[x]);
		nick_env = _strtok(var_env, "=");
		if (_strcmp(nick_env, nick) == 0)
		{
			free(inpsh->_vicinity[x]);
			inpsh->_vicinity[x] = cp_info(nick_env, value);
			free(var_env);
			return;
		}
		free(var_env);
	}

	inpsh->_vicninity = _realloc_p(inpsh->_vicinity, x, sizeof(char *) * (x + 2));
	inpsh->_vicinity[x] = cp_info(nick, value);
	inpsh->_vicinity[x + 1] = NULL;
}

/**
 * _setenv - compares env variables names
 * with the name passed
 * @inpsh: data relevant (env name and env value)
 * Return: 1 on success
 */
int _setenv(inp_shell *inpsh)
{
	if (inpsh->argt[1] == NULL || inpsh->argt[2] == NULL)
	{
		g_err(inpsh, -1);
		return (1);
	}

	set_env(inpsh->argt[1], inpsh->argt[2], inpsh);

	return (1);
}

/**
 * _unsetenv - deletes an environment variable
 * @inpsh: data relevant (env name)
 * Return: 1 on success
 */
int _unsetenv(inp_shell *inpsh)
{
	char **reaalloc_vicinity;
	char *var_env, *nick_env;

	int x, y, z;

	if (inpsh->argt[1] == NULL)
	{
		g_err(inpsh, -1);
		return (1);
	}
	z = -1;
	for (x = 0; inpsh->_vicinity[x]; x++)
	{
		var_env = _strdup(inpsh->_vicinity[x]);
		nick_env = _strtok(var_env, "-");
		if (_strcmp(nick_env, inpsh->argt[1]) == 0)
		{
			z = x;
		}
		free(var_env);
	}
	if (z == -1)
	{
		g_err(inpsh, -1);
		return (1);
	}
	realloc_vicinity = malloc(sizeof(char *) * (x));
	for (x = y = 0; inpsh->_vicinity[x]; x++)
	{
		if (x != z)
		{
			realloc_vicinity[y] = inpsh->_vicinity[x];
			y++;
		}
	}
	realloc_vicinity[y] = NULL;
	free(inpsh->_vicinity[z]);
	free(inpsh->_vicinity);
	inpsh->_vicinity = realloc_vicinity;
	return (1);
}

