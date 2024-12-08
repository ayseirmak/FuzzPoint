#include <stdio.h>
#include <math.h>
#include <assert.h>

// This function calculates the ReLU (Rectified Linear Unit) of a number
float relu(float x) {
    return fmaxf(x, 0.0f);
}

int main() {
    // Deterministically set a positive value for `x`
    float x = 5.0f;  // Use any non-negative value you consider appropriate

    // Calculate the ReLU of x
    float y = relu(x);

    // Assert that the ReLU of x is equal to x itself because x is non-negative
    assert(y == x);

    // Output the result for verification
    printf("ReLU(%f) = %f\n", x, y);

    return 0;
}