#include "lists.h"

/**
 * add_nodeint_end - adds a node at the end of a linked list
 * @head: pointer to the first element in the list
 * @n: data to insert in the new element
 *
 * Return: pointer to the new node, or NULL if it fails
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *meow;
	listint_t *prom = *head;

	meow = malloc(sizeof(listint_t));
	if (!meow)
		return (NULL);

	meow->n = n;
	meow->next = NULL;

	if (*head == NULL)
	{
		*head = meow;
		return (meow);
	}

	while (prom->next)
		prom = prom->next;

	prom->next = meow;

	return (meow);
}
