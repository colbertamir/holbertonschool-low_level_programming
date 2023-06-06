#include "main.h"
#include <stdio.h>

/**
 * _atoi - converts a string to an integer
 * @s: string to be converted
 *
 * Return: the int converted from the string
 */
int _atoi(char *s)
{
	int i, d, n, len;

	i = 0;
	d = 0;
	n = 0;
	len = strlen(s);

	if (s[0] == '-')
	{
		d = 1;
	}

	for (i = d; i < len; i++)
	{
		if (isdigit(s[i]))
		{
			digit = s[i] - '0';
			if (d % 2)
			{
				digit = -digit;
			}
			n = n * 10 + digit;
		}
		else
		{
			break;
		}
	}

	return (n);
}
