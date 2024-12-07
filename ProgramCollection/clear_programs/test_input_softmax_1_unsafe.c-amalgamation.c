#include <stdio.h>
#include <math.h>
#include <assert.h>

// Define test inputs directly
void softmax(const float* x, float* y, int n) {
    int i;
    
    // Find max input value to avoid overflow
    float max = x[0];
    for (i = 1; i < n; ++i)
        if (x[i] > max)
            max = x[i];
    
    // Compute the element-wise exponential while keeping track of their sum
    float sum = 0.0f;
    for (i = 0; i < n; ++i) {
        float z = expf(x[i] - max);
        sum += z;
        y[i] = z;
    }
    
    // Divide by the sum, i.e., make the result sum up to one
    for (i = 0; i < n; ++i)
        y[i] /= sum;
}

int main() {
    // Fixed test values to ensure deterministic behavior
    float x[2] = {0.5f, 1.5f};  // Example fixed values
    float y[2] = {0.0f, 0.0f};

    // Check preconditions manually
    assert(!isnan(x[0]) && !isinf(x[0]));
    assert(!isnan(x[1]) && !isinf(x[1]));
    
    // Perform the softmax calculation
    softmax(x, y, 2);
    
    // Post-condition assertion
    assert(islessequal(y[1], 0.9f));  // Expected result: this will ensure behavior

    // Output the result for verification
    printf("y[0]: %f, y[1]: %f\n", y[0], y[1]);

    return 0;
}