#include "hash_tables.h"
#include <stdlib.h>
#include <string.h>

/**
 * hash_table_set - Add or update an element in the hash table
 * @ht: Pointer to hash table
 * @key: The key to add - string can't be empty
 * @value: The value associated with the key
 *
 * Return: Upon failure return zero, otherwise return one
 *
 * Description: Adds or updates an element in the hash table
 * In case of collision, new nodes are added to the beginning of the list
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	if (ht == NULL || key == NULL || *key == '\0')
		return (0);

	unsigned long int index = key_index((const unsigned char *)key, ht->size);
	hash_node_t *new_node = malloc(sizeof(hash_node_t));

		if (new_node == NULL)
		return (0);

	char *new_value = (value != NULL) ? strdup(value) : NULL;

	if (value != NULL && new_value == NULL)
	{
		free(new_node);
		return (0);
	}

	char *new_key = strdup(key);

	if (new_key == NULL)
	{
		free(new_value);
		free(new_node);
		return (0);
	}

	new_node->key = new_key;
	new_node->value = new_value;
	new_node->next = NULL;

	if (ht->array[index] != NULL)
	{
		new_node->next = ht->array[index];
	}

	ht->array[index] = new_node;

	return (1);
}

