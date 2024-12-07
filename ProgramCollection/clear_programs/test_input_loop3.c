#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// PI approximation
const float PI = 3.14159;

// Function to simulate the behavior of nondeterministic input
float deterministic_float() {
    // Fixed value within the range (0, PI/8) for demonstration
    return 0.1f;
}

int main() {
    // Simulated nondeterministic input
    float x = deterministic_float();
    float octant1 = 0.0f;
    float octant2 = PI / 8.0f;

    // Assuming input is in the valid range
    if (!(x > octant1 && x < octant2)) {
        // Abort if assumption not met (acts similarly to `assume_abort_if_not`)
        abort();
    }

    float oddExp = x;
    float evenExp = 1.0f;
    float term = x;
    unsigned int count = 2;
    int multFactor = 0;
    int temp = 1; // Fixed deterministic value to simulate loop continuation

    while (temp != 0) {
        term = term * (x / count);
        multFactor = ((count >> 1) % 2 == 0) ? 1 : -1;

        evenExp = evenExp + multFactor * term;

        count++;

        term = term * (x / count);

        oddExp = oddExp + multFactor * term;

        count++;

        // For deterministic behavior, we set temp to a fixed non-zero value
        // As a demonstration, let's stop the loop after one iteration
        temp = 0;
    }

    // Assert the condition using standard assert
    assert(evenExp >= oddExp);

    return 0;
}