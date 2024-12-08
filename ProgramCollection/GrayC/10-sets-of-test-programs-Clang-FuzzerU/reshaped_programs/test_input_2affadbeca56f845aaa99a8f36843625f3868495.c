#include <stdio.h>  // Include necessary for printf
#include <stdlib.h> // Include necessary for abort and exit

int main() {
    long double x;

    // Initialize x
    x = 0x1.0p-500L;

    // Fixed value assignment
    x = 0x1.0p-522L;

    // Check calculation and use standard assert-style debugging
    if (x != 0x1.0p-1022L) {
        printf("Assertion failed: The value of x is incorrect.\n");
        abort();
    }

    // Exit successfully
    printf("All assertions succeeded.\n");
    exit(0);
}