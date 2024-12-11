#include <stdio.h>
#include <stdlib.h>

int main() {
    // Initialize and declare variables with fixed values
    double x = 5.0;  // example edge value to reflect typical use or edge cases
    double y = 6.0;  // example edge value to reflect typical use or edge cases

    // Replace the custom abort and exit with a standard output
    if ((y > x--) != 1) {
        printf("Condition failed\n");
    } else {
        printf("Condition passed\n");
    }

    return 0;
}