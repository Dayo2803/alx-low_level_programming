#include "main.h"

/**
 * get_bit - returns value of bit at an index in decimal number
 * @n: number to search
 * @index: index of bit
 *  Return: value of bit
 */
int get_bit(unsigned long int n, unsigned int index)
{
	int dune;

	if (index > 63)
		return (-1);

	dune = (n >> index) & 1;

	return (dune);
}
