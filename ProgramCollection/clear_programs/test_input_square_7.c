#include <assert.h>
#include <stdio.h>

// Function to simulate an approximate square root calculation (1 + x approximation)
float calculate_sqrt_approx(float x) {
    return 1.0f + 0.5f * x - 0.125f * x * x + 0.0625f * x * x * x - 0.0390625f * x * x * x * x;
}

// Error function to be called when a condition fails
void reach_error() {
    assert(0);
}

// Main function
int main() {
    // Initialize input with a fixed, deterministic value
    float IN = 0.5f;
    
    // Constant value determined by the preprocessor directive in the original code
    const float VAL = 1.4f;

    // Assert that the input conforms to the required range
    if (!(IN >= 0.0f && IN < 1.0f)) {
        return 1; // Terminate the program if input is out of range
    }

    // Calculate the approximate square root value
    float result = calculate_sqrt_approx(IN);

    // Check if the result is within the expected range
    if (!(result >= 0.0f && result < VAL)) {
        reach_error();
    }

    // Output the result
    printf("The result of the approximation is: %f\n", result);

    return 0;
}