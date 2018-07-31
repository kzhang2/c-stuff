#include <math.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct {
	double re, im;
} complex;

complex * mult(complex *a, complex *b);
complex * add(complex *a, complex *b);
complex * unity(int n, int k);
complex * dot(complex *a, complex *b);
