#include <stdio.h>
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
        x->c[0] = 0.;
    } else if (n == 2) {
        x->c[1] = m * y->c[0];
        x->c[0] = 2.0 * x->c[1];
    } else {
        double o = 0.0, p = 1.0;
        unsigned long i;
        for (i = 1; i <= n - 2; i++) {
            x->c[i] = m * (y->c[i - 1] - y->c[i + 1]) / (double)i;
            o += p * x->c[i];
            p = -p;
        }
        x->c[n - 1] = m * y->c[n - 2] / (n - 1.0);
        o += p * x->c[n - 1];
        x->c[0] = 2.0 * o;
    }
}

int main() {
    // Fixed values for demonstration, assuming y.d as a typical edge case value of 3
    struct S x, y;
    double c[4] = {10, 20, 30, 40}, d[4], e[4] = {118, 118, 118, 118};

    y.a = 10;
    y.b = 6;
    y.c = c;
    x.c = d;
    y.d = 3;  // Adjust this value as needed to test different scenarios.
    memcpy(d, e, sizeof d);
    foo(&x, &y);

    for (int i = 0; i < y.d + 1; i++)
        printf("%lf ", x.c[i]);
    printf("\n");

    return 0;
}