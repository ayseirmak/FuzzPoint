#include <stdio.h>
#include <stdarg.h>

// Function using variadic arguments to fetch a double value
// This function takes six float arguments followed by variadic arguments
double f(float f1, float f2, float f3, float f4, float f5, float f6, ...) {
    va_list ap;
    double d;

    // Initialize the variadic argument list
    va_start(ap, f6);
    // Retrieve the double argument following the float arguments
    d = va_arg(ap, double);
    // Clean up the variable argument list
    va_end(ap);

    // Return the retrieved double argument
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

    // Initialize a double variable with a known value for testing
    double d = 7.0;

    // Call the function with the float and double values
    // Verify if the returned double matches the provided double value
    if (f(f1, f2, f3, f4, f5, f6, d) != d) {
        printf("Test failed: the returned double value is not as expected.\n");
        return 1; // Indicate failure
    }
    
    // Print success message if the test passes
    printf("Test passed: the returned double value matches.\n");
    
    // Return 0 to indicate successful execution
    return 0;
}