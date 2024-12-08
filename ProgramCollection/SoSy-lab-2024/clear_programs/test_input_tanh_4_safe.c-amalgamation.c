#include <stdio.h>
#include <math.h>
#include <assert.h>

#define TANH_CHECK_NEXT 1e-2f

int main() /* check_derivative */
{
    // Initialize x1 with a fixed deterministic value
    float x1 = 0.5f;  // Example fixed value for x1
    float x2 = x1 + TANH_CHECK_NEXT;
    
    // Ensure x1 is not NaN using an assert (though in a fixed world, it's unnecessary)
    assert(!isnan(x1));
    
    float y1 = tanhf(x1);
    float y2 = tanhf(x2);
    float derivative = (y2 - y1) / TANH_CHECK_NEXT;
    
    // Use assert to check the condition
    assert(isgreaterequal(derivative, 0.0f)); /* Expected result: verification successful */

    return 0;
}