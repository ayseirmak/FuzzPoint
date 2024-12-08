#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#include <string.h>
#include <stdarg.h>

volatile float complex f1 = 1.1f + 2.2f*I;
volatile float complex f2 = 3.3f + 4.3f*I;
volatile float complex f3 = 5.5f + 6.6f*I;
volatile float complex f4 = 7.7f + 8.8f*I;
volatile float complex f5 = 7.7f + 8.8f*I;

volatile double complex d1 = 1.1 + 2.2*I;
volatile double complex d2 = 3.3 + 4.4*I;
volatile double complex d3 = 5.5 + 6.6*I;
volatile double complex d4 = 7.7 + 8.8*I;
volatile double complex d5 = 9.9 + 10.1*I;

volatile long double complex ld1 = 1.1L + 2.2L*I;
volatile long double complex ld2 = 3.3L + 4.4L*I;
volatile long double complex ld3 = 5.5L + 6.6L*I;
volatile long double complex ld4 = 7.7L + 8.8L*I;
volatile long double complex ld5 = 9.9L + 10.0L*I;

void check_float(int a, float complex a1, float complex a2, float complex a3, float complex a4, float complex a5) {
    if (a1 != f1 || a2 != f2 || a3 != f3 || a4 != f4 || a5 != f5) {
        abort();
    }
}

void check_double(int a, double complex a1, double complex a2, double complex a3, double complex a4, double complex a5) {
    if (a1 != d1 || a2 != d2 || a3 != d3 || a4 != d4 || a5 != d5) {
        abort();
    }
}

void check_long_double(int a, long double complex a1, long double complex a2, long double complex a3, long double complex a4, long double complex a5) {
    if (a1 != ld1 || a2 != ld2 || a3 != ld3 || a4 != ld4 || a5 != ld5) {
        abort();
    }
}

void g(const char *s, const char *f, va_list ap) {
    // Function body removed to adhere to no I/O operation rule
}

void f(char *s, const char *f, ...) {
    va_list ap;
    va_start(ap, f);
    g(s, f, ap);
    va_end(ap);
}

int main(void) {
    check_float(0, f1, f2, f3, f4, f5);
    check_double(0, d1, d2, d3, d4, d5);
    check_long_double(0, ld1, ld2, ld3, ld4, ld5);
    
    char buf[100];
    strcpy(buf, "asdf");

    if (strcmp(buf, "asdf") != 0) {
        abort();
    }

    return 0;
}