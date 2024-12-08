#include <stdio.h>
#include <stdlib.h>

int main() {
    // Initialize the variable x with a fixed hexadecimal floating-point value.
    double x = 0x1.fp1;  // This is equivalent to 3.875 in decimal.

    // Check if the value of x is not equal to 3.875
    if (x != 3.875) {
        printf("Error: x is not equal to 3.875. Exiting program.\n");
        exit(EXIT_FAILURE);  // Use exit instead of abort for clarity.
    } else {
        printf("Success: x is correctly equal to 3.875.\n");
    }

    return 0;
}