#include "shell.h"

/**
 * _which_ - function to locate the command in the system's PATH
 * @cmd: command name
 * @_vicinity: environmental variable
 * Return: Location of the command executable, 'NULL' if not found
 */
char *_which_(char *cmd, char **_vicinity)
{
	char *road, *ptr_road, *token_road, *dir;
	int len_dir, len_cmd, x;
	struct stat st;

	road = _getenv("PATH", _vicinity);
	if (road)
	{
		ptr_road = _strdup(road);
		len_cmd = _strlen(cmd);
		token_road = _strtok(ptr_road, ":");
		x = 0;
		while (token_road != NULL)
		{
			if (_cdir(road, &x))
				if (stat(cmd, &st) == 0)
					return (cmd);
			len_dir = _strlen(token_road);
			dir = malloc(len_dir + len_cmd + 2);
			_strcpy(dir, token_road);
			_strcat(dir, "/");
			_strcat(dir, cmd);
			_strcat(dir, "\0");
			if (stat(dir, &st) == 0)
			{
				free(ptr_road);
				return (dir);
			}
			free(dir);
			token_road = _strtok(NULL, ":");
		}
		free(ptr_road);
		if (stat(cmd, &st) == 0)
			return (cmd);
		return (NULL);
	}
	if (cmd[0] == '/')
		if (stat(cmd, &st) == 0)
			return (cmd);
	return (NULL);
}

/**
 * _cdir - function to check if a c ':' exists in the currently
 * directory path
 * @road: pointer to the directory path
 * @x: pointer to an index
 * Return: 1 if a ':' is found, '0' otherwise
 */
int _cdir(char *road, int *x)
{
	if (road[*x] == ':')
		return (1);
	while (road[*x] != ':' && road[*x])
		*x += 1;

	if (road[*x])
		*x += 1;

	return (0);
}

/**
 * chk_err_cmd - function to verify if the user has permissions to access
 * the cmd
 * @dir: directory path to the command
 * @inpsh: pointer to the data structure
 * Return: 1 if there is an error, 0 if not
 */
int chk_err_cmd(char *dir, inp_shell *inpsh)
{
	if (dir == NULL)
	{
		g_err(inpsh, 127);
		return (1);
	}
	if (_strcmp(inpsh->argt[0], dir) != 0)
	{
		if (access(dir, X_OK) == -1)
		{
			g_err(inpsh, 126);
			free(dir);
			return (1);
		}
		free(dir);
	}
	else
	{
		if (access(inpsh->argt[0], X_OK) == -1)
		{
			g_err(inpsh, 126);
			return (1);
		}
	}
	return (0);
}

/**
 * _exe_ - function to determine if a command is executable
 * @inpsh: pointer to the data structure
 * Return: -1 for permission error, 0 if not executable
 */
int _exe_(inp_shell *inpsh)
{
	struct stat st;
	int x;
	char *intk;

	intk = inpsh->argt[0];
	for (x = 0; intk[x]; x++)
	{
		if (intk[x] == '.')
		{
			if (intk[x + 1] == '.')
				return (0);
			if (intk[x + 1] == '/')
				continue;
			else
				break;
		}
		else if (intk[x] == '/' && x != 0)
		{
			if (intk[x + 1] == '.')
				continue;
			x++;
			break;
		}
		else
			break;
	}
	if (x == 0)
		return (0);

	if (stat(intk + x, &st) == 0)
		return (x);

	g_err(inpsh, 127);
	return (-1);
}

/**
 * cmd_execut - function to execute command lines by forking a new
 * process and executing the dired command
 * @inpsh: pointer to the data structure (contains
 * command arguments and input)
 * Return: 1 on success
 */
int cmd_execut(inp_shell *inpsh)
{
	pid_t pd;
	pid_t wpd;
	int state, exec;
	char *dir;
	(void) wpd;

	exec = _exe_(inpsh);
	if (exec == -1)
		return (1);
	if (exec == 0)
	{
		dir = _which_(inpsh->argt[0], inpsh->_vicinity);
		if (chk_err_cmd(dir, inpsh) == 1)
			return (1);
	}
	pd = fork();
	if (pd == 0)
	{
		if (exec == 0)
			dir = _which_(inpsh->argt[0], inpsh->_vicinity);
		else
			dir = inpsh->argt[0];
		execve(dir + exec, inpsh->argt, inpsh->_vicinity);
	}
	else if (pd < 0)
	{
		perror(inpsh->avec[0]);
		return (1);
	}
	else
	{
		do {
			wpd = waitpid(pd, &state, WUNTRACED);
		} while (!WIFEXITED(state) && !WIFSIGNALED(state));
	}

	inpsh->presnt = state / 256;
	return (1);
}
