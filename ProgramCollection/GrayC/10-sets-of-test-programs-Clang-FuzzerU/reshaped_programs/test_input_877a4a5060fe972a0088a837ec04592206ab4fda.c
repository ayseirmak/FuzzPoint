#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// Define structures
struct S {
    int a, b, c;
};

// Function prototypes
int foo2(struct S x, struct S y);
int foo3(struct S x, struct S y, struct S z);
int bar2(struct S x, struct S y);
int bar3(struct S x, struct S y, struct S z);
int baz3(struct S x, struct S y, struct S z);
void arg(void);
void ret(void);

// Implement functions
int foo2(struct S x, struct S y) {
    if (x.a != 3 || x.b != 4 || x.c != 5) {
        printf("Assertion failed in foo2 for x\n");
        abort();
    }
    if (y.a != 6 || y.b != 7 || y.c != 8) {
        printf("Assertion failed in foo2 for y\n");
        abort();
    }
    return 0;
}

int foo3(struct S x, struct S y, struct S z) {
    foo2(x, y);
    if (z.a != 9 || z.b != 10 || z.c != 11) {
        printf("Assertion failed in foo3 for z\n");
        abort();
    }
    return 0;
}

int bar2(struct S x, struct S y) {
    return foo2(y, x);
}

int bar3(struct S x, struct S y, struct S z) {
    return foo3(y, x, z);
}

int baz3(struct S x, struct S y, struct S z) {
    return foo3(y, z, x);
}

// Main function
int main(void) {
    // Initialize structures with deterministic values
    struct S a = {3, 4, 5};
    struct S b = {6, 7, 8};
    struct S c = {9, 10, 11};

    bar2(b, a);
    bar3(b, a, c);
    baz3(c, a, b);

    return 0;
}