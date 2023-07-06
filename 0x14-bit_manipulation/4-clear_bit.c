#include "main.h"
/**
 * clear_bit - sets the value of a bit to 0 at a given index
 * @n: pointer to the number to set the bit in
 * @index: index of the bit to set
 *
 * Return: 1 if it worked, -1 if an error occured
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	return (index > (sizeof(*n) * 8) ? -1 : (*n &= ~(1UL << index), 1));
}
