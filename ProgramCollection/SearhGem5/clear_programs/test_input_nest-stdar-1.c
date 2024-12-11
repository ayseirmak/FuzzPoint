#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

// Function to handle variable argument list and return a double
double f(int x, ...) {
    va_list args;
    double a;

    va_start(args, x);
    a = va_arg(args, double);
    va_end(args);
    return a;
}

int main() {
    // Pre-defined value; originally fetched from command line
    double predefinedValue = 1.0;

    // Use the function `f` with a predefined value instead of command line input
    if (f(1, predefinedValue) != 1.0) {
        // If the value is not as expected, print an error message
        printf("Error: Function did not return the expected value.\n");
        return 1;
    }

    // Indicate successful execution of the program
    printf("Function returned the expected value.\n");
    return 0;
}