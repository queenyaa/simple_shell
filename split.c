#include "shell.h"
/**
 * chng_char - swaps | and & for non-printed chars
 * @intk: input string
 * @bool: type of swap
 * Return: swapped string
 */
char *chng_char(char *intk, int bool)
{
	int x;

	if (bool == 0)
	{
		for (x = 0; intk[x]; x++)
		{
			if (intk[x] == '|')
			{
				if (intk[x + 1] != '|')
					intk[x] = 16;
				else
					x++;
			}
		}

		if (intk[x] == '&')
		{
			if (intk[x + 1] != '&')
				intk[x] = 12;
			else
				x++;
		}
	}
	else
	{
		for (x = 0; intk[x]; x++)
		{
			intk[x] = (intk[x] == 16 ? '|' : intk[x]);
			intk[x] = (intk[x] == 12 ? '&' : intk[x]);
		}
	}
	return (intk);
}

/**
 * add_nodes - add separators and comman lines in the lists
 * @head_s: head of separator list
 * @head_l: head of command lines list
 * @intk: input string
 * Return: none
 */
void add_nodes(sig_list **head_s, strlin_list **head_l, char *intk)
{
	int x;
	char *seam;

	intk = chng_char(intk, 0);

	for (x = 0; intk[x]; x++)
	{
		if (intk[x] == ';')
			add_sig_tail(head_s, intk[x]);

		if (intk[x] == '|' || intk[x] == '&')
		{
			add_sig_tail(head_s, intk[x]);
			x++;
		}
	}

	seam = _strtok(intk, ";|&");
	do {
		seam = chng_char(seam, 1);
		add_dim_tail(head_l, seam);
		seam = _strtok(NULL, ";|&");
	} while (seam != NULL);
}
/**
 * go_next - go to the next command line stored
 * @tilt_s: separator list
 * @tilt_l: command line list
 * @inpsh:data structure
 * Return: no return
 */
void go_next(sig_list **tilt_s, strlin_list **tilt_l, inp_shell *inpsh)
{
	int loop_sig;
	sig_list *tl_s;
	strlin_list *ti_l;

	loop_sig = 1;
	tl_s = *tilt_s;
	tl_l = *tilt_l;

	while (tl_s != NULL && loop_sig)
	{
		if (inpsh->presnt == 0)
		{
			if (tl_s->signal == '&' || tl_s->signal == ';')
				loop_sig = 0;
			if (tl_s->signal == '|')
				tl_l = tl_l->fward, tl_s = tl_s->fward;
		}
		else
		{
			if (tl_s->signal == '|' || tl_s->signal == ';')
				loop_sig = 0;
			if (tl_s->signal == '&')
				tl_l = tl_l->fward, tl_s = tl_s->fward;
		}
		if (tl_s != NULL && !loop_sig)
			tl_s = tl_s->fward;
	}

	*tilt_s = tl_s;
	*tilt_l = tl_l;
}
/**
 * split_cmds - splits command lines accorgind to
 * the separators ;, | and &, and executes them
 * @inpsh: data structure
 * @intk: input string
 * Return: 0 to exit, 1 to continue
 */

int split_cmds(inp_shell *inpsh, char *intk)
{
	sig_list *head_s, *tilt_s;
	strlin_list *head_l, *tilt_l;
	int loop;

	head_s = NULL;
	head_l = NULL;

	add_nodes(&head_s, &head_l, intk);

	tilt_s = head_s;
	tilt_l = head_l;

	while (tilt_l != NULL)
	{
		inpsh->intk = tilt_l->seam;
		inpsh->argt = split_seam(inpsh->intk);
		loop = exec_line(inpsh);
		free(inpsh->argt);

		if (loop == 0)
			break;

		go_next(&tilt_s, &tilt_l, inpsh);

		if (tilt_l != NULL)
			tilt_l = tilt_l->fward;
	}

	free_sig_list(&head_s);
	free_strlin_list(&head_l);

	if (loop == 0)
		return (0);
	return (1);
}

/**
 * split_seam - tokenizes the input string
 * @intk: input string
 * Return: string splitted
 */
char **split_seam(char *intk)
{
	size_t bsz;
	size_t x;
	char **parsings;
	char *parsing;

	bsz = PAR_LOAD;
	parsings = malloc(sizeof(char *) * (bsz));
	if (parsings == NULL)
	{
		write(STDERR_FILENO, ": allocation error\n", 18);
		exit(EXIT_FAILURE);
	}

	parsing = _strtok(intk, PAR_SHORT);
	parsings[0] = parsing;

	for (x = 1; parsing != NULL; x++)
	{
		if (x == bsz)
		{
			bsz += PAR_LOAD;
			parsings = _realloc_p(parsings, x, sizeof(char *) * bsz);
			if (parsings == NULL)
			{
				write(STDERR_FILENO, ": allocation error\n", 18);
				exit(EXIT_FAILURE);
			}
		}
		parsing = _strtok(NULL, PAR_SHORT);
		parsings[x] = parsing;
	}

	return (parsings);
}
