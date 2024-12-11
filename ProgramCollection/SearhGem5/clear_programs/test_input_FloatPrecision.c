#include <stdio.h>

// Function to print the product of X and a large integer along with its hexadecimal representation
void print(float X) {
    // Multiplying the float X by a large integer and printing the result
    printf("%f\n", X * 2147483647);
    // Converting the product to an unsigned long long then casting to int and printing as hexadecimal
    printf("%x\n", (int)(unsigned long long)(X * 2147483647));
}

int main(void) {
    // Declare and initialize X to an example value
    float X = 0.5;  // Example value for demonstration

    // Call the print function with the floating-point number X
    print(X);

    return 0;
}