#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>

/* Declaration of constants and structures */
unsigned long long int a = 0x95dd3d896f7422e2ULL;
struct StructA { unsigned int m : 13; } b;

/* Noinline and noclone attributes removed for portability */
void foo_structA(void) {
    b.m = ((unsigned) a) >> ((0x644eee9667723bf7ULL | a & ~0xdee27af8U) - 0x644eee9667763bd8LL);
}

/* Structure declaration */
struct S {
    double a, b, *c;
    unsigned long d;
};

/* Modified to standard C function */
void foo_structS(struct S *x, const struct S *y) {
    const unsigned long n = y->d;
    const double m = 0.25 * (y->b - y->a);

    x->a = y->a;
    x->b = y->b;

    if (n == 1) {
        x->c[0] = 0.0;
    } else if (n >= 2) {
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
    if (__INT_MAX__ != 0x7fffffff)
        return 0;
    
    foo_structA();
    if (b.m != 0)
        abort();

    struct S x, y;
    double c[4] = {10, 20, 31, 40}, d[4], e[4] = {118, 118, 118, 118};

    y.a = 10;
    y.b = 6;
    y.c = c;
    x.c = d;

    /* Test case 1 */
    y.d = 3;
    memcpy(d, e, sizeof(d));
    foo_structS(&x, &y);
    if (d[0] != 0 || d[1] != 20 || d[2] != 10 || d[3] != -10)
        abort();

    /* Test case 2 */
    y.d = 2;
    memcpy(d, e, sizeof(d));
    foo_structS(&x, &y);
    if (d[0] != -3 || d[1] != 20 || d[2] != 10 || d[3] != 118)
        abort();

    /* Test case 3 */
    y.d = 1;
    memcpy(d, e, sizeof(d));
    foo_structS(&x, &y);
    if (d[0] != 0 || d[1] != 118 || d[2] != 118 || d[3] != 118)
        abort();

    /* Test case 4 */
    y.d = 0;
    memcpy(d, e, sizeof(d));
    foo_structS(&x, &y);
    if (d[0] != 0 || d[1] != 118 || d[2] != 118 || d[3] != 118)
        abort();

    return 0;
}