#include <stdio.h>

void test(double X) {
    printf("%f %f\n", -0.0 - X, -X);
}

int main() {
    // Initialize a variable for testing
    double X = 5.0;  // An example value for demonstration

    // Call test with both positive and negative zero
    test(+0.0);
    test(-0.0);

    // Print the negative and positive zero
    printf("negzero = %f  poszero = %f\n", -0.0, +0.0);

    // Indicate successful completion
    return 0;
}