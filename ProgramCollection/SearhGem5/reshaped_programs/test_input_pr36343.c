#include <stdio.h>

// Instead of abort(), we will use a standard exit mechanism
#include <stdlib.h>

void bar (int **p) {
    float *q = (float *)p;
    *q = 0.0;  // Set the dereferenced value at q to 0.0
}

float foo (int b, float f) {
    int *i = NULL;  // Initialize pointer to NULL
    int **p;
    if (b)
        p = &i;
    else
        p = (int **)&f;  // Cast float pointer to int double pointer
    bar (p);
    if (b)
        return **p;  // If b was true, dereference the p pointer
    return f;  // Otherwise, return the float value
}

int main() {
    int b = 1; // Hardcoded value since we avoid reading input
    float f = 1.0;

    if (foo(b, f) != 0.0) {
        printf("Abort triggered\n"); // Print instead of abort for clarity
        return 1; // Return non-zero on abort-like condition
    }
    return 0; // Indicate successful execution
}