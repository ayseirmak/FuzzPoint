#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

float fx(float x) {
    return 1.0 + 3.0 / (2.302585093 * x);
}

int main() {
    // Initialize variables
    float a = 3.0;
    float c = 4.0;

    // Calculate b using the fx function and values of a and c
    float b = fx(c) + a;

    // Perform assertion checks instead of using abort() to handle conditions
    assert(a == 3.0);
    assert(b >= 4.3257 && b <= 4.3258);
    assert(c == 4.0);

    // Confirmation output to indicate successful execution
    printf("All conditions are met.\n");

    return 0; // Indicate successful execution
}