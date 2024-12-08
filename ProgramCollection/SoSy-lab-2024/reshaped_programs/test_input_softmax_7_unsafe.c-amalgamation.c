// SPDX-License-Identifier: MIT

#include <stdio.h>
#include <math.h>
#include <assert.h>

void softmax(const float* x, float* y, int n) {
    int i;

    /* find max input value to avoid overflow */
    float max = x[0];
    for (i = 1; i < n; ++i) {
        if (x[i] > max) {
            max = x[i];
        }
    }

    /* compute the element-wise exponential while keeping track of their sum */
    float sum = 0.0f;
    for (i = 0; i < n; ++i) {
        float z = expf(x[i] - max);
        sum += z;
        y[i] = z;
    }

    /* divide by the sum, i.e. make the result sum up to one */
    for (i = 0; i < n; ++i) {
        y[i] /= sum;
    }
}

int main() /* check_unitary_sum_size_2 */ {
    float x[2] = {0.5f, 0.3f}; // Fixed deterministic input
    float y[2] = {0.0f, 0.0f};
    
    // Assuming inputs are valid (e.g., not NaN or Infinite)
    softmax(x, y, 2);

    int i;
    float sum = 0.0f;
    for (i = 0; i < 2; ++i) {
        sum += y[i];
    }

    assert(sum == 1.0f); /* Expected outcome: verification failure */
 
    return 0;
}