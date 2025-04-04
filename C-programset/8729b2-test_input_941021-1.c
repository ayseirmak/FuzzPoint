#include <stdio.h>
#include <stdlib.h>

double glob_dbl = 0.0;

void f(double *pdbl, double value) {
    if (pdbl == NULL) {
        pdbl = &glob_dbl;
    }
    *pdbl = value;
}

int main(void) {
    double fixedValue1 = 0; // Initialize with a known value
    double value = 5.5; // Initialize with a sample test value

    double *pdbl = (fixedValue1 == 0) ? NULL : &glob_dbl;

    f(pdbl, value);

    if (glob_dbl != value) {
        printf("Test failed: glob_dbl (%f) is not equal to value (%f)\n", glob_dbl, value);
        return 1;
    }
    printf("Test passed: glob_dbl is equal to value (%f)\n", value);
    return 0;
}