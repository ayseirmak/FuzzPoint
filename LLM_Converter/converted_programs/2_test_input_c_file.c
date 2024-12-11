#include <stdio.h>
#include <stdarg.h>

// Function using variadic arguments to fetch a double value
double fetch_double(float f1, float f2, float f3, float f4, float f5, float f6, ...) {
    va_list ap;
    double d;

    va_start(ap, f6);
    d = va_arg(ap, double); // Fetches the double argument
    va_end(ap);
    return d;
}

int main() {
    // Initialize and declare float variables with example values
    float f1 = 1.0f;
    float f2 = 2.0f;
    float f3 = 3.0f;
    float f4 = 4.0f;
    float f5 = 5.0f;
    float f6 = 6.0f;

    // Initialize double variable with a known value for testing
    double d = 7.0;

    // Call the function and compare the returned double value
    if (fetch_double(f1, f2, f3, f4, f5, f6, d) != d) {
        printf("Test failed: the returned double value is not as expected.\n");
        return 1;
    }
    
    printf("Test passed: the returned double value matches.\n");

    return 0;
}