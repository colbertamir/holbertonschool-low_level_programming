#include "hash_tables.h"

/**
 * hash_table_print - Print key/values of the hash table in order
 * @ht: Pointer to hash table
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int idx = 0;
	hash_node_t *node;
	int printed = 0;

	if (!ht || !ht->array)
		return;

	printf("{");
	while (idx < ht->size)
	{
		node = ((ht->array)[idx]);
		while (node)
		{
			if (printed)
				printf(", ");
			printf("'%s': '%s'", node->key, node->value);
			printed = 1;
			node = node->next;
		}
		idx++;
	}
	printf("}\n");
}

