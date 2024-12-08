#include <math.h>
#include <assert.h>
#include <stdio.h>

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

#define SOFTMAX_CHECK_ERROR 1e-5f

int main() /* check_unitary_sum_size_2 */ {
    float x[2], y[2];

    // Fixed deterministic inputs
    x[0] = 1.0f;
    x[1] = 2.0f;
    
    softmax(x, y, 2);
    
    int i;
    float sum = 0.0f;
    for(i = 0; i < 2; ++i)
        sum += y[i];
    
    float diff = fabsf(sum - 1.0f);

    // Using standard C assertion
    assert(islessequal(diff, SOFTMAX_CHECK_ERROR));

    // Output logs for verification purposes
    printf("Sum of softmax outputs: %.6f\n", sum);
    printf("Difference from 1: %.10f\n", diff);
    printf("Softmax results: y[0]: %.6f, y[1]: %.6f\n", y[0], y[1]);

    return 0;
}