#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <float.h> // For FLT_MAX and FLT_MIN

float elu(float x) {
    if (x >= 0.0f)
        return x;
    else
        return expm1f(x);
}

#define ELU_CHECK_NEXT 1e-2

int main() {
    // Deterministic input
    float x1 = 1.5f;  // Example fixed value; adjust as necessary
    // Ensure x1 is not NaN or infinity
    if (isnan(x1) || isinf(x1)) {
        printf("Invalid input: x1 is NaN or infinity.\n");
        return 1;
    }

    float x2 = x1 + ELU_CHECK_NEXT;
    float y1 = elu(x1);
    float y2 = elu(x2);
    float derivative = (y2 - y1) / ELU_CHECK_NEXT;

    // Assertion to ensure derivative is greater than or equal to 0
    assert(isgreaterequal(derivative, 0.0f));

    printf("Derivative check passed for x1 = %f\n", x1);
    return 0;
}