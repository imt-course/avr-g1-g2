#include <stdio.h>
#include "std_types.h"
#include "complex.h"

Result calculateComplex (Complex *n1, Complex *n2) {
	Result res;
	
	res.sum.x = n1->x + n2->x;
	res.sum.y = n1->y + n2->y;
	
	res.diff.x = n1->x - n2->x;
	res.diff.y = n1->y - n2->y;
	
	res.mul.x = (n1->x * n2->x) - (n1->y * n2->y);
	res.mul.y = (n1->x * n2->y) + (n2->x * n1->y);

	res.div.x = ((n1->x * n2->x) + (n1->y * n2->y))
			  / ((n2->x * n2->x) + (n2->y * n2->y));
	res.div.y = ((n2->x * n1->y) - (n1->x * n2->y))
			  / ((n2->x * n2->x) + (n2->y * n2->y));

	return res;
}
