#include <stdio.h>
#include <string.h>

/* Define the structure */
struct S
{
    double a, b, *c;
    unsigned long d;
};

/* Function to perform operations on structs */
__attribute__((noinline, noclone)) 
void foo(struct S *x, const struct S *y)
{
    const unsigned long n = y->d + 1;
    const double m = 0.25 * (y->b - y->a);
    x->a = y->a;
    x->b = y->b;
    
    if (n == 1)
    {
        x->c[0] = 0.0;
    }
    else if (n == 2)
    {
        x->c[1] = m * y->c[0];
        x->c[0] = 2.0 * x->c[1];
    }
    else
    {
        double o = 0.0;
        for (unsigned long i = 0; i < n - 1; ++i)
        {
            const double p = y->c[i] / (i + 1.0);
            x->c[i] = m * y->c[i] / (i + 1.0);
            o += p * x->c[i];
        }
        x->c[n - 1] = m * y->c[n - 2] / (n - 1.0);
        o += (y->c[n - 1] / n) * x->c[n - 1];
        x->c[0] = 2.0 * o;
    }
}

int main(void)
{
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

    for (int i = 0; i < 4; ++i)
    {
        if (d[i] != e[i])
        {
            printf("Mismatch at index %d: %f != %f\n", i, d[i], e[i]);
            return 1;
        }
    }

    printf("All values match as expected.\n");
    return 0;
}