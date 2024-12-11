#include <stdio.h> // Standard input-output header

int main() {
    // Initializing and declaring all variables
    double a = 11.5; 
    double b = 0.34234523; 
    double product = 0.0; // Initialize product to ensure there are no uninitialized variables

    // Calculating product of a and b
    product = a * b;

    // Printing the product with two decimal places
    printf("Product = %.2lf\n", product);

    return 0; // Indicating successful execution
}