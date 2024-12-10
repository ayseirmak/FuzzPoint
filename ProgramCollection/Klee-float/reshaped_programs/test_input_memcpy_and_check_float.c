#include <stdio.h>
#include <string.h>
#include <math.h>
#include <assert.h>

#define EXP_MASK 0x7f800000
#define SIGNIFICAND_MASK 0x007fffff

int main() {
    // Initialize the float with a specific value for testing purposes
    float f = NAN;  // Example initialization to test NaN behavior

    // Ensure that 'f' leads to an expression of type float
    f = f + 1;

    int x = 0;
    memcpy(&x, &f, sizeof(float));

    // Copy back
    float g;
    memcpy(&g, &x, sizeof(float));

    if ((x & EXP_MASK) == EXP_MASK) {
        // Number is either NaN or infinity
        if ((x & SIGNIFICAND_MASK) == 0) {
            // Number should be infinity
            assert(isinf(f));
            assert(isinf(g));
            printf("The number is infinity.\n");
        } else {
            // Number should be NaN
            assert(isnan(f));
            assert(isnan(g));
            printf("The number is NaN.\n");
        }
    }

    return 0;
}