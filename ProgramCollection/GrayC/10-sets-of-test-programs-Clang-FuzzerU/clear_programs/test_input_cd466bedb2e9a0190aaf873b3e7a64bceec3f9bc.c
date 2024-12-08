#include <stdlib.h>
#include <complex.h>
#include <stdio.h>

// Function prototypes
void foo(double complex x);
void bar(float complex x);
void baz(long double complex x);

int main(void)
{
    double complex x = 1.0 + 2.0*I;
    float complex y = 3.0f + 4.0f*I;
    long double complex z = 5.0L + 6.0L*I;

    // Call functions with predefined values
    foo(x);
    bar(y);
    baz(z);

    printf("All functions completed successfully.\n");
    return 0;
}

void foo(double complex x)
{
    if (creal(x) != 1.0 || cimag(x) != 2.0)
    {
        printf("foo: Expected 1.0 + 2.0i, but received a different complex number.\n");
        abort();
    }
}

void bar(float complex x)
{
    if (creal(x) != 3.0f || cimag(x) != 4.0f)
    {
        printf("bar: Expected 3.0 + 4.0i, but received a different complex number.\n");
        abort();
    }
}

void baz(long double complex x)
{
    if (creal(x) != 5.0L || cimag(x) != 6.0L)
    {
        printf("baz: Expected 5.0 + 6.0i, but received a different complex number.\n");
        abort();
    }
}