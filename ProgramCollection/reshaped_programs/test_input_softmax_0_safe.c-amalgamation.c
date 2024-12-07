#include <stdio.h>
#include <math.h>
#include <assert.h>

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
    
    /* divide by the sum, i.e., make the result sum up to one */
    for(i = 0; i < n; ++i)
        y[i] /= sum;
}

int main() /* check_bounds_size_2 */
{
    float x[2] = {0.5f, 1.5f}; // Using fixed values for demonstration
    float y[2] = {0.0f, 0.0f}; // Initialize output array
    
    // Assuming values are neither NaN nor Inf
    assert(!isnan(x[0]) && !isinf(x[0]));
    assert(!isnan(x[1]) && !isinf(x[1]));
    
    softmax(x, y, 2);
    
    // Assert checks result
    assert(isgreaterequal(y[0], 0.0f)); /* Expected result: verification successful */

    // Print the results for verification
    printf("Softmax results: y[0] = %f, y[1] = %f\n", y[0], y[1]);

    return 0;
}