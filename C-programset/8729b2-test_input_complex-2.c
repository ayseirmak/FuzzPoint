#include <stdio.h>
#include <complex.h>

double complex f(double complex x, double complex y) {
    x += y;
    return x;
}

int main() {
    // Initialize variables with fixed values.
    double complex ag = 1.0 + 2.0 * I;
    double complex bg = 3.0 + 4.0 * I;
    double complex a, b, c;

    a = ag;
    b = 5.0 + 6.0 * I;
    c = f(a, b);

    // Use assertions to verify expected values.
    // The expected values are set to align with the initialized variables
    // and the operation performed in function `f`.
    if (a != (1.0 + 2.0 * I)) {
        printf("Assertion failed: a != 1.0 + 2.0 * I\n");
    }
    if (b != (5.0 + 6.0 * I)) {
        printf("Assertion failed: b != 5.0 + 6.0 * I\n");
    }
    if (c != (6.0 + 8.0 * I)) {
        printf("Assertion failed: c != 6.0 + 8.0 * I\n");
    }

    return 0; // Indicate successful execution
}