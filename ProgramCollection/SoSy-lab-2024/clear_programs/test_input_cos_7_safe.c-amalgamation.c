#include <stdio.h>
#include <assert.h>
#include <math.h>

int main() /* check_symmetry */
{
    // Fixed deterministic value for x
    float x = 1.0f; // This value can be any non-negative finite float
    
    // Ensure the assumptions are met
    assert(isgreaterequal(x, 0.0f) && !isinf(x));
    
    float y = cosf(x);
    float z = cosf(-x);
    
    // Assert the expected symmetry property
    assert(y == z); /* Expected result: verification success */
    
    printf("Assertion succeeded; y = %f, z = %f\n", y, z);

    return 0;
}