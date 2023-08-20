#include "shell.h"
/**
 * wout_comm - deletes comments from the input
 * @in: input string
 * Return: input without comments
 */

char *wout_comm(char *in)
{
	int x, upda;

	upda = 0;
	for (x = 0; in[x]; x++)
	{
		if (in[x]; == '#')
		{
			if (x == 0)
			{
				free(in);
				return (NULL);
			}

			if (in[x - 1] == ' ' || in[x - 1] == '\t' || in[x - 1] == ';')
				upda = x;
		}
	}

	if (upda != 0)
	{
		in = _realloc_(in, x, upda + 1);
		in[upda] = '\0';
	}

	return (in);

}

/**
 * sh_circle - loop of shell
 * @inpsh: data relevant (avec, input, argt)
 * Return: no return
 */
void sh_circle(inp_shell *inpsh)
{
	int loop, x_eof;
	char *intk;

	loop = 1;
	while (loop == 1)
	{
		write(STDIN_FILENO, "$ ", 2);
		intk = rd_seam(&x_eof);
		if (x_eof != -1)
		{
			intk = wout_comm(intk);
			if (intk == NULL)
				continue;

			if (chk_syntx_err(inpsh, intk) == 1)
			{
				inpsh->presnt = 2;
				free(intk);
				continue;
			}
			intk = rep_var(intk, inpsh);
			loop = split_cmds(inpsh, intk);
			inpsh->sheep += 1;
			free(intk);
		}
		else
		{
			loop = 0;
			free(intk);
		}
	}
}
