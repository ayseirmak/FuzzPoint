#include <stdio.h>
#include <math.h>
#include <assert.h>

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

int main()
{
    // Initialize input array with fixed values
    float x[4] = {0.5f, 1.0f, 1.5f, 2.0f};
    float y[4];

    for (int i = 0; i < 4; ++i) {
        // Ensure inputs are neither NaN nor Inf
        assert(!isnan(x[i]) && !isinf(x[i]));
    }

    // Call the softmax function
    softmax(x, y, 4);

    // Assert to verify expected result
    assert(islessequal(y[2], 1.0f));

    // Print the results for visualization
    printf("Softmax Results:\n");
    for (int i = 0; i < 4; ++i) {
        printf("y[%d] = %f\n", i, y[i]);
    }

    return 0;
}