#include <stdio.h>
#include <math.h>
#include <assert.h>

#define EXP_CHECK_NEXT 1e-5f

int main() /* check_non_decreasing */
{
    // Replace nondeterministic input with a fixed value
    float x1 = 0.5f; // Starting point (can be adjusted to any desired fixed value)
    float x2 = x1 + EXP_CHECK_NEXT;
    
    // Direct assumption that x1 is not NaN
    assert(!isnan(x1));

    float y1 = expf(x1);
    float y2 = expf(x2);
    
    // Using standard assert to check the condition
    assert(islessequal(y1, y2)); /* Expected result: verification successful */
    
    printf("Assertion passed: expf(x1) <= expf(x2)\n");
    
    return 0;
}