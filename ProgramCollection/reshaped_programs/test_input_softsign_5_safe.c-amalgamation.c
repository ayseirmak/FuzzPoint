#include <stdio.h>
#include <math.h>
#include <assert.h>

float softsign(float x)
{
    return x / (fabsf(x) + 1.0f);
}

int main() /* check_symmetry */
{
    // Deterministic input for demonstration
    float x = 1.0f; // Static value for demonstration, can be any non-negative finite float

    // Ensure the input condition directly
    if (x >= 0.0f && !isinf(x)) {
        float y = softsign(x);
        float z = -softsign(-x);

        // Using assert to verify symmetry
        assert(y == z); /* Expected result: verification successful */
    } else {
        printf("Input does not satisfy the condition.\n");
    }

    return 0;
}