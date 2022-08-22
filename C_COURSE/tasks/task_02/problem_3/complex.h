

#ifndef COMPLEX_H_
#define COMPLEX_H_

typedef struct {
	f32 x;
	f32 y;
} Complex;

typedef struct {
	Complex sum;
	Complex diff;
	Complex mul;
	Complex div;
} Result;

Result calculateComplex (Complex *n1, Complex *n2);

#endif