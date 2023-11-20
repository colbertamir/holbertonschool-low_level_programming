#include "hash_tables.h"
#include <stdlib.h>
#include <string.h>

/* Function prototypes */
hash_node_t *create_new_node(const char *key, const char *value);
int update_value(hash_node_t *current, const char *value);

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
	unsigned long int index;
	hash_node_t *current;
	hash_node_t *new_node;

	if (ht == NULL || key == NULL || *key == '\0')
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	current = ht->array[index];

	while (current != NULL)
	{
		if (strcmp(current->key, key) == 0)
			return (update_value(current, value));

		current = current->next;
	}

	new_node = create_new_node(key, value);

	if (new_node == NULL)
		return (0);

	new_node->next = ht->array[index];
	ht->array[index] = new_node;

	return (1);
}

/**
 * create_new_node - Creates a new node for the hash table
 * @key: The key to add
 * @value: The value associated with the key
 *
 * Return: Pointer to the new node created
 *
 * Description: Allocates memory for new node, assigns key and value,
 * and initializes the next pointer to NULL
 */
hash_node_t *create_new_node(const char *key, const char *value)
{
	hash_node_t *new_node = malloc(sizeof(hash_node_t));
	char *new_value;

	if (new_node == NULL)
		return (NULL);

	new_node->key = strdup(key);
	if (new_node->key == NULL)
	{
		free(new_node);
		return (NULL);
	}

	new_value = (value != NULL) ? strdup(value) : NULL;
	if (value != NULL && new_value == NULL)
	{
		free(new_node->key);
		free(new_node);
		return (NULL);
	}

	new_node->value = new_value;
	new_node->next = NULL;

	return (new_node);
}

/**
 * update_value - Updates the value of an existing key in the hash table
 * @current: Pointer to the node whose value is updating
 * @value: The new value to be updated
 *
 * Return: Upon success return one, otherwise return zero
 *
 * Description: Updates the value of an existing key in hash table
 * by assigning a new value to the corresponding node
 */
int update_value(hash_node_t *current, const char *value)
{
	char *new_value = (value != NULL) ? strdup(value) : NULL;

	if (new_value == NULL)
		return (0);

	free(current->value);
	current->value = new_value;

	return (1);
}

