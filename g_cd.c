#include "shell.h"
/**
 * cd_dt - changes to parent directory
 * @inpsh: relevant data (environ)
 * Return: none
 */
void cd_dt(inp_shell *inpsh)
{
	char pwd[PATH_MAX];
	char *dir, *cp_pwd, *cp_strtok_pwd;

	getcwd(pwd, sizeof(pwd));
	cp_pwd = _strdup(pwd);
	set_env("OLDPWD", cp_pwd, inpsh);
	dir = inpsh->argt[1];
	if (_strcmp(".", dir) == 0)
	{
		set_env("PWD", cp_pwd, inpsh);
		free(cp_pwd);
		return;
	}
	if (_strcmp("/", cp_pwd) == 0)
	{
		free(cp_pwd);
		return;
	}
	cp_strtok_pwd = cp_pwd;
	rv_string(cp_strtok_pwd);
	cp_strtok_pwd = _strtok(cp_strtok_pwd, "/");
	if (cp_strtok_pwd != NULL)
	{
		cp_strtok_pwd = _ strtok(NULL, "\0");

		if (cp_strtok_pwd != NULL)
			rv_string(cp_strtok_pwd);
	}
	if (cp_strtok_pwd != NULL)
	{
		chdir(cp_strtok_pwd);
		set_env("PWD", cp_strtok_pwd, inpsh);
	}
	else
	{
		chdir("/");
		set_env("PWD", "/", inpsh);
	}
	inpsh->presnt = 0;
	free(cp_pwd);
}

/**
 * cd_to - changes to a a user defined directory
 * @inpsh: data relevant (directories)
 * Return: none
 */
void cd_to(inp_shell *inpsh)
{
	char pwd[PATH_MAX];
	char *dir, *cp_pwd, *cp_dir;

	getcwd(pwd, sizeof(pwd));

	dir = inpsh->argt[1];
	if (chdir(dir) == -1)
	{
		g_err(inpsh, 2);
		return;
	}

	cp_pwd = _strdup(dir);
	set_env("OLDPWD", cp_pwd, inpsh);

	cp_dir = _strdup(dir);
	set_env("PWD", cp_dir, inpsh);

	free(cp_pwd);
	free(cp_dir);

	inpsh->presnt = 0;

	chdir(dir);
}

/**
 * cd_previous - changes to the previous directory
 * @inpsh: data relevant (environ)
 * Return: none
 */
void cd_previous(inp_shell *inpsh)
{
	char pwd[PATH_MAX];
	char *p_pwd, *p_oldpwd, *cp_pwd, *cp_oldpwd;

	getcwd(pwd, sizeof(pwd));
	cp_pwd = _strdup(pwd);

	p_oldpwd = _getenv("OLDPWD", inpsh->_vicinity);

	if (p_oldpwd == NULL)
		cp_oldpwd = cp_pwd;
	else
		cp_oldpwd = _strdup(p_oldpwd);

	set_env("OLDPWD", cp_pwd, inpsh);

	if (chdir(cp_oldpwd) == -1)
		set_env("PWD", cp_pwd, inpsh);
	else
		set_env("PWD", cp_oldpwd, inpsh);

	p_pwd = _getenv("PWD", inpsh->_vicinity);

	write(STDOUT_FILENO, p_pwd, _strlen(p_pwd));
	write(STDOUT_FILENO, "\n", 1);

	free(cp_pwd);
	if (p_oldpwd)
		free(cp_oldpwd);

	inpsh->presnt = 0;

	chdir(p_pwd);
}

/**
 * cd_to_home - changed to home directory
 * @inpsh: data relevant (environ)
 * Return: no return
 */
void cd_to_home(inp_shell *inpsh)
{
	char *p_pwd, *home;
	char pwd[PATH_MAX];

	getcwd(pwd, sizeof(pwd));
	p_pwd = _strdup(pwd);

	home = _getenv("HOME", inpsh->_vicinity);

	if (home == NULL)
	{
		set_env("OLDPWD", p_pwd, inpsh);
		free(p_pwd);
		return;
	}

	if (chdir(home) == -1)
	{
		g_err(inpsh, 2);
		free(p_pwd);
		return;
	}

	set_env("OLDPWD", p_pwd, inpsh);
	set_env("PWD", home, inpsh);
	free(p_pwd);
	inpsh->presnt = 0;
}
