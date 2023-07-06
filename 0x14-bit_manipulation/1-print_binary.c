#include "main.h"
/**
 * print_binary - prints binary representation of a number
 * @n: the number to print in the binary
 */
void print_binary(unsigned long int n)
{
	(n > 1) ? print_binary(n >> 1) : _putchar('0' + (n & 1));
}
