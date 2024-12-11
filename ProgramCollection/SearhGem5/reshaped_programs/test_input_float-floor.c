#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
    // Use a predetermined floating-point value instead of input
    double input_value = 1023.99; // This is a test value typically close to an edge for flooring to 1023

    double df = floor(input_value);
    float f1 = (float)floor(input_value);

    if ((int)df != 1023 || (int)f1 != 1023) {
        printf("Assertion failed: Floored values do not match expected 1023\n");
    } else {
        printf("All checks passed: Floored values are 1023\n");
    }

    return 0;
}