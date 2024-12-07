#include <stdio.h>
#include <stdlib.h>  // Optional for fixed float values
#include <math.h>
#include <assert.h>  // For assertion

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
    
    /* divide by the sum, i.e., make the result sum up to one */
    for(i = 0; i < n; ++i)
        y[i] /= sum;
}

int main() {
    float x[4], y[4];

    // Assign fixed values, replace nondet floats, ensuring no NaN or Inf
    x[0] = 0.1f;
    x[1] = 0.5f;
    x[2] = -0.3f;
    x[3] = 0.7f;

    // No assumptions needed since these values are pre-decided and valid

    softmax(x, y, 4);
    
    int i;
    float sum = 0.0f;
    for(i = 0; i < 4; ++i)
        sum += y[i];
    
    // Use assert to check the sum instead of custom verifier functions
    assert(fabsf(sum - 1.0f) < 1e-6);  // Tolerate small floating-point errors

    printf("Sum is approximately %f\n", sum);

    return 0;
}