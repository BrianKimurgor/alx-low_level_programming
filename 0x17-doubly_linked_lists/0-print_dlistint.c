#include "lists.h"

/**
 * print_dlistint - Prints all the elements of a doubly linked list.
 * @h: Pointer to the head of the list.
 * Return: The number of nodes in the list.
 */
size_t print_dlistint(const dlistint_t *h)
{
	int count = o;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
		count += 1;
	}
	return (count);
}
