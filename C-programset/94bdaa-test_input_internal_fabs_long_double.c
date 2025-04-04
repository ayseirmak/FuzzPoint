#include <assert.h>
#include <float.h>
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>

// Emulate the behavior of klee_abs_long_double using fabsl
long double custom_abs_long_double(long double x) {
    return fabsl(x);
}

long double make_long_double(uint16_t highBits, uint64_t lowBits) {
    long double v = 0.0l;
    memcpy(&v, &lowBits, sizeof(lowBits));       // 64 bits
    memcpy(((uint8_t *)(&v)) + 8, &highBits, 2); // 16 bits
    return v;
}

int main() {
    // -ve
    long double x = -100.0l;
    long double result = custom_abs_long_double(x);
    assert(result == 100.0l);

    // +ve
    x = 100.0l;
    assert(!signbit(x));
    result = custom_abs_long_double(x);
    assert(result == 100.0l);

    // -ve zero
    x = -0.0l;
    assert(signbit(x));
    result = custom_abs_long_double(x);
    assert(result == 0.0l);
    assert(signbit(x));

    // +ve zero
    x = 0.0l;
    assert(!signbit(x));
    result = custom_abs_long_double(x);
    assert(result == 0.0l);
    assert(!signbit(x));

    // +NaN
    long double posNan = make_long_double(0x7fff, 0xc000000000000000);
    assert(isnan(posNan));
    assert(!signbit(posNan));
    result = custom_abs_long_double(posNan);
    assert(isnan(result));
    assert(!signbit(result)); // is +ve NaN.

    // -NaN
    long double negNan = make_long_double(0xffff, 0xc000000000000000);
    assert(isnan(negNan));
    assert(signbit(negNan));
    result = custom_abs_long_double(negNan);
    assert(isnan(result));
    assert(!signbit(result)); // is +ve NaN.

    // +Infinity
    x = INFINITY;
    assert(!signbit(x));
    result = custom_abs_long_double(x);
    assert(isinf(x) == 1);

    // -Infinity
    x = -INFINITY;
    assert(signbit(x));
    result = custom_abs_long_double(x);
    assert(isinf(x) == -1);

    return 0;
}