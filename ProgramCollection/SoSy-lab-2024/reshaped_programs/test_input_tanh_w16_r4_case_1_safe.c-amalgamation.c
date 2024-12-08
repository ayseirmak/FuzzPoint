#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <keras2c/k2c_include.h>
#include <hopfield_nets/tanh/w16/hop_tanh_w16_r4.h>

int main() {
    float input_array[64] = {0.0f}, output_array[64] = {0.0f};
    k2c_tensor input_tensor = {&input_array[0], 2, 64, {4,16,1,1,1}};
    k2c_tensor output_tensor = {&output_array[0], 2, 64, {4,16,1,1,1}};

    // Initialize input_array with deterministic values
    input_array[0] = 0.5f;
    input_array[1] = -0.3f;
    input_array[2] = 0.8f;
    input_array[3] = -0.5f;
    input_array[4] = 0.1f;
    input_array[5] = 0.0f;
    input_array[6] = -0.7f;
    input_array[7] = 1.0f;
    input_array[8] = 1.0f;
    input_array[9] = 1.0f;
    input_array[10] = 1.0f;
    input_array[11] = 1.0f;
    input_array[12] = 1.0f;
    input_array[13] = 1.0f;
    input_array[14] = 1.0f;
    input_array[15] = 1.0f;

    // Standard assert checks for input range, replacing __VERIFIER_assume
    assert(input_array[0] >= -1.0f && input_array[0] <= 1.0f);
    assert(input_array[1] >= -1.0f && input_array[1] <= 1.0f);
    assert(input_array[2] >= -1.0f && input_array[2] <= 1.0f);
    assert(input_array[3] >= -1.0f && input_array[3] <= 1.0f);
    assert(input_array[4] >= -1.0f && input_array[4] <= 1.0f);
    assert(input_array[5] >= -1.0f && input_array[5] <= 1.0f);
    assert(input_array[6] >= -1.0f && input_array[6] <= 1.0f);

    hop_tanh_w16_r4(&input_tensor, &output_tensor);

    // Standard assert check to ensure expected output, replacing __VERIFIER_assert
    assert(output_array[63] == 1.0f); 

    printf("Program executed successfully.\n");

    return 0;
}