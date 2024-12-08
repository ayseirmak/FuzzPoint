#include <stdio.h>
#include <math.h>
#include <assert.h>

int main() /* check_upper_bound */
{
    // Fixed input value for x, for demonstration, using 0.0 as a deterministic value
    float x = 0.0f; 

    // Ensuring x is neither NaN nor infinity
    if (isnan(x) || isinf(x)) {
        printf("Invalid input for x: x cannot be NaN or Infinity\n");
        return 1;
    }
    
    // Calculate cosine of x
    float y = cosf(x);

    // Assertion to ensure the result is less than or equal to 1.0f
    assert(islessequal(y, 1.0f));

    // Log output result for debug purposes
    printf("cosf(%f) = %f is within [ -1.0, 1.0 ]\n", x, y);

    return 0;
}