
#include <stdio.h>

char			get_bit			(unsigned int num, char bit);
unsigned int	set_bit			(unsigned int num, char bit);
unsigned int	clr_bit			(unsigned int num, char bit);
unsigned int	toggle_bit		(unsigned int num, char bit);

char			get_ones		(unsigned int num);
char			get_max_ones	(unsigned int num);
char			get_first_one	(unsigned int num);
char			get_last_one	(unsigned int num);
unsigned int	rotate_bits		(unsigned int num);
unsigned int	flip_bits		(unsigned int num);

void			print_binary	(unsigned int num);


int main (void) {
	
	unsigned int operation, input_num, input_bit, result;
	
	while (1) {
		char exit = 0;
		char invalid_operation = 0;
		char invalid_bit = 0;
		
		/* Taking input from the user */
		printf("----------------------------------\n");
		printf("Please choose operation\n");
		printf("(0) Clear Bit\n");
		printf("(1) Set Bit\n");
		printf("(2) Toggle Bit\n");
		printf("(3) Get Bit\n");
		printf("(4) Rotate Bits\n");
		printf("(5) Flip Bits\n");
		printf("(6) Number of Ones\n");
		printf("(7) Max Number of Consecutive Ones\n");
		printf("(8) First Position of One\n");
		printf("(9) Last Position of One\n");
		printf("(10) Exit the application\n");
		
		printf("Operation is: ");
		scanf("%d", &operation);
		
		switch (operation) {
			/* Operations 0:3 take number and bit */
			case 0: case 1: case 2: case 3:
				printf("Please enter the number and the bit position: ");
				scanf("%d %d", &input_num, &input_bit);
				if (input_bit > 31) {
					invalid_bit = 1;
				}
				break;
			/* Operations 4:9 take number only */
			case 4: case 5: case 6: case 7: case 8: case 9:
				printf("Please enter the number: ");
				scanf("%d", &input_num);
				break;
			/* Operation 10 means terminating the program */
			case 10:
				exit = 1;
				break;
			/* Any other value for operation is invalid */
			default:
				invalid_operation = 1;
				break;
		}
		/* If exit flag is 1, break from the loop */
		if (exit){
			break;
		}
		/* If operation or bit is invalid, print to the user */
		else if (invalid_operation) {
			printf("You entered invalid operation.\n");
			printf("Operation range is [0,10].\n");

		}
		else if (invalid_bit) {
			printf("You entered invalid bit.\n");
			printf("Bits range is [0,31].\n");
		}
		/* Calculating output */
		else {
			printf("Input in decimal is: %d\n", input_num);
			printf("Input in binary is: ");
			print_binary(input_num);
			
			switch (operation) {
				case 0:
					result = clr_bit(input_num, input_bit);
					printf("Output in decimal is: %d\n", result);
					printf("Output in binary is: ");
					print_binary(result);
					break;
				case 1:
					result = set_bit(input_num, input_bit);
					printf("Output in decimal is: %d\n", result);
					printf("Output in binary is: ");
					print_binary(result);
					break;
				case 2:
					result = toggle_bit(input_num, input_bit);
					printf("Output in decimal is: %d\n", result);
					printf("Output in binary is: ");
					print_binary(result);
					break;
				case 3:
					result = get_bit(input_num, input_bit);
					printf("Bit value is: %d\n", result);
					break;
				case 4:
					result = rotate_bits(input_num);
					printf("Output in decimal is: %d\n", result);
					printf("Output in binary is: ");
					print_binary(result);
					break;
				case 5:
					result = flip_bits(input_num);
					printf("Output in decimal is: %d\n", result);
					printf("Output in binary is: ");
					print_binary(result);
					break;
				case 6:
					result = get_ones(input_num);
					printf("Number of ones is : %d\n", result);
					break;
				case 7:
					result = get_max_ones(input_num);
					printf("Max number of ones is : %d\n", result);
					break;
				case 8:
					result = get_first_one(input_num);
					if (result == -1) {
						printf("The number does not contain ones\n");
					}
					else {
						printf("First position of 1 is : %d\n", result);
					}
					break;
				case 9:
					result = get_last_one(input_num);
					if (result == -1) {
						printf("The number does not contain ones\n");
					}
					else {
						printf("Last position of 1 is : %d\n", result);
					}
					break;
				default:
					break;
			}
		}
	}
}