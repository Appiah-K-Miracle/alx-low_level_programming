#include "lists.h"

/**
 * delete_dnodeint_at_index - deletes the node at index of a
 * dlistint_t linked list
 *
 * @head: head of the list
 * @index: index of the new node
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *node1;
	dlistint_t *node2;
	unsigned int counter;

	node1 = *head;

	if (node1 != NULL)
		while (node1->prev != NULL)
			node1 = node1->prev;

	counter = 0;

	while (node1 != NULL)
	{
		if (counter == index)
		{
			if (counter == 0)
			{
				*head = node1->next;
				if (*head != NULL)
					(*head)->prev = NULL;
			}
			else
			{
				node2->next = node1->next;

				if (node1->next != NULL)
					node1->next->prev = node2;
			}

			free(node1);
			return (1);
		}
		node2 = node1;
		node1 = node1->next;
		counter++;
	}

	return (-1);
}
