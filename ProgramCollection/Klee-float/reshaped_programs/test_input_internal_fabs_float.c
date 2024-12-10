#include <assert.h>
#include <float.h>
#include <math.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>

int main() {
    // -ve
    float x = -100.0f;
    float result = fabsf(x);
    assert(result == 100.0f);

    // +ve
    x = 100.0f;
    assert(!signbit(x));
    result = fabsf(x);
    assert(result == 100.0f);

    // -ve zero
    x = -0.0f;
    assert(signbit(x));
    result = fabsf(x);
    assert(result == 0.0f);
    assert(signbit(x));

    // +ve zero
    x = 0.0f;
    assert(!signbit(x));
    result = fabsf(x);
    assert(result == 0.0f);
    assert(!signbit(x));

    // +NaN
    uint32_t posNanBits = 0x7fc00000;
    float posNan = 0.0f;
    memcpy(&posNan, &posNanBits, sizeof(float));
    assert(isnan(posNan));
    assert(!signbit(posNan));
    result = fabsf(posNan);
    assert(isnan(result));
    assert(!signbit(result)); // is +ve NaN.

    // -NaN
    uint32_t negNanBits = 0xffc00000;
    float negNan = 0.0f;
    memcpy(&negNan, &negNanBits, sizeof(float));
    assert(isnan(negNan));
    assert(signbit(negNan));
    result = fabsf(negNan);
    assert(isnan(result));
    assert(!signbit(result)); // is +ve NaN.

    // +Infinity
    x = INFINITY;
    assert(!signbit(x));
    result = fabsf(x);
    assert(isinf(x) == 1);

    // -Infinity
    x = -INFINITY;
    assert(signbit(x));
    result = fabsf(x);
    assert(isinf(x) == 1);

    return 0;
}