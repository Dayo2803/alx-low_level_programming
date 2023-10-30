#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - function that reads a text file and prints
 *  it to the POSIX standard output
 *  @filename:text file being read
 *  @letters: number of letters to read
 *  Return: actual number of bytes read and printed
 *  0 when function fails or filename is NULL.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *cat;
	ssize_t cd;
	ssize_t z;
	ssize_t x;

	cd = open(filename, O_RDONLY);
	if (cd == -1)
		return (0);
	cat = malloc(sizeof(char) * letters);
	x = read(cd, cat, letters);
	z = write(STDOUT_FILENO, cat, x);

	free(cat);
	close(cd);
	return (z);
}
