#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

int main() {
    // Initialize variables with a test value to replace the command line input
    volatile double a = 32.0;  // example value for testing purposes
    double c = pow(a, 1.0 / 3.0);

    if (c + 0.1 > 3.174802 && c - 0.1 < 3.174802) {
        printf("Condition passed, exiting successfully.\n");
        return 0;
    } else {
        printf("Condition failed, aborting.\n");
        assert(0);  // Assert triggers failure if the condition is not met
    }

    return 0;  // Ensure that the function returns 0
}