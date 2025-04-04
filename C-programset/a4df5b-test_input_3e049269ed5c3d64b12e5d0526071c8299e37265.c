#include <stdio.h>
#include <stdlib.h>

// Function to compare two floating-point numbers and abort if they are not equal
void fpEq (double x, double y) {
    if (x != y) {
        abort();
    }
}

// Function to perform a floating-point division and compare results using fpEq
void fpTest (double x, double y) {
    double result0 = (35.7 * 100.0) / 45.0;
    double result2 = (x * 100.0) / y;
    fpEq(result0, result2);
}

int main() {
    // Fixed deterministic inputs
    double x = 35.7;
    double y = 45.0;
    
    // Perform the test with fixed values
    fpTest(x, y);

    // Clean exit with status code 0
    exit(0);
}