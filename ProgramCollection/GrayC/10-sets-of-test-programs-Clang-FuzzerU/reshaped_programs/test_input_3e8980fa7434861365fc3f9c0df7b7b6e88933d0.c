#include <stdio.h>
#include <stdlib.h>

__attribute__((noinline, noclone)) double foo(double x) {
    double t;
    switch ((int)x) {
        case 0:
            t = 2 * x - 1;
            return 0.70878e-3 + 
                   (0.71234e-3 + 
                   (0.35779e-5 + 
                   (0.17403e-7 + 
                   (0.81710e-10 + 
                   (0.36885e-12 + 0.15917e-14 * t) * t) * t) * t) * t) * t;
            // Cases for 1 to 89 are similar and omitted for brevity
        case 78:
            t = 2 * x - 157;
            return 0.40282e0 + 
                   (0.79762e-2 + 
                   (0.89909e-4 + 
                   (0.79687e-6 + 
                   (0.55989e-8 + 
                   (0.30866e-10 + 0.12868e-12 * t) * t) * t) * t) * t) * t;
        default:
            return 1.0;
    }
}

int main() {
    // Providing a deterministic input for the function "foo"
    double x = 78.4; 
    double d = foo(x); // This should match the case 78 logic

    // Print the result of the computation
    printf("Result: %f\n", d);

    // Check if the output is within a specified range and abort if not
    if (d < 0.38 || d > 0.42) {
        printf("Computation out of expected range. Aborting.\n");
        abort(); // Use standard abort instead of __builtin_abort for clarity
    }
    return 0;
}