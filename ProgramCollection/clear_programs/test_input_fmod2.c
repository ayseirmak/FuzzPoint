#include <math.h>
#include <assert.h>
#include <stdio.h>

void reach_error() {
    assert(0);
}

void __VERIFIER_assert(int cond) {
    if (!cond) { 
        printf("Verification Failed!\n");
        reach_error();
    }
    return;
}

int main() {
    // Fixed deterministic value for `a`
    double a = 3.5;
    
    // Conditions that would have otherwise aborted
    if (__isnan(a) || __isinf(a) || a == 0.0) {
        printf("Preconditions not met!\n");
        return 1;  // Exit the program as preconditions are not satisfied
    }

    double plus_zero = 0.0;
    double plus_zero_mod = fmod(plus_zero, a);
    _Bool plus_zero_mod_sign = __signbit(plus_zero);

    __VERIFIER_assert((plus_zero_mod == 0.0) && !plus_zero_mod_sign);

    double minus_zero = -0.0;
    double minus_zero_mod = fmod(minus_zero, a);
    _Bool minus_zero_mod_sign = signbit(minus_zero);

    __VERIFIER_assert((minus_zero_mod == 0.0) && minus_zero_mod_sign);

    printf("All assertions passed.\n");
    return 0;
}