#include <stdlib.h>
#include <time.h>
#include <stdio.h>
/**
 *  * main - Entry point
 *   * Return: Always return 0 (Success) 
 */
int main(void)
{
	int n;
	int b;

	srand(time(0));
	n = rand() - RAND_MAX / 2;
	b = n % 10;

	if (a > 5)
	{
		printf("Last digit of %d is %d and is greater than 5\n", n, b);
	}
	else if (a == 0)
	{
		printf("Last digit of %d is %d and os 0\n", n, b);
	}
	else
	{
		printf("Last digit of %d is %d and is less than 6\n", n, b);
	}
	return (0);
}
