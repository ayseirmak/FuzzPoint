#include <stdio.h>  // For standard input/output functions
#include <math.h>   // For mathematical functions like tanhf
#include <assert.h> // For assertions

int main() {
    // Initialize x with a fixed deterministic value that is not NaN
    float x = 0.5f; // Example fixed input value
    
    // Ensure x is not NaN; if it were, this would be a logical error in this setup
    if (isnan(x)) {
        printf("Error: x should not be NaN.\n");
        return 1;
    }

    // Calculate hyperbolic tangent of x
    float y = tanhf(x);

    // Assert that y is less than or equal to 1.0f
    assert(islessequal(y, 1.0f));

    printf("Verification successful: y = %f is less than or equal to 1.0f\n", y);

    return 0;
}