#include <stdio.h>

// Function g takes two void pointers, two integers, and a float, and returns the float.
float g(void *a, void *b, int e, int c, float d) {
    return d;
}

// Function f calls function g with an additional integer parameter set to zero.
float f(void *a, void *b, int c, float d) {
    return g(a, b, 0, c, d);
}

int main() {
    // Initialize dummy pointers to avoid uninitialized variables
    void *a = NULL;
    void *b = NULL;
    // Initialize values for c and d to specific test case
    int c = 42;        // Assigning a placeholder integer value for testing
    float d = 3.14;    // Assigning a placeholder float value for testing

    // Call function f with initialized values
    float result = f(a, b, c, d);
    printf("Result: %f\n", result);

    return 0;
}