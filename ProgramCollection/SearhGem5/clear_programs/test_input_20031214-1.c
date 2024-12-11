#include <stdio.h>

// Structure definition with initialization
struct {
    double a;
    int n[2];
} g = {0.0, {1, 2}};

// Global variable initialization
int k = 0;

// Function b with pointer parameter, not used in modified version
void b(int *j) {
    // Intentionally left empty
}

int main() {
    // Initialize integer j
    int j;

    // Fixed loop count replacing command line argument
    int fixedCount = 2;

    // Use of fixed loop and computation instead of `argc` and `atoi(argv[1])`
    for (j = 0; j < fixedCount; j++) {
        k = (k > g.n[j]) ? k : g.n[j];
    }

    // Increment k after the loop
    k++;

    // Call to function b with the address of j
    b(&j);

    // Print output for verification
    printf("Final value of k: %d\n", k);

    // Return 0 to indicate successful execution
    return 0;
}