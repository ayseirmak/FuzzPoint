#include <stdio.h>
#include <math.h>
#include <assert.h>

// Function for the ReLU operation
float relu(float x) {
    return fmaxf(x, 0.0f);
}

int main() {
    // Initialize x with a fixed negative value to simulate the negative domain
    float x = -3.5f;  // Example negative value to ensure it stays within the negative domain
    
    // Simulate the __VERIFIER_assume behavior by checking that x is less than or equal to 0
    assert(x <= 0.0f);

    float y = relu(x);

    // Replacing __VERIFIER_assert with standard assert
    assert(y == 0.0f);

    if (y == 0.0f) {
        printf("Verification successful: y is 0.0 as expected.\n");
    } else {
        printf("Verification failed: y is not 0.0.\n");
    }

    return 0;
}