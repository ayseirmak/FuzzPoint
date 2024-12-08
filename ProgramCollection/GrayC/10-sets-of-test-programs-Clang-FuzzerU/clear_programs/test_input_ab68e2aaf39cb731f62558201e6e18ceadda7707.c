#include <stdio.h>
#include <stdlib.h>

double test(const double le, const double ri) {
    double val = (ri - le) / (ri * (le + 1.0));
    return val;
}

int main() {
    double retval;

    retval = test(1.0, 2.0);

    // Use printf for output to indicate the calculated value.
    printf("The result of the test function is: %f\n", retval);

    exit(0);
}