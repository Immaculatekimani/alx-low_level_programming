#include "main.h"

/**
 * read_textfile - reads a text file and prints it to standard output
 * @filename:the name of the file
 * @letters:the number of letters
 * Return: if success return number of letter, else return 0
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	int fil;
	char *stor;
	ssize_t content, output;

	if (filename == NULL)
		return (0);

	fil = open(filename, O_RDONLY);
	if (fil == -1)
		return (0);

	stor = malloc(sizeof(char) * letters + 1);
	if (stor == NULL)
		return (0);

	content = read(fil, stor, letters);
	if (content == -1)
		return (0);

	stor[letters + 1] = '\0';
	close(fil);

	output = write(STDOUT_FILENO, stor, content);
	if (output == -1)
		return (0);

	free(stor);

	return (content);
}
