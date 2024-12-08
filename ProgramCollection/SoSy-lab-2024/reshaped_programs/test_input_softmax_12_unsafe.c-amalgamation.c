#include <stdio.h>
#include <math.h>
#include <assert.h>

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

    // Divide by the sum, i.e. make the result sum up to one
    for(i = 0; i < n; ++i) {
        y[i] /= sum;
    }
}

#define SOFTMAX_CHECK_NEXT 1e-5f

int main() {
    float x[4], y[4];

    // Deterministic inputs
    x[0] = 0.1f;  // Replace nondeterministic input with fixed value
    x[1] = x[0] + SOFTMAX_CHECK_NEXT;
    x[2] = 0.123456f;
    x[3] = 0.654321f;

    // Ensure input is neither NaN nor infinity
    assert(!isnan(x[0]) && !isinf(x[0]));

    // Calculate softmax
    softmax(x, y, 4);

    // Replace verifier assertion with a standard assertion
    assert(islessequal(y[0], y[2]));

    return 0;
}