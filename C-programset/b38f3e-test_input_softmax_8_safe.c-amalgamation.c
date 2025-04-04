#include <stdio.h>
#include <math.h>
#include <stdbool.h>

// Function to perform softmax operation
void softmax(const float* x, float* y, int n)
{
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

#define SOFTMAX_CHECK_ERROR 1e-5f

// Function to simulate assumed behavior
bool is_assumed_valid(float val) {
    return !isnan(val) && !isinf(val);
}

int main() /* Check unitary sum size 4 */
{
    float x[4] = {1.0f, 2.0f, 3.0f, 4.0f}; // Fixed deterministic inputs
    float y[4];
   
    // Replace __VERIFIER_assume with C logic
    if (!is_assumed_valid(x[0]) || !is_assumed_valid(x[1]) ||
        !is_assumed_valid(x[2]) || !is_assumed_valid(x[3])) {
        printf("Precondition assumptions failed. Exiting.\n");
        return 1;
    }

    softmax(x, y, 4);

    int i;
    float sum = 0.0f;
    for(i = 0; i < 4; ++i) {
        sum += y[i];
    }

    float diff = fabsf(sum - 1.0f);

    // Replace __VERIFIER_assert with standard assertion
    if (diff <= SOFTMAX_CHECK_ERROR) {
        printf("Verification successful: Sum is roughly 1.0 with diff = %.8f\n", diff);
    } else {
        printf("Verification failed: Sum is not roughly 1.0 with diff = %.8f\n", diff);
    }

    return 0;
}