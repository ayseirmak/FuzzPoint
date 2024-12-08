#include <stdio.h>
#include <math.h>
#include <assert.h>

float softsign(float x) {
    return x / (fabsf(x) + 1.0f);
}

#define SOFTSIGN_CHECK_NEXT 1e-5f

int main() {
    // Initialize x1 with a fixed value
    float x1 = 0.5f;  // Example fixed value
    float x2 = x1 + SOFTSIGN_CHECK_NEXT;
    
    // Assume condition directly translated
    if (!isnan(x1) && !isinf(x1)) {
        float y1 = softsign(x1);
        float y2 = softsign(x2);
        
        // Use standard assert to check, logging with printf if needed for debugging
        printf("y1: %f, y2: %f\n", y1, y2);
        assert(islessequal(y1, y2)); // Expected result: verification failure
    }

    return 0;
}