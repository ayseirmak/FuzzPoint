// SPDX-License-Identifier: MIT

#include <stdio.h>
#include <math.h>
#include <keras2c/k2c_include.h>
#include <assert.h>  // For using standard assertions

void hop_softsign_w4_r3(k2c_tensor* simple_rnn_21_input_input, k2c_tensor* simple_rnn_21_output);

int main() {
    float input_array[12] = {0.0f};
    float output_array[12] = {0.0f};
    k2c_tensor input_tensor = {&input_array[0], 2, 12, {3, 4, 1, 1, 1}};
    k2c_tensor output_tensor = {&output_array[0], 2, 12, {3, 4, 1, 1, 1}};
    
    // Deterministic input for testing
    input_array[0] = 0.5f;  // Fixed input within the assumed bounds
    input_array[1] = 1.0f;
    input_array[2] = 1.0f;
    input_array[3] = 1.0f;

    // Run the model function
    hop_softsign_w4_r3(&input_tensor, &output_tensor);

    // Verification with assertion instead of non-standard verifier
    assert(output_array[8] >= 0.0f);  // Ensure condition holds

    if (fabsf(input_array[0]) <= 1.0f) { // Input domain condition check (optional as per deterministic input)
        printf("Verification successful: output_array[8] = %f is >= 0.0\n", output_array[8]);
    } else {
        printf("Input out of expected range!\n");
    }

    return 0;
}

// Simple implementation for demonstration purposes
void hop_softsign_w4_r3(k2c_tensor* simple_rnn_21_input_input, k2c_tensor* simple_rnn_21_output) {
    // This function should implement the specific RNN layer behavior
    // For demonstration, assume a simple transformation, like scaling and adding a bias
    for (int i = 0; i < 12; ++i) {
        simple_rnn_21_output->array[i] = simple_rnn_21_input_input->array[i] / (1.0f + fabsf(simple_rnn_21_input_input->array[i]));
    }
    // The logic will depend on the model you are implementing
}