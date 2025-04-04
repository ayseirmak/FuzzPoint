#include <stdio.h>
#include <stdarg.h>
#include <assert.h>

void fdouble(double one, ...) {
    double value;
    va_list ap;

    va_start(ap, one);
    value = va_arg(ap, double);
    va_end(ap);

    if (one != 0.0 || value != 2.0) {
        printf("Error in fdouble: unexpected values.\n");
    }
}

int foo(int x) {
    return x < 0 ? 1 : x;
}

struct S {
    int a, b, c;
};

void foo2(struct S x, struct S y) {
    if (y.a != 6 || y.b != 7 || y.c != 8) {
        printf("Error in foo2: structure values mismatch.\n");
    }
}

int foo3(struct S x, struct S y, struct S z) {
    foo2(x, y);
    if (z.a != 9) {
        printf("Error in foo3: structure Z mismatch.\n");
    }
    return 0;
}

int bar2(struct S x, struct S y) {
    foo2(y, x);
    return 0;
}

int bar3(struct S x, struct S y, struct S z) {
    return foo3(y, x, z);
}

int baz3(struct S x, struct S y, struct S z) {
    return foo3(y, z, x);
}

int main(void) {
    struct S a = {3, 4, 5};
    struct S b = {6, 7, 8};
    struct S c = {9, 10, 11};

    bar2(b, a);
    bar3(a, b, c);
    baz3(a, b, c);

    // Function tests with fixed values
    foo(5);
    fdouble(1.0, 2.0);

    printf("Program completed successfully.\n");
    return 0;
}