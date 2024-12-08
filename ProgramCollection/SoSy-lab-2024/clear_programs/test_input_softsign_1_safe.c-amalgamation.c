#include <stdio.h>
#include <math.h>
#include <assert.h>

float softsign(float x) {
    return x / (fabsf(x) + 1.0f);
}

int main() {
    // Using a deterministic value for x
    float x = 0.75f;

    // Directly assuming x is not NaN or Inf, as per the problem requirement
    assert(!isnan(x) && !isinf(x));
    
    float y = softsign(x);

    // Verify that y is less than or equal to 1
    assert(islessequal(y, 1.0f));

    // For testing purposes, log the result
    printf("For x = %.2f, softsign(x) = %.2f\n", x, y);

    return 0;
}