#include <stdio.h>
#include <math.h>
#include <assert.h>

void softmax(const float* x, float* y, int n) {
    int i;
    
    /* Find max input value to avoid overflow */
    float max = x[0];
    for(i = 1; i < n; ++i) {
        if(x[i] > max) {
            max = x[i];
        }
    }
    
    /* Compute the element-wise exponential while keeping track of their sum */
    float sum = 0.0f;
    for(i = 0; i < n; ++i) {
        float z = expf(x[i] - max);
        sum += z;
        y[i] = z;
    }
    
    /* Divide by the sum, i.e., make the result sum up to one */
    for(i = 0; i < n; ++i) {
        y[i] /= sum;
    }
}

#define SOFTMAX_CHECK_NEXT 1e-5f

int main() {
    float x[4], y[4];
    
    /* Deterministic inputs instead of nondeterministic */
    x[0] = 0.1f;                 // Arbitrary non-NaN, non-infinite value
    x[1] = x[0] + SOFTMAX_CHECK_NEXT;
    x[2] = 0.123456f;
    x[3] = 0.654321f;
    
    /* Ensure x[0] is neither NaN nor infinity (already deterministic) */
    assert(!isnan(x[0]) && !isinf(x[0]));
    
    softmax(x, y, 4);
    
    /* Check if y[2] is greater than or equal to y[3] */
    assert(isgreaterequal(y[2], y[3])); // Expected result: verification failure
    
    /* Optional: Print softmax results for inspection */
    printf("Softmax Outputs:\n");
    for(int i = 0; i < 4; ++i) {
        printf("y[%d] = %f\n", i, y[i]);
    }
    
    return 0;
}