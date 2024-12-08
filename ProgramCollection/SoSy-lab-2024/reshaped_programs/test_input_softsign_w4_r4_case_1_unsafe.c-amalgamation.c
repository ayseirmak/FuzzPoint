#include <stdio.h>
#include <math.h>
#include <string.h>
#include <keras2c/k2c_include.h>
#include <keras2c/k2c_tensor_include.h>
#include <hopfield_nets/softsign/w4/hop_softsign_w4_r4.h>

// Replacing __VERIFIER_assert with assert from the standard library
#include <assert.h>

// Define fixed input value since we're replacing non-deterministic input
#define FIXED_INPUT_VALUE 0.5f

int main() {
    float input_array[16] = {0.0f}, output_array[16] = {0.0f};
    k2c_tensor input_tensor = {&input_array[0], 2, 16, {4, 4, 1, 1, 1}};
    k2c_tensor output_tensor = {&output_array[0], 2, 16, {4, 4, 1, 1, 1}};

    // Initialize the input with a fixed value instead of using non-deterministic input
    input_array[0] = FIXED_INPUT_VALUE;
    input_array[1] = 1.0f;
    input_array[2] = 1.0f;
    input_array[3] = 1.0f;

    // Removed __VERIFIER_assume and rely only on logical assertions
    assert(input_array[0] >= -1.0f && input_array[0] <= 1.0f); // Checking input domain

    // Run the function from the hopfield_nets library
    hop_softsign_w4_r4(&input_tensor, &output_tensor);

    // Check the output value with assertion
    // If output_array[15] < 0.74, the assertion will fail indicating a test failure
    assert(isgreaterequal(output_array[15], 0.74f));

    // Simple logging for demonstration purposes
    if (isgreaterequal(output_array[15], 0.74f)) {
        printf("Output is great enough: %f\n", output_array[15]);
    } else {
        printf("Output did not meet expectation: %f\n", output_array[15]);
    }

    return 0;
}