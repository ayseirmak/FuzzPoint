#include <math.h>
#include <assert.h>
#include <stdio.h>

int main() {
    // Deterministic value for testing, instead of using nondeterministic input
    float x = 1.0f;

    // Assumption is hardcoded by choosing the value of x appropriately
    assert(isgreaterequal(x, 0.0f));

    // Compute the error functions
    float y = erff(x);
    float z = -erff(-x);

    // Assert the symmetry property
    assert(y == z);

    // Log the results
    printf("For x = %f, erff(x) = %f and -erff(-x) = %f\n", x, y, z);
    printf("Assertion passed: y == z\n");

    return 0;
}