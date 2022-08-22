#include <stdio.h>
#include "std_types.h"

void main (void) {
	u8 str[1000];
	u16 i;
	printf("Please enter string: ");
	scanf("%[^\n]%*c", str);
	for (i=0; str[i]!='\0'; i++) {
		switch(str[i]) {
			case 'A': case 'a':
				str[i] = '4';
				break;
			case 'B': case 'b':
				str[i] = '8';
				break;
			case 'E': case 'e':
				str[i] = '3';
				break;
			case 'I': case 'i':
				str[i] = '1';
				break;
			case 'O': case 'o':
				str[i] = '0';
				break;
			case 'S': case 's':
				str[i] = '5';
				break;
			default:
				if ((str[i] >= 'a') && (str[i] <= 'z')) {
					str[i] -= 32;
				}
				break;
		}
	}
	printf("Output is: %s!!!!!", str);
}
