#include "lists.h"

/**
 * get_dnodeint_at_index - Returns the nth node of dlistint_t list
 * @head: The head ofthe list
 * @index: The index of the node, starting from zero
 * Return: If the node does not exist return NULL
 * Otherwise - The address of the node
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	while (head != NULL && index > 0)
	{
		head = head->next;
		index--;
	}

	return (index == 0 ? head : NULL);
}

