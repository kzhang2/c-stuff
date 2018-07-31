#include <stdlib.h>
#include <stdio.h>
#include "complex.h"

complex * fft(complex *p, int size, int inv);
complex * invFft(complex *p, int size);

int main(int argc, char *argv[]) {
	int sz = 4;
	complex *test = malloc(sz * sizeof(complex));
	complex a = {10.0, 0.0};
	complex b = {-2.0, 2.0};
	complex c = {-2.0, 0.0};
	complex d = {-2.0, -2.0};
	test[0] = a;
	test[1] = b;
	test[2] = c;
	test[3] = d;
	complex *test1 = invFft(test, sz);
	for (int i = 0; i < sz; i++) {
		printf("%f, %f\n", test1[i].re, test1[i].im);
	}
}

//note: size must be power of 2, inv must be either 1 or -1
complex * fft(complex *p, int size, int inv) {
	if (size == 1) {
		return p;
	}
	complex *result = malloc(size * sizeof(complex));
	complex *evens = malloc((size / 2) * sizeof(complex));
	complex *odds = malloc((size / 2) * sizeof(complex));
	for (int i = 0; i < size; i++) {
		if (i % 2 == 0) {
			evens[i / 2] = p[i];
		} else {
			odds[i / 2] = p[i];
		}
	}
	evens = fft(evens, size / 2, inv);
	odds = fft(odds, size / 2, inv);
	for (int i = 0; i < size / 2; i++) {
		complex *u = unity(-1 * size * inv, i);
		complex n = {-1.0, 0.0};
		result[i] = *add(&evens[i], mult(&odds[i], u));
		result[i + (size / 2)] = *add(&evens[i], mult(&n, mult(&odds[i], u)));
	}
	return result;
}

complex * invFft(complex *p, int size) {
	complex *result = fft(p, size, -1);
	complex scale = {1.0 / size, 1.0 / size};
	for (int i = 0; i < size; i++) {
		result[i] = *dot(&result[i], &scale);
	}
	return result;
}
