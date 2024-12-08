#include <stdio.h>
#include <math.h>
#include <assert.h>

#define GELU_CHECK_SQRT2 1.41421356237309504880168872420969807856967187537694807317667973799f

float gelu(float x) {
    float cdf = 0.5f * erff(x / GELU_CHECK_SQRT2) + 0.5f; /* Express the CDF of the normal distribution in terms of the error function */
    return x * cdf;
}

#define GELU_CHECK_NEXT 1e-5f

int main() {
    float x1 = 0.0f;  // Deterministic fixed value for x1
    float x2 = x1 + GELU_CHECK_NEXT;

    assert(!isnan(x1) && !isinf(x1));

    float y1 = gelu(x1);
    float y2 = gelu(x2);

    assert(islessequal(y1, y2)); /* Check if y1 is less than or equal to y2 */

    if (islessequal(y1, y2)) {
        printf("Assertion passed: y1 <= y2\n");
    } else {
        printf("Assertion failed: y1 > y2\n");
    }

    return 0;
}