#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <keras2c/k2c_include.h>
#include <hopfield_nets/softsign/w32/hop_softsign_w32_r4.h>

int main() {
    float input_array[128] = {0.0f}, output_array[128] = {0.0f};
    k2c_tensor input_tensor = {&input_array[0], 2, 128, {4, 32, 1, 1, 1}};
    k2c_tensor output_tensor = {&output_array[0], 2, 128, {4, 32, 1, 1, 1}};

    // Initialized with fixed deterministic inputs for simulation
    input_array[0] = 0.5f;
    input_array[1] = -0.5f;
    input_array[2] = 0.7f;
    input_array[3] = -0.7f;
    input_array[4] = 0.3f;
    input_array[5] = -0.3f;
    input_array[6] = 0.9f;
    input_array[7] = -0.9f;
    input_array[8] = 0.6f;
    input_array[9] = -0.6f;
    input_array[10] = 0.8f;
    input_array[11] = -0.8f;
    input_array[12] = 0.4f;
    input_array[13] = -0.4f;
    input_array[14] = 0.2f;
    input_array[15] = 1.0f;
    input_array[16] = 1.0f;
    input_array[17] = 1.0f;
    input_array[18] = 1.0f;
    input_array[19] = 1.0f;
    input_array[20] = 1.0f;
    input_array[21] = 1.0f;
    input_array[22] = 1.0f;
    input_array[23] = 1.0f;
    input_array[24] = 1.0f;
    input_array[25] = 1.0f;
    input_array[26] = 1.0f;
    input_array[27] = 1.0f;
    input_array[28] = 1.0f;
    input_array[29] = 1.0f;
    input_array[30] = 1.0f;
    input_array[31] = 1.0f;

    // Assumptions: input is within the specified domain
    assert(input_array[0] >= -1.0f && input_array[0] <= 1.0f);
    assert(input_array[1] >= -1.0f && input_array[1] <= 1.0f);
    assert(input_array[2] >= -1.0f && input_array[2] <= 1.0f);
    assert(input_array[3] >= -1.0f && input_array[3] <= 1.0f);
    assert(input_array[4] >= -1.0f && input_array[4] <= 1.0f);
    assert(input_array[5] >= -1.0f && input_array[5] <= 1.0f);
    assert(input_array[6] >= -1.0f && input_array[6] <= 1.0f);
    assert(input_array[7] >= -1.0f && input_array[7] <= 1.0f);
    assert(input_array[8] >= -1.0f && input_array[8] <= 1.0f);
    assert(input_array[9] >= -1.0f && input_array[9] <= 1.0f);
    assert(input_array[10] >= -1.0f && input_array[10] <= 1.0f);
    assert(input_array[11] >= -1.0f && input_array[11] <= 1.0f);
    assert(input_array[12] >= -1.0f && input_array[12] <= 1.0f);
    assert(input_array[13] >= -1.0f && input_array[13] <= 1.0f);
    assert(input_array[14] >= -1.0f && input_array[14] <= 1.0f);

    hop_softsign_w32_r4(&input_tensor, &output_tensor);

    // Assert and check if the output meets the expectation
    printf("Output: %f\n", output_array[127]);
    assert(isgreaterequal(output_array[127], 0.97f));  // Expected result

    return 0;
}