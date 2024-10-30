#include "palindrome.h"

/**
 * reverse_string(char *str) - this function reverses any string given as input
 *
 * str - string variable to be reversed.
 */

void reverse_string(char *str) {
	int n = strlen(str);
	int start = 0; //index of string beginning
	int end = n - 1; //index of string end
	char tmp; //temporary memory to store a value

	//swap characters from start and end until they meet in the middle
	while (start < end) {
		tmp = str[start]; //store character at index start temporarily
		str[start] = str[end]; //change value at start index to end value
		str[end] = tmp; //swap end value and temp value
		start++; //shift and index forward
		end--; //shift an index backward
	}
}
