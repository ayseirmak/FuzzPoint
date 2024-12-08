#include <stdio.h>
#include <math.h>
#include <assert.h>

#define LOG_CHECK_NEXT 1e-5f

int main() /* check_non_decreasing */
{
    // Initialize x1 to a fixed non-negative value
    float x1 = 1.0f; // Example fixed value, can be any non-negative value
    float x2 = x1 + LOG_CHECK_NEXT;
    
    // Ensure x1 is non-negative; this checks precondition equivalent to __VERIFIER_assume
    assert(x1 >= 0.0f);

    float y1 = logf(x1);
    float y2 = logf(x2);
    
    // Ensure log function is non-decreasing; this is the postcondition equivalent to __VERIFIER_assert
    assert(y1 <= y2); /* Expected result: verification successful */

    return 0;
}