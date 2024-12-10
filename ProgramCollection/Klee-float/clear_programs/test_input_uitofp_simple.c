#include <assert.h>
#include <stdio.h>
#include <stdint.h>

int main() {
    float x;
    uint32_t y = 100000; // Example chosen typical value for demonstration
    x = (float)y;

    // Ensure that `x` holds the floating point representation of `y` and that x is within valid limits.
    assert(x >= 0.0f);
    assert(x <= 0x1.000000p32); // x <= 2^32

    printf("Value of x: %f\n", x); // Print to demonstrate the final value
    return 0;
}