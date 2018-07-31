#include "complex.h"

complex * mult(complex *a, complex *b) {
	complex *result = malloc(sizeof(complex));
	result->re = (a->re * b->re) - (a->im * b->im);
	result->im = (a->re * b->im) + (a->im * b->re);
	return result;
}

complex * add(complex *a, complex *b) {
	complex *result = malloc(sizeof(complex));
	result->re = a->re + b->re;
	result->im = a->im + b->im;
	return result;
}

complex * dot(complex *a, complex *b) {
	complex * result = malloc(sizeof(complex));
	result->re = a->re * b->re;
	result->im = a->im * b->im;
	return result;
}

//note: we must have 0 <= k < n
//use negative n for fft
complex * unity(int n, int k) {
	complex *result = malloc(sizeof(complex));
	result->re = cos(2 * M_PI * ((double) k / n));
	result->im = sin(2 * M_PI * ((double) k / n));
	return result;
}
