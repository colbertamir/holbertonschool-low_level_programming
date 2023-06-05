#include "main.h"

/**
 * _isupper - uppercase character
 * # will check for uppercase character
 * @c: Variable text
 * Return: 1 if uppercase, 0 otherwise.
 */

static int _isupper(const int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	else
		return (0);
}
