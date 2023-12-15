#include "search_algos.h"

/**
 * binary_search - Searches for a value in a sorted integer array
 *                 using the binary search algorithm.
 * @arr: A pointer to the first element of the sorted array.
 * @size: The number of elements in the array.
 * @val: The value to search for.
 *
 * Return: If the value is not present or the array is NULL, return -1.
 *         Otherwise, return the index where the value is located.
 */
int binary_search(int *arr, size_t size, int val)
{
	size_t index, left, right;

	/* Check if the array is NULL */
	if (arr == NULL)
		return (-1);

	/* Perform binary search */
	for (left = 0, right = size - 1; right >= left;)
	{
		printf("Searching in array: ");
		for (index = left; index < right; index++)
			printf("%d, ", arr[index]);
		printf("%d\n", arr[index]);

		/* Calculate the middle index */
		index = left + (right - left) / 2;

		/* If the middle element is the value */
		if (arr[index] == val)
			/* Return the index */
			return (index);

		/* If the middle element is greater than the value */
		if (arr[index] > val)
			/* Update the right boundary */
			right = index - 1;
		else
			/* Otherwise, update the left boundary */
			left = index + 1;
	}
	/* Value not found, return -1 */
	return (-1);
}
