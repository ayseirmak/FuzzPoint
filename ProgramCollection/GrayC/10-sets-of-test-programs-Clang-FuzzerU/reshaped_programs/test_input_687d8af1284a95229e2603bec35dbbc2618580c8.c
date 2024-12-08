#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct S {
    double a, b, *c;
    unsigned long d;
};

void foo(struct S *x, const struct S *y) {
    const unsigned long n = y->d + 1;
    const double m = 0.25 * (y->b - y->a);
    x->a = y->a;
    x->b = y->b;
    if (n == 1) {
        x->c[0] = 0.0;
    } else if (n == 2) {
        x->c[1] = m * y->c[0];
        x->c[0] = 2.0 * x->c[1];
    } else {
        double o = 0.0, p = 1.0;
        unsigned long i;
        for (i = 1; i <= n - 2; i++) {
            x->c[i] = m * (y->c[i - 1] - y->c[i + 1]) / (double) i;
            o += p * x->c[i];
            p = -p;
        }
        x->c[n - 1] = m * y->c[n - 2] / (n - 1.0);
        o += p * x->c[n - 1];
        x->c[0] = 2.0 * o;
    }
}

int main(void) {
    struct S x, y;
    double c[4] = {10, 20, 30, 40};
    double d[4] = {0, 0, 0, 0};
    double expected_result[4] = {118, 118, 118, 118}; // Expected output values for validation

    // Initialize y
    y.a = 0.0;
    y.b = 0.0; // You need to set appropriate test values for a and b
    y.c = c;
    y.d = 3;   // Modify this if you test with different d values
    
    // Set up x
    x.c = d;
    foo(&x, &y);

    // Validate result
    for (int i = 0; i < 4; i++) {
        assert(d[i] == expected_result[i]);
    }

    printf("Test completed successfully.\n");
    return 0;
}