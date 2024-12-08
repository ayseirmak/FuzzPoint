#include <stdio.h>
#include <stdlib.h>

// Initialize the array 'a' with 6 elements, where only the first three are set explicitly.
double a[6] = {0.0, 1.0, 2.0, 0.0, 0.0, 0.0};

// Function 'bar' checks the input conditions
void bar(int x, double *y) {
    if (x || *y != 1.0) {
        abort(); // If conditions are true, abort the program
    }
}

int main() {
    double c = 1.0; // Initialize 'c' to a fixed value for deterministic behavior
    int d = 0;      // Initialize 'd' to a fixed value

    for (d = 0; d < 6; d++) {
        // Only call bar if the condition is met to make it deterministic
        if (d == 1) {
            bar(d, &a[d]);
        }
    }

    printf("Program completed without abort\n");
    return 0;
}