#include <stdio.h>
#include <math.h>
#include <assert.h>

#define SIN_CHECK_RANGE 32.0f
#define SIN_CHECK_ERROR 1e-6f
#define SIN_CHECK_NEXT 1e-2f

int main() /* check_derivative */
{
    // Deterministically defined input value within the specified range.
    float x1 = 15.0f; // Example value within [-32.0, 32.0]
    
    // Ensure x1 is within the specified range for precision in verification
    assert(isgreaterequal(x1, -SIN_CHECK_RANGE) && islessequal(x1, SIN_CHECK_RANGE));
    
    // Calculate the next point x2
    float x2 = x1 + SIN_CHECK_NEXT;

    // Enforcing x1 to be non-negative as per original assumption
    assert(isgreaterequal(x1, 0.0f));

    // Compute sine values and the derivative approximation
    float y1 = sinf(x1);
    float y2 = sinf(x2);
    float derivative = (y2 - y1) / SIN_CHECK_NEXT;
    
    // Calculate the reference derivative using cosine
    float dref = cosf((x1 + x2) / 2.0f); // Mid-point evaluation for derivative
    float error = fabsf(derivative - dref);
    
    // Assert to verify that the error is within the permissible limit
    assert(islessequal(error, SIN_CHECK_ERROR));

    // Output the results for logging purposes
    printf("x1: %.4f, x2: %.4f, derivative: %.6f, reference derivative: %.6f, error: %.10f\n", x1, x2, derivative, dref, error);

    return 0;
}