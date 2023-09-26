#include "lists.h"

/**
 * insert_nodeint_at_index - inserts a new node in a linked list,
 * at a given position
 * @head: pointer to the first node in the list
 * @idx: index where the new node is added
 * @n: data to insert in the new node
 *
 * Return: pointer to the new node, or NULL
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	unsigned int x;
	listint_t *meow;
	listint_t *prom = *head;

	meow = malloc(sizeof(listint_t));
	if (!meow || !head)
		return (NULL);

	meow->n = n;
	meow->next = NULL;

	if (idx == 0)
	{
		meow->next = *head;
		*head = meow;
		return (meow);
	}

	for (x = 0; prom && x < idx; x++)
	{
		if (x == idx - 1)
		{
			meow->next = prom->next;
			prom->next = meow;
			return (meow);
		}
		else
			prom = prom->next;
	}

	return (NULL);
}
