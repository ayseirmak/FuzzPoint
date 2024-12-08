#include <math.h>
#include <assert.h>
#include <stdio.h>

int main() {
    // Use a fixed value for x within the domain of tanhf
    float x = 0.5f;

    // Compute tanh(x) and -tanh(-x) to check for symmetry
    float y = tanhf(x);
    float z = -tanhf(-x);

    // Assert that y and z are equal, indicating symmetry
    assert(y == z); // Expected result: verification successful

    // Print result for logs
    printf("x: %f, y: %f, z: %f, Assertion passed\n", x, y, z);

    return 0;
}