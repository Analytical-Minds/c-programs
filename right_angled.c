#include <stdio.h>
#include <stdlib.h>

/**
 * this program asks for two angles and checks 
 * for a right-angled property.
 * return:0 (success).
 */

int main()
{
	int angle1, angle2; //variables to hold angles provided by user
	printf("Enter two angles in degrees to check for a right angled property:");
	scanf("%d %d", &angle1, &angle2); //prompt user for inputs

	//check for valid angles (greater than zero and less than 90)
	if (angle1 <= 0 || angle2 <= 0 || angle1 >= 90 || angle2 >= 90) {
		printf("Invalid input. Angles must be positive and less than 90\n");
	}
	//check if the sum of angles equal 90 degrees
	else if ((angle1 + angle2) == 90) {
		printf("The triangle is a right-angled triangle\n");
	}
	else {
		printf("The triangle is not a right-angled triangle\n");
	}

	return 0; //exit program
}
