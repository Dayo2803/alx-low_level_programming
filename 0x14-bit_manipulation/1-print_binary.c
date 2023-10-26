#include "main.h"

/**
 * print_binary - Write a function that prints the
 *  binary representation of a number
 *  @n: number to print binary
 */
void print_binary(unsigned long int n)
{
	int m, count = 0;
	unsigned long int debt;

	for (m = 63; m >= 0; m--)
	{
		debt = n >> m;

		if (debt & 1)
		{
			_putchar('1');
			count++;
		}
		else if (count)
			_putchar('0');
	}
	if (!count)
		_putchar('0');
}
