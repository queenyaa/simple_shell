#include "shell.h"

/**
 * _realloc_p - function to reallocate memory for an array of pointers
 * @ptr: ...
 * @o_sz: ...
 * @n_sz: ...
 *
 * Return: ...
 */
char **_realloc_p(char **ptr, unsigned int o_sz, unsigned int n_sz)
{
	char **n_ptr;
	unsigned int x;

	if (ptr == NULL)
		return (malloc(sizeof(char *) * n_sz));

	if (n_sz == o_sz)
		return (ptr);

	n_ptr = malloc(sizeof(char *) * n_sz);
	if (n_ptr == NULL)
		return (NULL);

	for (x = 0; x < o_sz; x++)
		n_ptr[x] = ptr[x];

	free(ptr);

	return (n_ptr);
}

/**
 * _realloc_ - function that reallocates memory for a given block of memory
 * @ptr: ...
 * @o_sz: ...
 * @n_sz: ...
 * Return: ...
 */
void *_realloc_(void *ptr, unsigned int o_sz, unsigned int n_sz)
{
	void *n_ptr;

	if (ptr == NULL)
		return (malloc(n_sz));

	if (n_sz == 0)
	{
		free(ptr);
		return (NULL);
	}
	if (n_sz == o_sz)
		return (ptr);

	n_ptr = malloc(n_sz);
	if (n_ptr == NULL)
		return (NULL);

	if (n_sz < o_sz)
		_memcpy(n_ptr, ptr, n_sz);
	else
		_memcpy(n_ptr, ptr, o_sz);

	free(ptr);
	return (n_ptr);
}

/**
 * _memcpy - performs a memory copy between two void pointers
 * @n_ptr: ...
 * @ptr: ...
 * @sz: ...
 * Return: ...
 */
void _memcpy(void *n_ptr, const void *ptr, unsigned int sz)
{
	char *char_ptr = (char *)ptr;
	char *char_n_ptr = (char *)n_ptr;
	unsigned int x;

	for (x = 0; x < sz; x++)
		char_n_ptr[x] = char_ptr[x];
}
