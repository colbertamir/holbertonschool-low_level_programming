#include "lists.h"

/**
 * free_dlistint - Frees dlistint_t list
 * @h: Head of the list
 * Return: Nada
 */
void free_dlistint(dlistint_t *h)
{
	if (h == NULL)
		return;

	while (h->next)
	{
		h = h->next;
		free(h->prev);
	}
	free(h);
}

