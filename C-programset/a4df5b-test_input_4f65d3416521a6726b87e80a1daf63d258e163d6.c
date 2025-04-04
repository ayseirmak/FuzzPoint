#include <stdio.h>
#include <stdlib.h>

int main() {
    long double x; // Declare and initialize

    // Initialize x with a deterministic calculation
    x = 0x1.0p-500L;
    x *= 0x1.0p-522L;

    // Verify if the calculated x matches the expected value
    if (x != 0x1.0p-1022L) {
        printf("Error: Calculation did not meet the expected value.\n");
        abort(); // Abort the program if the condition is not met
    }

    printf("Calculation successful, the value is as expected.\n"); // Log success message
    return 0; // Successful termination
}