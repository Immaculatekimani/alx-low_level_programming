/**
 * get_endianness - Gets the endianness
 *
 * Return: 1 if little endian, 0 if big endian
 */
int get_endianness(void)
{
	int s;
	char *t;

	t = (char *)&s;
	return (*t + 48);
}
