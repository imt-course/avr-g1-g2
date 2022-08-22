#include <stdio.h>
#include "std_types.h"
#include "complex.h"

void main (void) {
	Complex n1, n2;
	Result res;
	printf("Please enter number 1: ");
	scanf("%f %f", &(n1.x), &(n1.y));
	printf("Please enter number 2: ");
	scanf("%f %f", &(n2.x), &(n2.y));
	res = calculateComplex(&n1, &n2);
	printf ("Sum = %.2f  %+.2fi\n", res.sum.x, res.sum.y);
	printf ("Diff = %.2f  %+.2fi\n", res.diff.x, res.diff.y);
	printf ("Mul = %.2f  %+.2fi\n", res.mul.x, res.mul.y);
	printf ("Div = %.2f  %+.2fi\n", res.div.x, res.div.y);
}