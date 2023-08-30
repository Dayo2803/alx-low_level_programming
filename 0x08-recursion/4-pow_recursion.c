#include "main.h"
/**
 * _pow_recursion - function that returns the value
 * of x raised to the power of y
 * @x: value to raise
 * @y: power
 * Return: result of the power
 */
int _pow_recursion(int x, int y)
{
	int result = x;

	if (y < 0)
		return (-1);

	else if (y == 0)
		return (1);

	result *= _pow_recursion(x, y - 1);

	return (result);
}
