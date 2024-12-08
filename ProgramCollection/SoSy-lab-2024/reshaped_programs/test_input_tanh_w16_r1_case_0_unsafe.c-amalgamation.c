#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <keras2c/k2c_include.h>
#include <keras2c/k2c_tensor_include.h>

// Function prototype for hop_tanh_w16_r1
void hop_tanh_w16_r1(k2c_tensor* input_tensor, k2c_tensor* output_tensor);

int main() {
    float input_array[16] = {0.0f}, output_array[16] = {0.0f};
    k2c_tensor input_tensor = {&input_array[0], 2, 16, {1, 16, 1, 1, 1}};
    k2c_tensor output_tensor = {&output_array[0], 2, 16, {1, 16, 1, 1, 1}};

    // Initialize deterministically instead of nondeterministic
    input_array[0] = 0.5f;
    input_array[1] = -0.5f;
    input_array[2] = 0.25f;
    input_array[3] = -0.25f;
    input_array[4] = 0.75f;
    input_array[5] = -0.75f;
    input_array[6] = 0.0f;
    input_array[7] = 1.0f;
    input_array[8] = 1.0f;
    input_array[9] = 1.0f;
    input_array[10] = 1.0f;
    input_array[11] = 1.0f;
    input_array[12] = 1.0f;
    input_array[13] = 1.0f;
    input_array[14] = 1.0f;
    input_array[15] = 1.0f;

    // Use assertions instead of verifier functions
    assert(input_array[0] >= -1.0f && input_array[0] <= 1.0f);
    assert(input_array[1] >= -1.0f && input_array[1] <= 1.0f);
    assert(input_array[2] >= -1.0f && input_array[2] <= 1.0f);
    assert(input_array[3] >= -1.0f && input_array[3] <= 1.0f);
    assert(input_array[4] >= -1.0f && input_array[4] <= 1.0f);
    assert(input_array[5] >= -1.0f && input_array[5] <= 1.0f);
    assert(input_array[6] >= -1.0f && input_array[6] <= 1.0f);

    hop_tanh_w16_r1(&input_tensor, &output_tensor);

    // Conducting verification on output
    assert(isgreaterequal(output_array[0], 0.0f));

    return 0;
}

/* Function to implement hop_tanh_w16_r1 remains untouched as it was meant to be imported */