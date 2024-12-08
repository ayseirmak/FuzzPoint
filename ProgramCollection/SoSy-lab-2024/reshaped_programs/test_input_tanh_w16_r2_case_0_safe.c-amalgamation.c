#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <keras2c/k2c_include.h>
#include <hopfield_nets/tanh/w16/hop_tanh_w16_r2.h>

void run_model() {
    float input_array[32] = {0.0f}, output_array[32] = {0.0f};
    k2c_tensor input_tensor = {&input_array[0], 2, 32, {2, 16, 1, 1, 1}};
    k2c_tensor output_tensor = {&output_array[0], 2, 32, {2, 16, 1, 1, 1}};
    
    // Deterministic inputs
    input_array[0] = 0.5f;
    input_array[1] = -0.3f;
    input_array[2] = 0.7f;
    input_array[3] = -0.1f;
    input_array[4] = 0.4f;
    input_array[5] = -0.2f;
    input_array[6] = 0.9f;
    input_array[7] = 1.0f;
    input_array[8] = 1.0f;
    input_array[9] = 1.0f;
    input_array[10] = 1.0f;
    input_array[11] = 1.0f;
    input_array[12] = 1.0f;
    input_array[13] = 1.0f;
    input_array[14] = 1.0f;
    input_array[15] = 1.0f;

    // Ensure input values are within the assumed domain
    assert(input_array[0] >= -1.0f && input_array[0] <= 1.0f);
    assert(input_array[1] >= -1.0f && input_array[1] <= 1.0f);
    assert(input_array[2] >= -1.0f && input_array[2] <= 1.0f);
    assert(input_array[3] >= -1.0f && input_array[3] <= 1.0f);
    assert(input_array[4] >= -1.0f && input_array[4] <= 1.0f);
    assert(input_array[5] >= -1.0f && input_array[5] <= 1.0f);
    assert(input_array[6] >= -1.0f && input_array[6] <= 1.0f);

    hop_tanh_w16_r2(&input_tensor, &output_tensor);

    // Verify the output
    assert(isgreaterequal(output_array[16], 0.0f)); 

    // Output for debugging
    printf("Output verified successfully.\n");
}

int main() {
    run_model();
    return 0;
}