#include "hash_tables.h"

/**
 * key_index - Grabs index at which a key/value pair should
 *		be stored in the array of the hash table
 *
 * @key: The key to get the index of
 * @size: The size of the array
 *
 * Return: The index of the key
 * Description: Uses djb2 algorithm
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int hash_value = hash_djb2(key);

	return (hash_value % size);
}

