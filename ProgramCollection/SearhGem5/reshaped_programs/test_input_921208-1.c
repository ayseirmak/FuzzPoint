#include <stdio.h>
#include <stdlib.h>

// Define the function f which computes the square of a number
double f(double x) {
    return x * x;
}

// Define the Int function which takes a function pointer and a double argument
double Int(double (*f)(double), double a) {
    return (*f)(a);
}

int main() {
    // Initialize and declare the variable `a` with a fixed value
    double a = 5.0;
    
    // Compute the result using the Int function
    double result = Int(&f, a);
    
    // Print the result for verification purposes
    printf("The result of f(%f) is: %f\n", a, result);

    // Return 0 to indicate successful execution
    return 0;
}