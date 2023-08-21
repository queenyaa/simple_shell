#include "shell.h"

/**
 * free_dvar_list - function to free the memory allocated for
 * d_var linked list
 * @head: head of the linked list
 * Return: none
 */
void free_dvar_list(d_var **head)
{
	d_var *tmp;
	d_var *bind;

	if (head != NULL)
	{
		bind = *head;
		while ((tmp = bind) != NULL)
		{
			bind = bind->fward;
			free(tmp);
		}
		*head = NULL;
	}
}

/**
 * add_dvar_n - function to add a new node to the end of 'd_var' linked
 * list to store info about replacement variables
 * @head: head of the linked list
 * @dvar: d something
 * @wght: idk
 * @dwght: idk
 * Return: address of the head
 */
d_var *add_dvar_n(d_var **head, int dvar, char *wght, int dwght)
{
	d_var *nw, *tmp;

	nw = malloc(sizeof(d_var));
	if (nw == NULL)
		return (NULL);

	nw->dim_var = dvar;
	nw->wght = wght;
	nw->dim_wght = dwght;

	nw->fward = NULL;
	tmp = *head;

	if (tmp == NULL)
		*head = nw;

	else
	{
		while (tmp->fward != NULL)
			tmp = tmp->fward;
		tmp->fward = nw;
	}
	return (*head);
}
