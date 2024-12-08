#include <stdio.h>
#include <math.h>
#include <assert.h>

#define EXP_CHECK_NEXT 1e-2f
#define EXP_CHECK_RANGE 88.0f

int main() {
    // Initialize and declare all variables explicitly
    float x1 = 0.0f;  // Assign a specific value within the desired range

    // Assume condition for range where precision is high
    assert(x1 >= -EXP_CHECK_RANGE && x1 <= EXP_CHECK_RANGE);

    float x2 = x1 + EXP_CHECK_NEXT;
    
    float y1 = expf(x1);
    float y2 = expf(x2);
    float derivative = (y2 - y1) / EXP_CHECK_NEXT;
    
    // Checking if the derivative is greater than or equal to y2
    if (!(derivative >= y2)) {
        printf("Verification failed: derivative is not greater or equal to y2.\n");
    } else {
        printf("Verification passed.\n");
    }

    return 0;
}