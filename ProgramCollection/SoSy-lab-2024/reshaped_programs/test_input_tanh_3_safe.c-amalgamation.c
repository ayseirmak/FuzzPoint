#include <stdio.h>
#include <math.h>
#include <assert.h>

#define TANH_CHECK_NEXT 1e-2f

int main() {
    // Assign a fixed value for x1
    float x1 = 0.5;  // A predetermined value, for example
    float x2 = x1 + TANH_CHECK_NEXT;

    // Assume x1 is not NaN
    assert(!isnan(x1));

    float y1 = tanhf(x1);
    float y2 = tanhf(x2);
    float derivative = (y2 - y1) / TANH_CHECK_NEXT;

    // Assert to check if the derivative is less than or equal to 1.0
    assert(islessequal(derivative, 1.0f));

    // Print the result to standard output for verification purposes
    printf("x1: %f, y1: %f, y2: %f, derivative: %f\n", x1, y1, y2, derivative);
    
    return 0;
}