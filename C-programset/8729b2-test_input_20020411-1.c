#include <stdio.h>
#include <stdlib.h>

// Define a structure for complex numbers with float components
typedef struct {
    float real;
    float imag;
} complex_float;

// Define a structure for complex numbers with double components
typedef struct {
    double real;
    double imag;
} complex_double;

// Function to return a modified complex float number
complex_float foo(void) {
    // Create an array of complex_float with one element
    // Initialize it with specific values
    complex_float f[1];
    f[0].real = 1.0f;
    f[0].imag = 1.0f;
    // Modify the real part of the first element
    f[0].real = -f[0].real;

    // Return the first element of the array
    return f[0];
}

int main(void) {
    // Declare and initialize a placeholder for complex_double
    complex_double d[1];
    // Call the foo function and store the result in a temporary complex_float variable
    complex_float temp = foo();
    // Assign the values from the temporary complex_float to the complex_double
    d[0].real = temp.real;
    d[0].imag = temp.imag;

    // Check if the real part is not 1.0 or the imaginary part is not -1.0
    if (d[0].real != -1.0 || d[0].imag != 1.0) {
        // If the condition is true, there is an unexpected behavior, so abort the program
        abort();
    }

    // Return 0 to indicate successful execution
    return 0;
}