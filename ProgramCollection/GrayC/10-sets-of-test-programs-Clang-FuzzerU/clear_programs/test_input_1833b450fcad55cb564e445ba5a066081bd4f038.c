#include <stdio.h>
#include <assert.h>
#include <complex.h>

void foo(double complex x);
void bar(float complex x);
void baz(long double complex x);

int main() {
    long double complex z = 5.0 + 6.0 * I;
    baz(z);
    return 0;
}

void foo(double complex x) {
    assert(creal(x) == 1.0 && cimag(x) == 2.0);
}

void bar(float complex x) {
    assert(creal(x) == 3.0f && cimag(x) == 4.0f);
}

void baz(long double complex x) {
    assert(creal(x) == 5.0L && cimag(x) == 6.0L);
}