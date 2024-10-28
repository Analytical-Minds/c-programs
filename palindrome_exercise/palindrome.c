#include "palindrome.h"

/**
 * this program checks for palindromicity
 *
 */

int main()
{
	regex_t regex; //stores compiled regex
	int regres; //stores returned value from regex function
	char user_input[100]; // array to hold user input
	char test_num[100]; // array to hold validated user input

	// compile regular expression
	regres = regcomp(&regex, "^[0-9]+(\\.[0-9]+)?$", REG_EXTENDED);

	// regres holds 1 if regcomp failed and 0 if otherwise.
	if(regres) {
		fprintf(stderr, "Could not compile regex\n");
		return 1;
	}

	int valid_input = 0; // initialize code for valid input

	// request user input for validation
	while(!valid_input) {
		printf("Enter a number to check if it is a palindrome:");
		fgets(user_input, sizeof(user_input), stdin); // Use fgets to read input

		// remove newline character if present
		size_t len = strlen(user_input);
		if (len > 0 && user_input[len - 1] == '\n') {
			user_input[len - 1] = '\0'; // Replace newline with null terminator
		}

		// validate input using regex
		regres = regexec(&regex, user_input, 0, NULL, 0);
		if (regres != 0) {
			char errbuf[100];
			regerror(regres, &regex, errbuf, sizeof(errbuf));
			printf("That is not a number: %s\n", errbuf); //print error message
		}
		else {
			printf("Match found\n");

			// clean user input if it contains a decimal point
			char *decimal_pos = strchr(user_input, '.');
                        if (decimal_pos) {
				// copy characters before decimal
				size_t  integer_part_len = decimal_pos - user_input;
				strncpy(test_num, user_input, integer_part_len);

				// copy characters after decimal
				strcpy(test_num +  integer_part_len, decimal_pos + 1);
			}
			else {
				strcpy(test_num, user_input); //copy the string
			}

			printf("This is now the test num: %s\n", test_num);
			valid_input = 1; // terminate loop
		}
	}

	// Save original cleaned string before reversing for palindrome comparison
	char original_test_num[100];
	strcpy(original_test_num, test_num);

	// reverse test_num and compare it to original_test_num
	reverse_string(test_num);
	if (strcmp(original_test_num, test_num) == 0) {
		printf("%s is a palindrome\n", original_test_num);
	} else {
		printf("%s is not a palindrome\n", original_test_num);
	}

	// free memory allocated to the regex pattern buffer
	regfree(&regex);

	return 0;
}
