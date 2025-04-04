#include <assert.h>
#include <float.h>
#include <math.h>
#include <stdio.h>

int main() {
    float x = 100.0f;
    float result = sqrtf(x);
    printf("sqrt(%f) = %f\n", x, result);
    assert(result == 10.0f);

    x = -0.0f;
    assert(signbit(x));
    result = sqrtf(x);
    printf("sqrt(%f) = %f\n", x, result);
    assert(result == 0.0f);
    assert(signbit(result) == signbit(x));

    printf("Test sqrt negative\n");
    x = -FLT_MIN;
    assert(signbit(x));
    assert(x < 0.0f);
    result = sqrtf(x);
    printf("sqrt(%f) = %f\n", x, result);
    assert(isnan(result));

    return 0;
}