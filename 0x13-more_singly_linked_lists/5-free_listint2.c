#include "lists.h"

/**
 * free_listint2 - frees a linked list
 * @head: pointer to the listint_t list to be freed
 */
void free_listint2(listint_t **head)
{
	listint_t *prom;

	if (head == NULL)
		return;

	while (*head)
	{
		prom = (*head)->next;
		free(*head);
		*head = prom;
	}

	*head = NULL;
}
