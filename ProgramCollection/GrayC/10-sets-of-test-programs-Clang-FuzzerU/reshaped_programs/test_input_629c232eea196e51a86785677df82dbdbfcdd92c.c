#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
        x->c[0] = 0.;
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
    double c[4] = {10.0, 20.0, 30.0, 40.0};
    double d[4];
    double e[4] = {118.0, 118.0, 118.0, 118.0};

    y.a = 10.0;
    y.b = 6.0;
    y.c = c;
    x.c = d;
    y.d = 3;
    memcpy(d, e, sizeof(d));
    foo(&x, &y);
    if (d[0] != 0.0 || d[1] != 20.0 || d[2] != 10.0 || d[3] != -10.0) {
        printf("Test 1 failed\n");
        abort();
    }

    y.d = 2;
    memcpy(d, e, sizeof(d));
    foo(&x, &y);
    if (d[0] != 60.0 || d[1] != 20.0 || d[2] != -10.0 || d[3] != 118.0) {
        printf("Test 2 failed\n");
        abort();
    }

    y.d = 1;
    memcpy(d, e, sizeof(d));
    foo(&x, &y);
    if (d[0] != -20.0 || d[1] != -10.0 || d[2] != 118.0 || d[3] != 118.0) {
        printf("Test 3 failed\n");
        abort();
    }

    y.d = 0;
    memcpy(d, e, sizeof(d));
    foo(&x, &y);
    if (d[0] != 0.0 || d[1] != 118.0 || d[2] != 118.0 || d[3] != 118.0) {
        printf("Test 4 failed\n");
        abort();
    }

    printf("All tests passed!\n");
    return 0;
}