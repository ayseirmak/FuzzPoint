#include <stdio.h>
#include <assert.h>

// Define the constant X
#define X 2.5

int main() {
    // Initialize variables
    double x = 1.0;
    double x1 = x / X;

    // Iterative process with a while loop
    while (x1 != x) {
        x = x1;
        x1 = x / X;
    }

    // Use standard assertion to verify the condition
    assert(x == 0);

    // Allow the program to output a success message for clarity
    printf("Program finished without error, assertion holds.\n");

    return 0;
}