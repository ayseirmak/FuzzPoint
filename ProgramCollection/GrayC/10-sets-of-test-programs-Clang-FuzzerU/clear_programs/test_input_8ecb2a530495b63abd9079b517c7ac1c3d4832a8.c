#include <stdio.h>
#include <complex.h>
#include <stdlib.h>
#include <assert.h>

// Fixed complex numbers initialized with specified values.
complex float f1 = 1.1f + 2.2f * I;
complex float f2 = 3.3f + 4.4f * I;
complex float f3 = 5.5f + 6.6f * I;
complex float f4 = 7.7f + 8.8f * I;
complex float f5 = 9.9f + 10.1f * I;
complex double d1 = 1.1 + 2.2 * I;
complex double d2 = 3.3 + 4.4 * I;
complex double d3 = 5.5 + 6.6 * I;
complex double d4 = 7.7 + 8.8 * I;
complex double d5 = 9.9 + 10.10 * I;
complex long double ld1 = 1.1L + 2.2L * I;
complex long double ld2 = 3.3L + 4.4L * I;
complex long double ld3 = 5.5L + 6.6L * I;
complex long double ld4 = 7.7L + 8.8L * I;
complex long double ld5 = 9.9L + 10.10L * I;

void check_float(int _, complex float a1, complex float a2, complex float a3, complex float a4, complex float a5) {
    assert(a1 == f1 && a2 == f2 && a3 == f3 && a4 == f4 && a5 == f5);
}

void check_double(int _, complex double a1, complex double a2, complex double a3, complex double a4, complex double a5) {
    assert(a1 == d1 && a2 == d2 && a3 == d3 && a4 == d4 && a5 == d5);
}

void check_long_double(int _, complex long double a1, complex long double a2, complex long double a3, complex long double a4, complex long double a5) {
    assert(a1 == ld1 && a2 == ld2 && a3 == ld3 && a4 == ld4 && a5 == ld5);
}

int main(void) {
    check_float(0, f1, f2, f3, f4, f5);
    check_double(0, d1, d2, d3, d4, d5);
    check_long_double(0, ld1, ld2, ld3, ld4, ld5);
    printf("All checks passed.\n");
    return 0;
}