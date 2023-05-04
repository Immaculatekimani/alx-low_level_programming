#include "main.h"

/**
 * flip_bits - returns the number of bits to flip number to another
 * @n: first integer
 * @m: second integer
 * Return: number of bits to change (integer)
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned int sum;
	unsigned long int chek;

	sum = 0;
	chek = n ^ m;
	while (chek)
	{
		sum += chek & 1;
		chek = chek >> 1;
	}
	return (sum);
}
