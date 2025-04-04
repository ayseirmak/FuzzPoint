#include <stdio.h>
#include <stdlib.h> // For abort() and exit()

// Ensure that fpEq checks for floating-point equality with a tolerance
void fpEq(double x, double y) {
    const double tolerance = 1e-9;
    if ((x - y) > tolerance || (y - x) > tolerance) {
        printf("Floating-point numbers are not equal: %lf != %lf\n", x, y);
        abort();
    }
}

void fpTest(double x, double y) {
    double result0;
    double result2;
    
    // Correct result0 assignment and calculation
    result0 = (35.7 * 100.0) / 45.0; 

    result2 = (x * 100.0) / y;
    
    // Compare the calculated results with some tolerance
    fpEq(result0, result2);
}

int main() {
    // Directly pass deterministic values
    double x = 35.7;
    double y = 45.0;
    
    fpTest(x, y);
    exit(0);
}