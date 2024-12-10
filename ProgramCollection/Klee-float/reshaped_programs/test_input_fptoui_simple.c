#include <assert.h>
#include <stdio.h>

int main() {
    // Initialize the variable 'x' with a value between 1.0 and 128.0 to mimic the klee constraints
    float x = 2.5f; // Example value in range (can change based on test requirements)
    unsigned int y;

    // Convert 'x' to an unsigned int
    y = (unsigned int)x;

    // Assert that y is greater than 0 and less than 128
    assert(y > 0);
    assert(y < 128);

    // Print the values for manual verification
    printf("x: %f, y: %u\n", x, y);

    return 0;
}