#include <stdio.h>

/**
 * this program computes the sum of two numbers
 *
 */

int main()
{
	int  a, b, sum;

	// getting user input
	printf("Enter two numbers to be added:");
	scanf("%d %d", &a, &b);

	// calculating sum
	sum = a + b;
	printf("%d + %d = %d\n", a, b, sum);
	return 0; // return the integer value in the sum
}
