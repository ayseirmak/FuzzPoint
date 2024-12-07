#include <stdio.h>
#include <assert.h>

#define X 2.5

int main() {
    double x = 1.0; // Initial value of x
    double x1 = x/X; // Calculate initial x1

    // Loop to update x and x1 until they are equal
    while(x1 != x) {
        x = x1; // Update x to current x1
        x1 = x/X; // Calculate new x1
    }

    // Assert that x is zero, this condition will obviously not hold
    assert(x == 0);

    // Output the final value of x
    printf("Final value of x: %f\n", x);

    return 0;
}