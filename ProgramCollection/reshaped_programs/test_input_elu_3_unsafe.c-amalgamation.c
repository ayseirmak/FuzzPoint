#include <stdio.h>
#include <math.h>
#include <assert.h>

float elu(float x) {
    if (x >= 0.0f)
        return x;
    else
        return expm1f(x);
}

#define ELU_CHECK_NEXT 1e-2

int main() {
    float x1 = 1.0f;  // Fixed value for deterministic execution
    float x2 = x1 + ELU_CHECK_NEXT;

    // Assume x1 is neither NaN nor infinity for this deterministic setup
    if (!isnan(x1) && !isinf(x1)) {
        float y1 = elu(x1);
        float y2 = elu(x2);
        float derivative = (y2 - y1) / ELU_CHECK_NEXT;

        // Assert that the empirical derivative is less than or equal to 1.0f
        assert(islessequal(derivative, 1.0f));
    } else {
        printf("Invalid values for x1\n");
    }

    return 0;
}