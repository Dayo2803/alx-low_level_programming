#include "hash_tables.h"

/**
 * create_node - Creates a new node
 * @key: the key
 * @value: the value of the node
 * Return: the new node
 */

hash_node_t *create_node(const char *key, const char *value)
{
	hash_node_t *newly_created_node;

	newly_created_node = malloc(sizeof(hash_node_t));
	if (newly_created_node == NULL)
		return (NULL);
	newly_created_node->key = strdup(key);
	if (newly_created_node->key == NULL)
	{
		free(newly_created_node);
		return (NULL);
	}
	newly_created_node->value = strdup(value);
	if (newly_created_node->value == NULL)
	{
		free(newly_created_node->key);
		free(newly_created_node);
		return (NULL);
	}
	newly_created_node->next = NULL;
	return (newly_created_node);
}

/**
 * hash_table_set - add the new node
 * @ht: is the hash table you want to add or update the key/value to
 * @key: key
 * @value: value
 * Return: success or fail
 */

int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *current_node, *newly_created_node;
	unsigned long int index;
	char *newvalue;

	if (ht == NULL || ht->array == NULL || ht->size == 0
			|| key == NULL || strlen(key) == 0 || value == NULL)
		return (0);
	index = key_index((const unsigned char *)key, ht->size);
	current_node = ht->array[index];

	while (current_node != NULL)
	{
		if (strcmp(current_node->key, key) == 0)
		{
			newvalue = strdup(value);
			if (newvalue == NULL)
				return (0);
			free(current_node->value);
			current_node->value = newvalue;
			return (1);
		}
		current_node = current_node->next;
	}
	newly_created_node = create_node(key, value);
	if (newly_created_node == NULL)
		return (0);
	newly_created_node->next = ht->array[index];
	ht->array[index] = newly_created_node;
	return (1);
}
