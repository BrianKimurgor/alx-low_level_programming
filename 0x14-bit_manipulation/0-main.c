#include "main.h"

/**
 * binary_to_uint - converts a binary number to an unsigned int.
 * @b: binary.
 *
 * Return: unsigned int.
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int ui = 0;

	if (!b)
		return (0);

	for (; *b; b++)
	{
		if (*b == '0' || *b == '1')
		{
			ui = ui * 2 + (*b - '0');
		}
		else
		{
			return (0);
		}
	}

	return (ui);
}

