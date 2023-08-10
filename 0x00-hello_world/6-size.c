#include <stdio.h>
/**
 * main - Entry point
 * Return: 0
 */
int main(void)
{
	char v;
	int w;
	long int x;
	long long int y;
	float z;

printf("Size of a char: %lu byte(s)\n", (unsigned long)sizeof(v));
printf("Size of a int: %lu byte(s)\n", (unsigned long)sizeof(w));
printf("Size of a long int: %lu byte(s)\n", (unsigned long)sizeof(x));
printf("Size of a long long int: %lu byte(s)\n", (unsigned long)sizeof(y));
printf("Size of a float: %lu byte(s)\n", (unsigned long)sizeof(z));
return (0);
}
