#include <stdio.h>
#include <math.h>
#include <assert.h>

// This function simulates the behavior of the non-deterministic input
double fixed_input_double() {
    return 1.0; // Fixed deterministic input
}

void assume_abort_if_not(int cond) {
    if (!cond) {
        printf("Aborting due to assumption failure.\n");
        abort();
    }
}

void reach_error() {
    assert(0);
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
        printf("Error reached: Assertion failed.\n");
        reach_error();
        abort();
    }
}

int main() {
    // Instead of nondeterministic input, use a fixed deterministic input
    double a = fixed_input_double();

    // Check the constraints on 'a'
    assume_abort_if_not(!isnan(a));
    assume_abort_if_not(a != 0.0);

    // Check and assert properties related to zero modulus operation
    double plus_zero = 0.0;
    double plus_zero_mod = fmod(plus_zero, a);
    _Bool plus_zero_mod_sign = signbit(plus_zero);
    __VERIFIER_assert((plus_zero_mod == 0.0) && !plus_zero_mod_sign);

    double minus_zero = -0.0;
    double minus_zero_mod = fmod(minus_zero, a);
    _Bool minus_zero_mod_sign = signbit(minus_zero);
    __VERIFIER_assert((minus_zero_mod == 0.0) && minus_zero_mod_sign);

    printf("Program completed successfully without error.\n");
    return 0;
}