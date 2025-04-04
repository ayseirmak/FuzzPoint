#include <stdio.h>
#include <stdlib.h>

void foo(__complex__ double x);
void bar(__complex__ float x);
void baz(__complex__ long double x);

int main() {
    __complex__ double x;
    __complex__ float y;
    __complex__ long double z;

    // Initialize with fixed values
    __real__ x = 1.0;
    __imag__ x = 2.0;
    foo(x);

    __real__ y = 3.0f;
    __imag__ y = 4.0f;
    bar(y);

    __real__ z = 5.0L;
    __imag__ z = 6.0L;
    baz(z);

    return 0;
}

void foo(__complex__ double x) {
    if (__real__ x != 1.0 || __imag__ x != 2.0) {
        printf("foo: Complex double mismatch!\n");
    }
}

void bar(__complex__ float x) {
    if (__real__ x != 3.0f || __imag__ x != 4.0f) {
        printf("bar: Complex float mismatch!\n");
    }
}

void baz(__complex__ long double x) {
    if (__real__ x != 5.0L || __imag__ x != 6.0L) {
        printf("baz: Complex long double mismatch!\n");
    }
}