#include <stdio.h>
#include "std_types.h"

void main (void) {
	u8 input[1000];
	u8 output[1000];
	u16 i, last;
	printf("Please enter string: ");
	scanf("%s", input);
	output[0] = input[0];
	last = 0;
	for (i=1; input[i]!='\0'; i++) {
		if (input[i] != output[last]) {
			output[++last] = input[i];
		}
	}
	output[++last] = '\0';
	printf("Output is %s\n", output);
	printf("Deletions = %d", i-last);
}
