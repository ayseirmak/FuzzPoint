#include <stdio.h>
#include <complex.h>

void foo(double complex x) {
    printf("foo called with x: %.2f + %.2fi\n", creal(x), cimag(x));
}

void bar(float complex y) {
    printf("bar called with y: %.2f + %.2fi\n", creal(y), cimag(y));
}

void baz(long double complex z) {
    printf("baz called with z: %.2Lf + %.2Lfi\n", creal(z), cimag(z));
}

int main() {
    // Initialize complex variables with deterministic values
    double complex x = 2.0 + 0.0*I;
    float complex y = 3.0f + 4.0f*I;
    long double complex z = 0.0L + 6.0L*I;

    // Call the functions
    foo(x);
    bar(y);
    baz(z);

    return 0;
}