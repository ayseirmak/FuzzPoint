#include <stdio.h>

int main() {
    // Initialize the floating point number `x`
    double x = 0.5;  // Chose a typical test value, e.g., less than 1

    // Verify the condition and print the result
    if (x < 1) {
        printf("The value %.1f is less than 1\n", x);
        return 0;
    } else {
        printf("The value %.1f is not less than 1\n", x);
        return 1;
    }
}