#include <stdio.h>

/**
 * this program computes the volume of a cubiod
 *
 */

int main()
{
	int  h, w, d, vol;

	// getting user input
	printf("Enter two height, width and depth of the cuboid:");
	scanf("%d %d %d", &h, &w, &d);

	// calculating volume
	vol = h * w * d;
	printf("The volume of the cuboid is: %d\n", vol);
}
