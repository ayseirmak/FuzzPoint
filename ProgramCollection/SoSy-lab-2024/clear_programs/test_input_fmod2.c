#include <stdio.h>
#include <math.h>
#include <assert.h>

void reach_error() {
    assert(0);
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    // We assign a deterministic non-zero, non-NaN, non-infinite value to 'a'.
    double a = 2.5;

    // Initialize 'plus_zero' and calculate its modulus with 'a'.
    double plus_zero = 0.0;
    double plus_zero_mod = fmod(plus_zero, a);

    // Determine the sign of 'plus_zero' and assert the conditions.
    _Bool plus_zero_mod_sign = __signbit(plus_zero);
    __VERIFIER_assert((plus_zero_mod == 0.0) && !plus_zero_mod_sign);

    // Initialize 'minus_zero' and calculate its modulus with 'a'.
    double minus_zero = -0.0;
    double minus_zero_mod = fmod(minus_zero, a);

    // Determine the sign of 'minus_zero' and assert the conditions.
    _Bool minus_zero_mod_sign = signbit(minus_zero);
    __VERIFIER_assert((minus_zero_mod == 0.0) && minus_zero_mod_sign);

    printf("Assertions passed successfully.\n");
    
    return 0;
}