#include "shell.h"

/**
 * free_dvar_list - function to free the memory allocated for
 * d_var linked list
 * @head: ...
 * Return: ...
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
