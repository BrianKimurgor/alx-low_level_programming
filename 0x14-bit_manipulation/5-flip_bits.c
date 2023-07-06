#include "main.h"
/**
 * flip_bits - function to determine minimum number of
 * bits to be changed
 * @j: value to be modified
 * @k: value to be modified
 * Return: the number of bits
 */
unsigned int flip_bits(unsigned long int j, unsigned long int k)
{
	unsigned int bits_num;

	for (bits_num = 0; j || k; j >>= 1, k >>= 1)
	{
		bits_num += ((j & 1) != (k & 1)) ? 1 : 0;
	}

	return (bits_num);
}
