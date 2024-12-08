#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "keras2c/k2c_include.h"
#include "hopfield_nets/softsign/w32/hop_softsign_w32_r3.h"

// Hopfield and softsign functions need implementations or library where they are declared.
extern void hop_softsign_w32_r3(k2c_tensor*, k2c_tensor*);

int main() {
    float input_array[96] = {0.0f};
    float output_array[96] = {0.0f};

    k2c_tensor input_tensor = {input_array, 2, 96, {3, 32, 1, 1, 1}};
    k2c_tensor output_tensor = {output_array, 2, 96, {3, 32, 1, 1, 1}};

    // Instead of __VERIFIER_nondet_float(), we use deterministic inputs.
    // Here, initializing the first 16 floats with some values.
    float fixed_values[16] = {0.5f, -0.5f, 0.1f, -0.1f, 0.3f, -0.3f, 0.6f, -0.6f, 0.7f, -0.7f, 0.8f, -0.8f, 0.9f, -0.9f, 0.2f, 0.0f};
    for (int i = 0; i < 16; i++) {
        input_array[i] = fixed_values[i];
    }
    for (int i = 16; i < 32; i++) {
        input_array[i] = 1.0f;
    }

    // Replace __VERIFIER_assume with assertions
    for (int i = 0; i < 15; i++) {
        assert(input_array[i] >= -1.0f && input_array[i] <= 1.0f);
    }

    hop_softsign_w32_r3(&input_tensor, &output_tensor);

    // Replace __VERIFIER_assert with assert
    assert(isgreaterequal(output_array[65], 0.95f));

    return 0;
}