#include <assert.h>
#include <float.h>
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>

int main() {
    // Initialize variables
    double x, result;

    // -ve
    x = -100.0;
    result = fabs(x);
    assert(result == 100.0);

    // +ve
    x = 100.0;
    assert(!signbit(x));
    result = fabs(x);
    assert(result == 100.0);

    // -ve zero
    x = -0.0;
    assert(signbit(x));
    result = fabs(x);
    assert(result == 0.0);
    assert(signbit(x));

    // +ve zero
    x = 0.0;
    assert(!signbit(x));
    result = fabs(x);
    assert(result == 0.0);
    assert(!signbit(x));

    // +NaN
    uint64_t posNanBits = 0x7ff8000000000000;
    double posNan = 0.0;
    memcpy(&posNan, &posNanBits, sizeof(double));
    assert(isnan(posNan));
    assert(!signbit(posNan));
    result = fabs(posNan);
    assert(isnan(result));
    assert(!signbit(result)); // is +ve NaN.

    // -NaN
    uint64_t negNanBits = 0xfff8000000000000;
    double negNan = 0.0;
    memcpy(&negNan, &negNanBits, sizeof(double));
    assert(isnan(negNan));
    assert(signbit(negNan));
    result = fabs(negNan);
    assert(isnan(result));
    assert(!signbit(result)); // is +ve NaN.

    // +Infinity
    x = INFINITY;
    assert(!signbit(x));
    result = fabs(x);
    assert(isinf(x) == 1);

    // -Infinity
    x = -INFINITY;
    assert(signbit(x));
    result = fabs(x);
    assert(isinf(x) == 1);

    return 0;
}