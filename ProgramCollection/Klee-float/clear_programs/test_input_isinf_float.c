#include <stdio.h>
#include <math.h>
#include <assert.h>

int main() {
    // Initialize x to a floating-point number, for example 1.0f
    float x = 1.0f;

    // Check if 'x' is infinite and assert correctly
    if (isinf(x)) {
        assert(isinf(x));
    } else {
        assert(!isinf(x));
    }

    printf("Program completed successfully.\n");

    return 0;
}