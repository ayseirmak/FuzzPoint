#include <stdio.h>

// Define the constant value X
#define X  5.9486574767861588254287966331400356538172e4931L

int main() {
    // Initialize the long double variables
    long double x = X + X;
    long double y = 2.0L * X;

    // Check if the floating point arithmetic yields the expected result
    if (x != y) {
        printf("Assertion failed: x != y\n");
        return 1;
    }

    printf("Assertion succeeded: x == y\n");
    return 0;
}