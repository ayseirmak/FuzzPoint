#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdbool.h>

void softmax(const float* x, float* y, int n)
{
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

int main() /* check_non_decreasing_size_4 */
{
    float x[4], y[4];

    // Deterministic initialization of input values
    x[0] = 0.5f;  // Fixed value replacing nondeterministic input
    x[1] = x[0] + 1e-5f;
    x[2] = 0.123456f;
    x[3] = 0.654321f;
    
    assert(!isnan(x[0]) && !isinf(x[0]));  // Standard assertion replacing __VERIFIER_assume

    softmax(x, y, 4);

    assert(y[0] <= y[1]); /* Expected result: verification successful */
    printf("Assertions passed.\n");

    return 0;
}