#include <stdio.h>

void testfunc(short s, float X, char C, long long LL, int I, double D) {
    printf("%d, %f, %d, %lld, %d, %f\n", s, X, C, LL, I, D);
}

int main() {
    // Initialize and declare variables with typical test values
    short s = 42;               // Example value for short
    float X = 3.14f;            // Example value for float
    char C = 'A';               // Example value for char (ASCII value 65)
    long long LL = 123456789LL; // Example value for long long
    int I = 1000;               // Example value for int
    double D = 2.71828;         // Example value for double

    // Call the test function with the initialized variables
    testfunc(s, X, C, LL, I, D);

    return 0; // Indicate successful execution
}