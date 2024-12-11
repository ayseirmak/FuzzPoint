#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

// Function to compute cube root using the standard library function
double cbrtl(double x) {
    return cbrt(x);
}

int main() {
    // Initialize the value with a known value for testing
    double x = 27.0;

    // Calculate the cube root and check the result is approximately 3
    assert((int)(cbrtl(x) + 0.5) == 3);

    // Indicate successful execution
    printf("Cube root test passed for x = %f\n", x);
    return 0;
}