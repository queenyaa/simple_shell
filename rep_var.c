#include "shell.h"

/**
 * chk_env - checks if typed variable is an env variable
 * @h: head of linked list
 * @in: input string
 * @inp: data structure
 * Return: none
 */
void chk_env(d_var **h, char *in, inp_shell *inp)
{
	int ror, chat, y, lval;
	char **_vicin;

	_vicin = inp->_vicinity;
	for (ror = 0; _vicin[ror]; ror++)
	{
		for (y = 1, chat = 0; _vicin[chat][chat]; chat++)
		{
			if (_vicin[ror][chat] == '=')
			{
				lval = _strlen(_vicin[ror] + chat + 1);
				add_dvar_n(h, y, _vicin[ror] + chat + 1, lval);
				return;
			}

			if (in[y] == _vicin[ror][chat])
				y++;
			else
				break;
		}
	}

	for (y = 0; in[y]; y++)
	{
		if (in[y] == ' ' || in[y] == '\t' || in[y] == ';' || in[y] == '\n')
			break;
	}

	add_dvar_n(h, y, NULL, 0);
}

/**
 * chk_vars - check if the typed variable is $$ or $?
 * @h: head of the linked list
 * @in: input string
 * @st: last status of the shell
 * @inp: data structure
 * Return: none
 */
int chk_vars(d_var **h, char *in, char *st, inp_shell *inp)
{
	int x, nxt, lpd;

	nxt = _strlen(st);
	lpd = _strlen(inp->pid);

	for (x = 0; in[x]; x++)
	{
		if (in[x] == '$')
		{
			if (in[x + 1] == '?')
				add_dvar_n(h, 2, st, nxt), x++;
			else if (in[x + 1] == '$')
				add_dvar_n(h, 2, inp->pid, lpd), x++;
			else if (in[x + 1] == '\n')
				add_dvar_n(h, 0, NULL, 0);
			else if (in[x + 1] == '\0')
				add_dvar_n(h, 0, NULL, 0);
			else if (in[x + 1] == ' ')
				add_dvar_n(h, 0, NULL, 0);
			else if (in[x + 1] == '\t')
				add_dvar_n(h, 0, NULL, 0);
			else if (in[x + 1] == ';')
				add_dvar_n(h, 0, NULL, 0);
			else
				chk_env(h, in + x, inp);
		}
	}

	return (x);
}

/**
 *  repl_intk - replaces string into variables
 *  @head: head of the linked list
 *  @intk: input string
 *  @n_intk: new input string (replaced)
 *  @nlen: new length
 *  Return: replaced string
 */
char *repl_intk(d_var **head, char *intk, char *n_intk, int nlen)
{
	d_var *catal;
	int x, y, z;

	catal = *head;
	for (y = x = 0; x < nlen; x++)
	{
		if (intk[y] == '$')
		{
			if (!(catal->dim_var) && !(catal->dim_wght))
			{
				n_intk[x] = intk[y];
				y++;
			}
			else if (catal->dim_var && !(catal->dim_wght))
			{
				for (z = 0; z < catal->dim_var; z++)
					y++;
				x--;
			}
			else
			{
				for (z = 0; z < catal->dim_wght; z++)
				{
					n_intk[x] = catal->wght[z];
					x++;
				}
				y += (catal->dim_var);
				x--;
			}
			catal = catal->fward;
		}
		else
		{
			n_intk[x] = intk[y];
			y++;
		}
	}

	return (n_intk);
}

/**
 * rep_var - calls functions to replace string into vars
 * @intk: input string
 * @inpsh: data structure
 * Return: replaced string
 */
char *rep_var(char *intk, inp_shell *inpsh)
{
	d_var *head, *catal;
	char *presnt, *n_intk;
	int olen, nlen;

	presnt = acc_itoa(inpsh->presnt);
	head = NULL;

	olen = chk_vars(&head, intk, presnt, inpsh);

	if (head == NULL)
	{
		free(presnt);
		return (intk);
	}

	ctaal = head;
	nlen = 0;

	while (catal != NULL)
	{
		nlen += (catal->dim_wght - catal->dim_var);
		catal = catal->fward;
	}

	nlen += olen;

	n_intk = malloc(sizeof(char) * (nlen + 1));
	n_intk[nlen] = '\0';

	n_intk = repl_intk(&head, intk, n_intk, nlen);

	free(intk);
	free(presnt);
	free_dvar_list(&head);

	return (n_intk);
}
