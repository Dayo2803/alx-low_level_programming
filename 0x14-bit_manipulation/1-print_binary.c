#include "main.h"

/**
 * print_binary - prints binary equivalent of a decimal number
 * @n: number to print binary
 */
void print_binary(unsigned long int n)
{
	int x, count = 0;
	unsigned long int saving;

	for (x = 63; x >= 0; x--)
	{
		saving = n >> x;

		if (saving & 1)
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
