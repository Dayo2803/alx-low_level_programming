#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_buffer(char *file);
void close_file(int cd);

/**
 * create_buffer - Allocates 1024 bytes for a buffer.
 * @file: The name of the file buffer is storing chars for.
 *
 * Return: A pointer to the newly-allocated buffer.
 */
char *create_buffer(char *file)
{
	char *cat;

	cat = malloc(sizeof(char) * 1024);

	if (cat == NULL)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", file);
		exit(99);
	}

	return (cat);
}

/**
 * close_file - Closes file descriptors.
 * @cd: The file descriptor to be closed.
 */
void close_file(int cd)
{
	int s;

	s = close(cd);

	if (s == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close cd %d\n", cd);
		exit(100);
	}
}

/**
 * main - Copies the contents of a file to another file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: If the argument count is incorrect - exit code 97.
 * If file_from does not exist or cannot be read - exit code 98.
 * If file_to cannot be created or written to - exit code 99.
 * If file_to or file_from cannot be closed - exit code 100.
 */
int main(int argc, char *argv[])
{
	int go, to, v, z;
	char *cat;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	cat = create_buffer(argv[2]);
	go = open(argv[1], O_RDONLY);
	v = read(go, cat, 1024);
	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (go == -1 || v == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", argv[1]);
			free(cat);
			exit(98);
		}

		z = write(to, cat, v);
		if (to == -1 || z == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", argv[2]);
			free(cat);
			exit(99);
		}

		v = read(go, cat, 1024);
		to = open(argv[2], O_WRONLY | O_APPEND);

	} while (v > 0);

	free(cat);
	close_file(go);
	close_file(to);

	return (0);
}
