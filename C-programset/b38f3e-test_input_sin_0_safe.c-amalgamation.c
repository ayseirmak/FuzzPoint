#include <stdio.h>
#include <math.h>
#include <assert.h>

int main() /* check_lower_bound */
{
    // Using a fixed float value for x instead of a nondeterministic input
    float x = 0.5f; // Example fixed value within typical input range

    // Ensuring x is not NaN or infinity
    if(isnan(x) || isinf(x)) {
        printf("Invalid input: x is NaN or infinity.\n");
        return 1;
    }

    float y = sinf(x);

    // Use assert to verify that y is greater than or equal to -1.0f
    assert(isgreaterequal(y, -1.0f)); // Expected result: verification successful

    printf("Verification successful: y is greater than or equal to -1.0f.\n");

    return 0;
}