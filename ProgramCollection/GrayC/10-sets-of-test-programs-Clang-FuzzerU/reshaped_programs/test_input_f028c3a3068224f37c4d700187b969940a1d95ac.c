#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <assert.h>

unsigned long long int a = 0x95dd3d896f7422e2ULL;
struct S1 { unsigned int m : 13; } b;

void foo1(void) {
    b.m = ((unsigned)a) >> ((0x644eee9667723bf7LL | a) & ~0xdee27af8U) - 0x644eee9667763bd8LL;
}

struct S2 {
    double a, b, *c;
    unsigned long d;
};

void foo2(struct S2 *x, const struct S2 *y) {
    const unsigned long n = y->d;
    const double m = 0.25 * (y->b - y->a);
    x->a = y->a;
    x->b = y->b;
    if (n == 1) {
        x->c[0] = 0.0;
    } else if (n == 2) {
        double o = 0.0, p = 1.0;
        x->c[0] = x->c[1] = x->c[2] = 0.0; // Init necessary elements
        for (unsigned long i = 1; i <= n - 2; i++) {
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
    // Check the first function
    if (__INT_MAX__ != 0x7fffffffULL) {
        return 0;
    }
    foo1();
    if (b.m != 0) {
        printf("Error in foo1: unexpected 'b.m' value\n");
        exit(EXIT_FAILURE);
    }

    // Check the second function
    struct S2 x, y;
    double c[4] = {10, 20, 30, 40}, d[4], e[4] = {118, 118, 118, 118};
    y.a = 10;
    y.b = 6;
    y.c = c;
    x.c = d;
    y.d = 3;
    memcpy(d, e, sizeof d);
    foo2(&x, &y);
    if (d[0] != 0 || d[1] != 20 || d[2] != 10 || d[3] != -10) {
        printf("Error in foo2 (case 3)\n");
        exit(EXIT_FAILURE);
    }
    y.d = 1;
    memcpy(d, e, sizeof d);
    foo2(&x, &y);
    if (d[0] != -20 || d[1] != -10 || d[2] != 118 || d[3] != 118) {
        printf("Error in foo2 (case 1)\n");
        exit(EXIT_FAILURE);
    }
    y.d = 0;
    memcpy(d, e, sizeof d);
    foo2(&x, &y);
    if (d[0] != 0 || d[1] != 118 || d[2] != 118 || d[3] != 118) {
        printf("Error in foo2 (case 0)\n");
        exit(EXIT_FAILURE);
    }
    printf("All tests passed.\n");
    return 0;
}