#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <keras2c/k2c_include.h>
#include <hopfield_nets/tanh/w16/hop_tanh_w16_r4.h>

// This function simulates the hop_tanh_w16_r4 function.
// Ensure it matches the function signature used in the original code.
void hop_tanh_w16_r4(k2c_tensor* input_tensor, k2c_tensor* output_tensor);

int main()
{
    float input_array[64] = {0.0f}, output_array[64] = {0.0f};
    k2c_tensor input_tensor = {&input_array[0], 2, 64, {4, 16, 1, 1, 1}};
    k2c_tensor output_tensor = {&output_array[0], 2, 64, {4, 16, 1, 1, 1}};

    // Fixed input values replacing nondeterministic ones
    input_array[0] = 0.5f;
    input_array[1] = -0.3f;
    input_array[2] = 0.1f;
    input_array[3] = -0.6f;
    input_array[4] = 0.7f;
    input_array[5] = -0.4f;
    input_array[6] = 0.3f;
    input_array[7] = 1.0f;
    input_array[8] = 1.0f;
    input_array[9] = 1.0f;
    input_array[10] = 1.0f;
    input_array[11] = 1.0f;
    input_array[12] = 1.0f;
    input_array[13] = 1.0f;
    input_array[14] = 1.0f;
    input_array[15] = 1.0f;

    // Assumed conditions now validated with assertions
    assert(input_array[0] >= -1.0f && input_array[0] <= 1.0f);
    assert(input_array[1] >= -1.0f && input_array[1] <= 1.0f);
    assert(input_array[2] >= -1.0f && input_array[2] <= 1.0f);
    assert(input_array[3] >= -1.0f && input_array[3] <= 1.0f);
    assert(input_array[4] >= -1.0f && input_array[4] <= 1.0f);
    assert(input_array[5] >= -1.0f && input_array[5] <= 1.0f);
    assert(input_array[6] >= -1.0f && input_array[6] <= 1.0f);

    hop_tanh_w16_r4(&input_tensor, &output_tensor);

    // Assert the expected condition
    assert(isgreaterequal(output_array[62], 0.0f));

    printf("Program executed successfully!\n");
    return 0;
}