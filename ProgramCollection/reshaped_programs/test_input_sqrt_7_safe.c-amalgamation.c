#include <math.h>
#include <stdio.h>
#include <assert.h>

#define SQRT_CHECK_ERROR 1e-5f

int main() {
    // Deterministic input value for x
    float x = 4.0f; // Change this value accordingly for different test cases
   
    // Ensure x is within defined constraints
    if (!(isgreaterequal(x, 0.0f) && !isinf(x))) {
        printf("Precondition not satisfied: x must be non-negative and finite.\n");
        return 1;
    }

    float y = sqrtf(x);
    float z = y * y;
    float r = fabsf(x - z) / (x + 1e-37f); // Relative error, avoid division by zero

    // Check assertion with standard assert
    assert(islessequal(r, SQRT_CHECK_ERROR));
    
    printf("Verification successful: The calculated error %f is within the acceptable range.\n", r);

    return 0;
}