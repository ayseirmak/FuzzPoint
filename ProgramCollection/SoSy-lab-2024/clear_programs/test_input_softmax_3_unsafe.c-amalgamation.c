#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdbool.h>

// Softmax function definition
void softmax(const float* x, float* y, int n)
{
    int i;

    // Find the max input value to avoid overflow
    float max = x[0];
    for(i = 1; i < n; ++i)
        if(x[i] > max)
            max = x[i];

    // Compute the element-wise exponential while keeping track of their sum
    float sum = 0.0f;
    for(i = 0; i < n; ++i) {
        float z = expf(x[i] - max);
        sum += z;
        y[i] = z;
    }

    // Divide by the sum, i.e. make the result sum up to one
    for(i = 0; i < n; ++i)
        y[i] /= sum;
}

// Function to check if a number is neither NaN nor infinity
bool is_valid_number(float num) {
    return !isnan(num) && !isinf(num);
}

int main() // check_bounds_size_4
{
    // Define fixed values for x (deterministic input)
    float x[4] = {1.0, 2.0, 0.5, 0.0};
    float y[4] = {0.0, 0.0, 0.0, 0.0}; // Ensure y is initialized

    // Assume x values are valid, which is already ensured with fixed values
    assert(is_valid_number(x[0]));
    assert(is_valid_number(x[1]));
    assert(is_valid_number(x[2]));
    assert(is_valid_number(x[3]));

    // Apply the softmax function
    softmax(x, y, 4);

    // Check post-condition
    assert(y[1] >= 0.1f); // Expected result: verification failure

    // Print result
    printf("Softmax results: [ ");
    for(int i = 0; i < 4; ++i) {
        printf("%f ", y[i]);
    }
    printf("]\n");

    return 0;
}