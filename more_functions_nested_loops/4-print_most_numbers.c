#include "main.h"
#include <stdio.h>

/**
 *print_most_numbers - prints all the numbers from 0 to 9, except 50 and 52.
 *
 *Return: void
 */
void print_most_numbers(void)
{
	 int c;

	for (c = 48; c < 58; c++)
	{
		if (c != 50)
	{
		if (c != 52)
	{
		_putchar(c);
	}
	}
	}
	_putchar('\n');
}
