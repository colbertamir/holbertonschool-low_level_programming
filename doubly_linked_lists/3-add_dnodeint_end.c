#include "lists.h"

/**
 * add_dnodeint_end - Adds new node at the end of dlistint_t list
 * @h: Head of the list
 * @n: The integer for the new node
 *
 * Return: If the function fails return NULL
 * Otherwise - The address of new node
 */
dlistint_t *add_dnodeint_end(dlistint_t **h, const int n)
{
	dlistint_t *new, *last;

	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);

	new->n = n;
	new->next = NULL;

	if (*h == NULL)
	{
		new->prev = NULL;
		*h = new;
		return (new);
	}

	last = *h;
	while (last->next != NULL)
		last = last->next;

	last->next = new;
	new->prev = last;

	return (new);
}

