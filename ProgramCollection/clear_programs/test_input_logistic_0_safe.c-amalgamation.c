#include <stdio.h>
#include <math.h>
#include <assert.h>

// Replacing nondeterministic input with a fixed deterministic value
#define FIXED_FLOAT_INPUT 0.1f // You can change this to any specific test value

float logistic(float x) {
    return 0.5f * tanhf(0.5f * x) + 0.5f;
}

int main() {
    // Initialize variable with a deterministic input
    float x = FIXED_FLOAT_INPUT;
    
    // Ensure x is not NaN using a logical condition
    if (!isnan(x)) {
        float y = logistic(x);

        // Use standard assert to verify the desired property
        assert(isgreaterequal(y, 0.0f));
        
        // Optional: print the output to verify results
        printf("Logistic function result for x = %f is y = %f\n", x, y);
        printf("Assertion passed: y (%.2f) is greater than or equal to 0.0\n", y);
    } else {
        printf("Invalid input: x is NaN\n");
    }
    
    return 0;
}