#include <stdio.h>

int main() {
    const float x = 0.5f;
    const double y = 0.75;

    // Print the values of x and y using standard printf for float and double
    printf("x: %.1E\n", x); // Exponential form
    printf("y: %.1E\n", y); // Exponential form

    return 0;
}