#include <stdio.h>

// Function to check if a double value is infinite
int target_isinf(double x) {
    union {
        double d;
        struct {
            unsigned mantissa2;
            unsigned mantissa1 : 20;
            unsigned exponent  : 11;
            unsigned sign      :  1;
        } big_endian;
    } u;

    u.d = x;
    return (u.big_endian.exponent == 2047 && u.big_endian.mantissa1 == 0 && u.big_endian.mantissa2 == 0);
}

int main() {
    // Initialize the double value to test
    double testValue = INFINITY;  // Change to a specific value to test other cases

    // Print the result of the infinity check for the value
    printf("Is the number infinite: %d\n", target_isinf(testValue));

    return 0;
}