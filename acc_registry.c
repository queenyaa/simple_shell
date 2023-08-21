#include "shell.h"

/**
 * free_strlin_list - frees the memory allocated for strlin_list
 * linked list
 * @head: head of the linked list
 * Return: address of the head
 */
void free_strlin_list(strlin_list **head)
{
	strlin_list *tmp;
	strlin_list *bind;

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
 * add_dim_tail - function adds a new node to the end of the strlin_list
 * linked list to store command lines
 * @head: head of the linked list
 * @seam: command line
 * Return: address of the head
 */
strlin_list *add_dim_tail(strlin_list **head, char *seam)
{
	strlin_list *nw, *tmp;

	nw = malloc(sizeof(strlin_list));
	if (nw == NULL)
		return (NULL);

	nw->seam = seam;
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

/**
 * free_sig_list - function to free memory allocated for the sig_list
 * linked list
 * @head: head of the linked list
 * Return: address of the head
 */
void free_sig_list(sig_list **head)
{
	sig_list *tmp;
	sig_list *bind;

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
 * add_sig_tail - function to add a new node to the end of the sig_list
 * linked list to store separators found in the user unput
 * @head: head of the linked list
 * @sig: separator found (; | &)
 * Return: address of the head
 */
sig_list *add_sig_tail(sig_list **head, char sig)
{
	sig_list *nw, *tmp;

	nw = malloc(sizeof(sig_list));
	if (nw == NULL)
		return (NULL);

	nw->signal = sig;
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
