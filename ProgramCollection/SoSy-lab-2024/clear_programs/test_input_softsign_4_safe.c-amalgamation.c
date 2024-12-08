#include <stdio.h>
#include <math.h>
#include <assert.h>

float softsign(float x) {
    return x / (fabsf(x) + 1.0f);
}

#define SOFTSIGN_CHECK_NEXT 1e-1f
#define SOFTSIGN_CHECK_ERROR 1e-3f

int main() {
    // Initializing a deterministic value for x1
    float x1 = 1.5f; // Example fixed value
    float x2 = x1 + SOFTSIGN_CHECK_NEXT;
    
    // Checking assumptions to mimic __VERIFIER_assume behavior
    if (!isnan(x1) && !isinf(x1)) {
        float y1 = softsign(x1);
        float y2 = softsign(x2);
        float derivative = (y2 - y1) / SOFTSIGN_CHECK_NEXT;
        
        // Assert to replace __VERIFIER_assert
        assert(isgreaterequal(derivative, -SOFTSIGN_CHECK_ERROR));
        
        printf("Derivative check passed: %f\n", derivative);
    } else {
        printf("Invalid input value: x1 is NaN or Inf\n");
    }

    return 0;
}