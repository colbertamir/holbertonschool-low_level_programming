#include "search_algos.h"

/**
 * linear_search - Locates a specific value in an array
 *                 of integers using linear search.
 * @arr: A pointer to the first element of the array to search.
 * @arr_size: The number of elements in the array.
 * @target: The value to locate.
 *
 * Return: If the value isn't found or the array is NULL, return -1.
 *         Otherwise, return the index where the value is found.
 */
int linear_search(int *arr, size_t arr_size, int target)
{
	size_t index;

	/* Check if the array is NULL */
	if (arr == NULL)
		return (-1);

	/* Iterate over each element in the array */
	for (index = 0; index < arr_size; index++)
	{
		/* Print the currently checked value */
		printf("Value checked arr[%ld] = [%d]\n", index, arr[index]);

		/* If the value is found */
		if (arr[index] == target)
			/* Return the index of the found value */
			return (index);
	}

	/* Value not found, return -1 */
	return (-1);
}
