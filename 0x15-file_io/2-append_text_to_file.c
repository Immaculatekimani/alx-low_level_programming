#include "main.h"

/**
 * _strlen - returns length of string
 * @s: string
 * Return: length of string
 */

int _strlen(char *s)
{
	int len = 0;

	while (s[len] != '\0')
	{
		len++;
	}

	return (len);
}


/**
 * append_text_to_file - appends a text at the end of a file
 * @filename: name of file
 * @text_content: text
 * Return: 1 - success, -1 error
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int fil;
	unsigned int leng;
	ssize_t content;

	if (filename == NULL)
		return (-1);
	if (text_content == NULL)
		return (1);
	fil = open(filename, O_WRONLY | O_APPEND);
	if (fil == -1)
		return (-1);
	leng = _strlen(text_content);

	content = write(fil, text_content, leng);
	if (content == -1)
		return (-1);
	close(fil);
	return (1);
}
