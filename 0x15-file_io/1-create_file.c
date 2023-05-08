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
 * create_file - creates a file
 * @filename: name of file
 * @text_content: text
 * Return: 1 - success, -1 error
 */

int create_file(const char *filename, char *text_content)
{
	int fil;
	unsigned int leng;
	ssize_t content;

	if (filename == NULL)
		return (-1);
	fil = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (fil == -1)
		return (-1);

	if (text_content == NULL)
	{
		leng = 0;
		text_content = "";
	}
	else
		leng = _strlen(text_content);

	content = write(fil, text_content, leng);
	if (content == -1)
		return (-1);
	close(fil);
	return (1);
}
