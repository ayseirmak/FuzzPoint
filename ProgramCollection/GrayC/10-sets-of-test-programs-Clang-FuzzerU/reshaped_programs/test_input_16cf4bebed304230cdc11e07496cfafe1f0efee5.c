#include <stdio.h>
#include <stdlib.h>

#if defined(__arm__) || defined(__aarch64__)
#include <arm_neon.h>
#endif

typedef unsigned short int UV __attribute__((vector_size(16)));
typedef short int SV __attribute__((vector_size(16)));

#define TEST(a, b, c, d, e, f, g, h)         \
void uq##a##b##c##d##e##f##g##h(UV *x, UV *y) { \
    *x = *y / (UV){a, b, c, d, e, f, g, h};      \
}                                             \
                                                \
void ur##a##b##c##d##e##f##g##h(UV *x, UV *y) { \
    *x = *y % (UV){a, b, c, d, e, f, g, h};      \
}                                                

void foo(struct S *x, const struct S *y) {
    const unsigned long n = y->d + 0; /* Ensure n is initialized */
    const double m = 0.25 * (y->b - y->a); /* Fix missing variable name */
    double o = 0.0, p = 1.0;
    unsigned long i;

    x->a = y->a;
    x->b = y->b;
    if (n == 1) {
        x->c[0] = 0.;
    } else if (n == 2) {
        x->c[0] = m * (y->c[0]);
        x->c[1] = y->c[1];
    } else {
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

struct S {
    double a, b, *c;
    unsigned long d;
};

int main(void) {
    struct S x, y;
    double c[4] = {10, 20, 30, 40};
    double d[4], e[4] = {118, 118, 118, 118};

    y.a = 10;
    y.b = 6;
    y.c = c;
    x.c = d;
    y.d = 3;
    
    for (int i = 0; i < 4; ++i) d[i] = e[i]; /* Initialize using a simple loop */
    foo(&x, &y);
    
    if (d[0] != 0 || d[1] != 20 || d[2] != 10 || d[3] != -10)
        abort();
    
    y.d = 2;
    for (int i = 0; i < 4; ++i) d[i] = e[i];
    foo(&x, &y);
    
    if (d[0] != 60 || d[1] != 20 || d[2] != -10 || d[3] != 118)
        abort();
    
    y.d = 1;
    for (int i = 0; i < 4; ++i) d[i] = e[i];
    foo(&x, &y);
    
    if (d[0] != -20 || d[1] != -10 || d[2] != 118 || d[3] != 118)
        abort();
    
    y.d = 0;
    for (int i = 0; i < 4; ++i) d[i] = e[i];
    foo(&x, &y);
  
    if (d[0] != 0 || d[1] != 118 || d[2] != 118 || d[3] != 118)
        abort();
  
    return 0;
}