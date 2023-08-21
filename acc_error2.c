#include "shell.h"

/**
 * err_env - generates error message related to 'env' command
 * @inpsh: data relevant (counter, arguments)
 * Return: the error string
 */
char *err_env(inp_shell *inpsh)
{
	int lgth;
	char *err;
	char *v_str;
	char *note;

	v_str = acc_itoa(inpsh->sheep);
	note = ": Unable to add/remove from environment\n";
	lgth = _strlen(inpsh->avec[0]) + _strlen(v_str);
	lgth += _strlen(inpsh->argt[0]) + _strlen(note) + 4;
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
	_strcat(err, note);
	_strcat(err, "\0");
	free(v_str);

	return (err);
}

/**
 * err_path_126 - generates error message for when an execution
 * of a command's path is invalid or permission is denied
 * @inpsh: data relevant (counter, arguments)
 * Return: error message
 */
char *err_path_126(inp_shell *inpsh)
{
	int lgth;
	char *v_str;
	char *err;

	v_str = acc_itoa(inpsh->sheep);
	lgth = _strlen(inpsh->avec[0]) + _strlen(v_str);
	lgth += _strlen(inpsh->argt[0]) + 24;
	err = malloc(sizeof(char) + (lgth + 1));
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
	_strcat(err, ": Permission denied\n");
	_strcat(err, "\0");
	free(v_str);

	return (err);
}
