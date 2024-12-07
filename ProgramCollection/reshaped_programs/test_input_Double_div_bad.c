#include <stdio.h>
#include <assert.h>

// Adjusted to use standard assert directly and avoid custom verifier functions

int main() {
    // Initialize and define fixed constant
    double x = 1.0;
    double x1 = x / 2.5;  // Updated as per the original comment

    // Fixed deterministic behavior
    while (x1 != x) {
        x = x1;
        x1 = x / 2.5;
    }

    // Standard assert to check condition
    assert(x == 0);

    // Log a message to confirm program end
    printf("Program reached end without assert failure.\n");

    return 0;
}