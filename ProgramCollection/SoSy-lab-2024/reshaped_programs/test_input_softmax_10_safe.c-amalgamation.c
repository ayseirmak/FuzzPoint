#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>

void softmax(const float* x, float* y, int n) {
    int i;

    /* find max input value to avoid overflow */
    float max = x[0];
    for(i = 1; i < n; ++i)
        if(x[i] > max)
            max = x[i];

    /* compute the element-wise exponential while keeping track of their sum */
    float sum = 0.0f;
    for(i = 0; i < n; ++i) {
        float z = expf(x[i] - max);
        sum += z;
        y[i] = z;
    }

    /* divide by the sum, i.e. make the result sum up to one */
    for(i = 0; i < n; ++i)
        y[i] /= sum;
}

#define SOFTMAX_CHECK_NEXT 1e-5f

int main() {
    float x[2], y[2];

    // Deterministic input instead of nondet
    x[0] = 1.0f;  // Example fixed value
    x[1] = x[0] + SOFTMAX_CHECK_NEXT;

    // Assumption translated into an assertion for deterministic value
    assert(!isnan(x[0]) && !isinf(x[0]));

    softmax(x, y, 2);

    // Assert using standard assertion logic
    assert(islessequal(y[0], y[1])); /* Expected result: verification successful */

    printf("Softmax computed successfully and assertion passed.\n");

    return 0;
}