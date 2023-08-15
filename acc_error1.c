#include "shell.h"

/**
 * err_g_cd - generates an error message specific to 'cd' command
 * @inpsh: ...
 * Return: ...
 */
char *err_g_cd(inp_shell *inpsh)
{
	int lgth, lgth_id;
	char *err, *v_str, *note;

	v_str = acc_itoa(inpsh->sheep);
	if (inpsh->argt[1][0] == '-')
	{
		not = ": Illegal option ";
		lgth_id = 2;
	}
	else
	{
		note = ": can't cd to ";
		lgth_id = _strlen(inpsh->argt[1]);
	}

	lgth = _strlen(inpsh->avec[0]) + _strlen(inpsh->argt[0]);
	lgth += _strlen(v_str) + _strlen(note) + lgth_id + 5;
	err = malloc(sizeof(char) * (lgth + 1));

	if (err == 0)
	{
		free(v_str);
		return (NULL);
	}
	err = strcat_cd(inpsh, note, err, v_str);

	free(v_str);

	return (err);
}

/**
 * err_nfound - generates a generic error message when command is not found
 * inpsh: ...
 * Return: ...
 */
char *err_nfound(inp_shell *inpsh)
{
	int lgth;
	char *err;
	char *v_str;

	v_str = acc_itoa(inpsh->sheep);
	lgth = _strlen(inpsh->avec[0]) + _strlen(v_str);
	lgth += _strlen(inpsh->argt[0]) + 16;
	err = malloc(sizeof(char) * (lgth + 1));
	if (err == 0)
	{
		free(err);
		free(v_str);
		return (NULL);
	}
	_strcpy(err, inpsh->avec[0]);
	_strcat(err, ": ");
	_strcat(err, v_str);
	_strcat(err, ": ");
	_strcat(err, inpsh->argt[0]);
	_strcat(err, ": not found\n");
	_strcat(err, "\0");
	free(v_str);

	return (err);
}
