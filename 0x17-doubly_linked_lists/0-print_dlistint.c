#include "lists.h"

/**
 * print_dlistint - Prints all the elements of a doubly linked list.
 * @h: Pointer to the head of the list.
 * Return: The number of nodes in the list.
 */
size_t print_dlistint(const dlistint_t *h)
{
    const dlistint_t *current = h; /* Start from the head of the list */
    size_t count = 0; /* Initialize the count of nodes */

    /* Traverse the list and print each element */
    while (current != NULL)
    {
        printf("%d\n", current->n);
        current = current->next;
        count++;
    }

    return count; /* Return the number of nodes */
}

