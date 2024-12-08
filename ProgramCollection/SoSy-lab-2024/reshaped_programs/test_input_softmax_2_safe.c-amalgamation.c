#include <stdio.h>
#include <math.h>
#include <assert.h>

// Function to calculate softmax
void softmax(const float* x, float* y, int n) {
    int i;

    // Find max input value to avoid overflow
    float max = x[0];
    for(i = 1; i < n; ++i) {
        if(x[i] > max) {
            max = x[i];
        }
    }

    // Compute the element-wise exponential while keeping track of their sum
    float sum = 0.0f;
    for(i = 0; i < n; ++i) {
        float z = expf(x[i] - max);
        sum += z;
        y[i] = z;
    }

    // Divide by the sum, i.e., make the result sum up to one
    for(i = 0; i < n; ++i) {
        y[i] /= sum;
    }
}

int main() {
    // Fixed values for deterministic input
    float x[4] = {1.0f, 2.0f, 3.0f, 4.0f};
    float y[4];

    // Calculate softmax
    softmax(x, y, 4);

    // Assert that the output is a valid probability distribution
    assert(isgreaterequal(y[0], 0.0f));

    // Print the softmax result for verification
    for(int i = 0; i < 4; i++) {
        printf("y[%d] = %f\n", i, y[i]);
    }

    return 0;
}