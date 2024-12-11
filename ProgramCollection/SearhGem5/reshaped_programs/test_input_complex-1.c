#include <stdio.h>
#include <complex.h>
#include <stdlib.h>

double g0(double x)
{
    return 1.0;
}

double g1(double x)
{
    return -1.0;
}

double g2(double x)
{
    return 0.0;
}

double complex xcexp(double complex x)
{
    double r;

    r = g0(creal(x));
    double complex result;
    result = r * (g1(cimag(x)) + g2(cimag(x)) * I);
    return result;
}

int main(void)
{
    double complex x = xcexp(I);

    if (creal(x) != -1.0) {
        printf("Assertion failed: real part is not -1.0\n");
        return 1;
    }
    if (cimag(x) != 0.0) {
        printf("Assertion failed: imaginary part is not 0.0\n");
        return 1;
    }

    return 0;
}