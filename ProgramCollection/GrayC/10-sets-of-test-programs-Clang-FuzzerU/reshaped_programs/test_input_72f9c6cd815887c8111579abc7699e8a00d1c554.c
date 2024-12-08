#include <stdio.h>
#include <complex.h>
#include <stdlib.h>
#include <assert.h>

void foo(_Complex double x);
void bar(_Complex float y);
void baz(_Complex long double z);

int main() {
    _Complex double x = 1.0 + 2.0 * I;
    _Complex float y = 3.0f + 4.0f * I;
    _Complex long double z = 5.0L + 6.0L * I;

    foo(x);
    bar(y);
    baz(z);

    return 0;
}

void foo(_Complex double x) {
    double realPart = creal(x);
    double imagPart = cimag(x);

    // For demonstration, let's use assertions
    printf("foo: %.2f + %.2fi\n", realPart, imagPart);

    // Check some condition, for demonstration purposes let's use an assertion
    assert(realPart == 1.0 && imagPart == 2.0);
}

void bar(_Complex float y) {
    float realPart = creal(y);
    float imagPart = cimag(y);

    printf("bar: %.2f + %.2fi\n", realPart, imagPart);

    assert(realPart == 3.0f && imagPart == 4.0f);
}

void baz(_Complex long double z) {
    long double realPart = creal(z);
    long double imagPart = cimag(z);

    printf("baz: %.2Lf + %.2Lfi\n", realPart, imagPart);

    assert(realPart == 5.0L && imagPart == 6.0L);
}