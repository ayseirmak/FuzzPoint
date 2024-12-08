#include <stdio.h>
#include <string.h>
#include <assert.h>

// Define the structure S
struct S {
    double a, b, *c;
    unsigned long d;
};

// Function foo with no inline or clone attributes
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
        double o = 0.0;
        for (unsigned long i = 1; i < n - 1; i++) {
            const double p = (i + 1) * m * y->c[i - 1] / (i + 1.0);
            x->c[i] = p;
            o += p * x->c[i];
        }
        x->c[n - 1] = m * y->c[n - 2] / (n - 1.0);
        o += x->c[n - 1];
        x->c[0] = 2.0 * o;
    }
}

int main(void) {
    struct S x, y;
    double c[4] = {10, 20, 30, 40};
    double d[4];
    double e[4] = {118, 118, 118, 118};

    y.a = 10.0;
    y.b = 6.0;
    y.c = c;
    x.c = d;
    y.d = 3;

    memcpy(d, e, sizeof(d));
    foo(&x, &y);

    // Check the condition and assert instead of abort
    assert(d[0] == 0 && d[1] == 118 && d[2] == 118 && d[3] == 118);

    return 0;
}