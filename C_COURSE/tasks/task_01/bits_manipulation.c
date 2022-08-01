#include <stdio.h>

char get_bit (unsigned int num, char bit) {
	return ((num>>bit) & 1);
}

unsigned int set_bit (unsigned int num, char bit) {
	num |= (1<<bit);
	return num;
}

unsigned int clr_bit (unsigned int num, char bit) {
	num &= ~(1<<bit);
	return num;
}

unsigned int toggle_bit (unsigned int num, char bit) {
	num ^= (1<<bit);
	return num;
}

unsigned int rotate_bits (unsigned int num) {
	unsigned int result = 0;
	for (int i = 0; i < 32; i++) {
		int bit = (num>>i) & 1;
		result |= bit<<(31-i);
	}
	return result;
}

unsigned int flip_bits (unsigned int num) {
	return (~num);
}

char get_ones (unsigned int num) {
	char result = 0;
	while (num != 0) {
		if ((num&1) == 1) {
			result++;
		}
		num >>= 1;
	}
	return result;
}


char get_max_ones (unsigned int num) {
	char result = 0;
	while (num != 0) {
		num &= num<<1;
		result++;
	}
}

char get_first_one (unsigned int num) {
	char result = -1;
	int i;
	if (num != 0) {
		for (i=0; i<32; i++) {
			if (((num>>i)&1) == 1) {
				result = i;
				break;
			}
		}
	}
	return result;
}

char get_last_one (unsigned int num) {
	char result = -1;
	int i;
	if (num != 0) {
		for (i=31; i>0; i--) {
			if (((num>>i)&1) == 1) {
				result = i;
				break;
			}
			num >>= 1;
		}
	}
	return result;
}

void print_binary (unsigned int num) {
	int i, counter = 0;
	for (i=31; i>=0; i--) {
		int bit = (num>>i) & 1;
		printf("%d", bit);
		counter ++;
		
		if (counter == 4) {
			printf(" "); /*Print space between every 4 bits*/
			counter = 0;
		}
	}
	printf("\n");
}

