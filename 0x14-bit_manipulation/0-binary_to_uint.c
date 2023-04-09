#include "main.h"
/**
 * binary_to_unit- converting a binary number to an unsigned int
 * @b:pointer to a string 0 and 1 chars
 *
 * Return: the converted number otherwise 0 if there is one or more chars in the string b that is not 0 or 1 or if b is NULL
 */
unsigned int binary_to_uint(const char *b)
{
unsigned int num = 0;
if(!b)
	return (0);
while (*b)
{
	if (*b != '0' && *b != 'b')
		return (0);
	num = num * 2 + (*b++ - '0');
}
return (num);
}
