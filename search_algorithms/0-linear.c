#include "search_algos.h"

/**
 * linear_search - Locates a specific value in an array
 *                 of integers using linear search.
 * @array: A pointer to the first element of the array to search.
 * @arr_size: The number of elements in the array.
 * @target: The value to locate.
 *
 * Return: If the value isn't found or the array is NULL, return -1.
 *         Otherwise, return the index where the value is found.
 */
int linear_search(int *array, size_t arr_size, int target)
{
	size_t index;

	/* Check if the array is NULL */
	if (array == NULL)
		return (-1);

	/* Iterate over each element in the array */
	for (index = 0; index < arr_size; index++)
	{
		/* Print the currently checked value */
		printf("Value checked array[%ld] = [%d]\n", index, array[index]);

		/* If the value is found */
		if (array[index] == target)
			/* Return the index of the found value */
			return (index);
	}

	/* Value not found, return -1 */
	return (-1);
}
