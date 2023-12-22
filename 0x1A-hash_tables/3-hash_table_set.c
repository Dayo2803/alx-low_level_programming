#include "hash_tables.h"

/**
 * create_node - Creates a new node
 * @key: the key
 * @value: the value of the node
 * Return: the new node
 */

hash_node_t *create_node(const char *key, const char *value)
{
	hash_node_t *new_node = malloc(sizeof(hash_node_t));

	if (!new_node)
		return (NULL);
	new_node->key = strdup(key);
	new_node->value = strdup(value);
	new_node->next = NULL;

	return (new_node);
}

/**
 * hash_table_set - adds nodes to the hash table
 * @ht: the hash table
 * @key: the key
 * @value: the value of the node
 * Return: 0 or 1
 */

int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
}
