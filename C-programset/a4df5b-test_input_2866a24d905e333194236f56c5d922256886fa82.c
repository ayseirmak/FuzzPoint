#include <stdio.h>
#include <complex.h>
#include <stdlib.h>
#include <assert.h>

/* Function to add two complex numbers */
double complex f(double complex x, double complex y) {
    x += y;
    return x;
}

int main(void) {
    /* Initialize complex numbers */
    double complex ag = 1.0 + 1.0*I;
    double complex bg = -2.0 + 2.0*I;
    double complex a = ag;
    double complex b = -2.0 + 2.0*I;
    double complex c;

    /* Call the function and calculate the result */
    c = f(a, b);

    /* Verify that the calculations are correct */
    assert((creal(a) == 1.0) && (cimag(a) == 1.0));
    assert((creal(b) == -2.0) && (cimag(b) == 2.0));
    assert((creal(c) == -1.0) && (cimag(c) == 3.0));

    printf("All assertions passed. No errors found.\n");

    return 0;
}