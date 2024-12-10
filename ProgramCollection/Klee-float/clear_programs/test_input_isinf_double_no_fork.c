#include <stdio.h>
#include <math.h>
#include <assert.h>

int main() {
    // Initialize x with a value that represents infinity
    double x = INFINITY;

    // Check if x is infinite
    assert(isinf(x));

    // Print a message to ensure the output
    printf("Assertion passed: x is infinite.\n");

    return 0;
}