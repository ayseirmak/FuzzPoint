#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <assert.h>

unsigned long long int a = 0x95dd3d896f7422e2ULL;
struct S {
    unsigned int m : 13;
} b;

void foo_struct_1(void) {
    b.m = ((unsigned)a) >> (0x644eee9667723bf7LL | a & ~0xdee27af8U) - 0x644eee9667763bd8LL;
}

struct S2 {
    double a, b, *c;
    unsigned long d;
};

void foo_struct_2(struct S2 *x, const struct S2 *y) {
    unsigned long n = y->d;
    double m = 0.25 * (y->b - y->a);
    x->a = y->a;
    x->b = y->b;

    if (n == 1) {
        x->c[0] = 0.0;
    } else if (n >= 2) {
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

int main(void) {
    // First part testing foo_struct_1
    if (__INT_MAX__ != 0x7fffffffULL) {
        return 0;
    }
    foo_struct_1();
    assert(b.m == 0);

    // Second part testing foo_struct_2
    struct S2 x, y;
    double c[4] = {10, 20, 30, 40};
    double d[4];
    double e[4] = {118, 118, 118, 118};

    y.a = 10;
    y.b = 6;
    y.c = c;
    x.c = d;
    y.d = 3;
    memcpy(d, e, sizeof(d));
    foo_struct_2(&x, &y);
    assert(d[0] == 0 && d[1] == 20 && d[2] == 10 && d[3] == -10);

    y.d = 2;
    memcpy(d, e, sizeof(d));
    foo_struct_2(&x, &y);
    assert(d[0] == 60 && d[1] == 20 && d[2] == -10 && d[3] == 118);

    y.d = 1;
    memcpy(d, e, sizeof(d));
    foo_struct_2(&x, &y);
    assert(d[0] == -20 && d[1] == -10 && d[2] == 118 && d[3] == 118);

    y.d = 0;
    memcpy(d, e, sizeof(d));
    foo_struct_2(&x, &y);
    assert(d[0] == 0 && d[1] == 118 && d[2] == 118 && d[3] == 118);

    return 0;
}