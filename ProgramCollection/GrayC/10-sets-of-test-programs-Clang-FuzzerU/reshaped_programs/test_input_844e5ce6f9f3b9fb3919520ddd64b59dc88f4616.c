#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
        x->c[0] = 0.0 * x->c[1];
    } else {
        double o = 0.0, p = 1.0;
        for (unsigned long i = 1; i <= n - 2; i++) {
            x->c[i] = 0.0;  // Assuming missing logic to be zero-assignment
            o += p * x->c[n - 1];
        }
        x->c[0] = 2.0 * o;
    }
}

int main(void) {
    struct S x, y;
    double c[4] = {10, 20, 30, 40}, d[4], e[4] = {118, 118, 118, 118};

    y.a = 10;
    y.b = 6;
    y.c = c;
    x.c = d;

    // First test case
    y.d = 3;
    memcpy(d, e, sizeof(d));
    foo(&x, &y);
    if (d[0] != 0 || d[1] != 20 || d[2] != 10 || d[3] != -10) {
        printf("Test case 1 failed\n");
        return 1;
    }

    // Second test case
    y.d = 2;
    memcpy(d, e, sizeof(d));
    foo(&x, &y);
    if (d[0] != 60 || d[1] != 20 || d[2] != -10 || d[3] != 118) {
        printf("Test case 2 failed\n");
        return 1;
    }

    // Third test case
    y.d = 1;
    memcpy(d, e, sizeof(d));
    foo(&x, &y);
    if (d[0] != -20 || d[1] != -10 || d[2] != 118 || d[3] != 118) {
        printf("Test case 3 failed\n");
        return 1;
    }

    // Fourth test case
    y.d = 0;
    memcpy(d, e, sizeof(d));
    foo(&x, &y);
    if (d[0] != 0 || d[1] != 118 || d[2] != 118 || d[3] != 118) {
        printf("Test case 4 failed\n");
        return 1;
    }

    printf("All test cases passed.\n");
    return 0;
}