#include <stdio.h>
#include "lists.h"

/**
 * print_dlistint - Prints every element of dlistint_t list.
 * @h: The head of dlistint_t list.
 *
 * Return: The number of nodes in list.
 */
size_t print_dlistint(const dlistint_t *h)
{
    size_t nodes = 0;

    while (h)
    {
        nodes++;
        printf("%d\n", h->n);
        h = h->next;
    }

    return (nodes);
}

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    dlistint_t *head;
    dlistint_t *new;
    dlistint_t hello = {8, NULL, NULL};
    size_t n;

    head = &hello;
    new = malloc(sizeof(dlistint_t));
    if (new == NULL)
    {
        dprintf(2, "Error: Can't malloc\n");
        return (EXIT_FAILURE);
    }
    new->n = 9;
    head->prev = new;
    new->next = head;
    new->prev = NULL;
    head = new;
    n = print_dlistint(head);
    printf("-> %lu elements\n", n);
    free(new);
    return (EXIT_SUCCESS);
}
