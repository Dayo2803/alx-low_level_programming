#include "main.h"

/**
 * create_file - Creates file.
 * @filename: A pointer to the name of file to create.
 * @text_content: A pointer to a string to write to file.
 *
 * Return: If function fails - -1.
 *         Otherwise - 1.
 */
int create_file(const char *filename, char *text_content)
{
	int cd, z, len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}

	cd = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	z = write(cd, text_content, len);

	if (cd == -1 || z == -1)
		return (-1);

	close(cd);

	return (1);
}
