#include <stdio.h>
#include <math.h>
#include <assert.h>

#define ERF_CHECK_NEXT 1e-5f

int main() /* check_non_decreasing */
{
    // Give 'x1' a fixed deterministic value
    float x1 = 0.5f; // Example choice; adjust as needed for different tests
    float x2 = x1 + ERF_CHECK_NEXT;

    // Ensure x1 is not NaN
    assert(!isnan(x1));

    float y1 = erff(x1);
    float y2 = erff(x2);

    // Assert that the erf function is non-decreasing
    assert(islessequal(y1, y2)); /* Expected result: verification successful */
    
    printf("Assertions passed, the logic holds.\n");

    return 0;
}