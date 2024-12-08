#include <math.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <keras2c/k2c_include.h>
#include <keras2c/k2c_tensor_include.h>
#include <hopfield_nets/tanh/w32/hop_tanh_w32_r2.h>

// Custom assert macro for verification
#define VERIFY_ASSERT(x) assert(x)

int main() {
    // Initialize deterministic input array with fixed values
    float input_array[64] = {-0.5f, 0.6f, -0.7f, 0.8f, -0.9f, 0.4f, -0.3f, 0.2f, 
                              -0.1f, 0.0f, 0.1f, -0.2f, 0.3f, -0.4f, 0.5f, 1.0f,
                               1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 
                               1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 
                               1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
                               1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
                               1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 
                               1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f};

    // Initialize output array
    float output_array[64] = {0.0f};

    k2c_tensor input_tensor = {&input_array[0], 2, 64, {2, 32, 1, 1, 1}};
    k2c_tensor output_tensor = {&output_array[0], 2, 64, {2, 32, 1, 1, 1}};

    // Assumptions replaced with deterministic checks
    for (int i = 0; i < 15; i++) {
        VERIFY_ASSERT(input_array[i] >= -1.0f && input_array[i] <= 1.0f);
    }

    // Pass through the hopfield network
    hop_tanh_w32_r2(&input_tensor, &output_tensor);

    // Assert condition for the verifier
    VERIFY_ASSERT(output_array[32] >= 0.0f);

    return 0;
}