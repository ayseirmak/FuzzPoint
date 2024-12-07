#include <math.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

void reach_error() { 
    assert(0); 
}

void __VERIFIER_assert(int cond) { 
    if (!cond) { 
        reach_error();
    } 
    return; 
}

int main() {
    // Deterministic value for 'a' (must not be 0 and not NaN)
    double a = 1.0;  // Example value that meets the conditions

    // Removed assume_abort_if_not because 'a' is already valid by choice

    double plus_zero = 0.0;
    double plus_zero_mod = fmod(plus_zero, a);
    bool plus_zero_mod_sign = signbit(plus_zero);

    __VERIFIER_assert((plus_zero_mod == 0.0) && !plus_zero_mod_sign);

    double minus_zero = -0.0;
    double minus_zero_mod = fmod(minus_zero, a);
    bool minus_zero_mod_sign = signbit(minus_zero);

    __VERIFIER_assert((minus_zero_mod == 0.0) && minus_zero_mod_sign);

    printf("Assertions passed without errors.\n");

    return 0;
}