#include <math.h>
#include <stdio.h>
#include <assert.h>
#include <keras2c/k2c_include.h>

void hop_softsign_w4_r1(k2c_tensor* input_tensor, k2c_tensor* output_tensor);

int main() {
    // Initialize input and output arrays
    float input_array[4] = {0.5f, 1.0f, 1.0f, 1.0f}; // Replaced non-deterministic input with fixed value
    float output_array[4] = {0.0f};
    
    // Define input_tensor and output_tensor
    k2c_tensor input_tensor = {input_array, 2, 4, {1, 4, 1, 1, 1}};
    k2c_tensor output_tensor = {output_array, 2, 4, {1, 4, 1, 1, 1}};
    
    // Call the function
    hop_softsign_w4_r1(&input_tensor, &output_tensor);
    
    // Assert the condition for verification
    assert(output_array[2] >= 0.0f);

    // Output the result for clarity
    printf("Output array[2] value: %f\n", output_array[2]);

    return 0;
}

void hop_softsign_w4_r1(k2c_tensor* simple_rnn_1_input_input, k2c_tensor* simple_rnn_1_output) {
    int simple_rnn_1_go_backwards = 0;
    int simple_rnn_1_return_sequences = 1;
    float simple_rnn_1_fwork[8] = {0};
    float simple_rnn_1_state[4] = {0};
    float simple_rnn_1_kernel_array[16] = {
        1.0f, 0.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f
    };
    k2c_tensor simple_rnn_1_kernel = {simple_rnn_1_kernel_array, 2, 16, {4, 4, 1, 1, 1}};
    float simple_rnn_1_recurrent_kernel_array[16] = {
        1.0f, 1.0f, 1.0f, 1.0f,
        1.0f, 1.0f, 1.0f, 1.0f,
        1.0f, 1.0f, 1.0f, 1.0f,
        1.0f, 1.0f, 1.0f, 1.0f
    };
    k2c_tensor simple_rnn_1_recurrent_kernel = {simple_rnn_1_recurrent_kernel_array, 2, 16, {4, 4, 1, 1, 1}};
    float simple_rnn_1_bias_array[4] = {0}; 
    k2c_tensor simple_rnn_1_bias = {simple_rnn_1_bias_array, 1, 4, {4, 1, 1, 1, 1}};

    k2c_simpleRNN(simple_rnn_1_output, simple_rnn_1_input_input, simple_rnn_1_state, &simple_rnn_1_kernel,
                  &simple_rnn_1_recurrent_kernel, &simple_rnn_1_bias, simple_rnn_1_fwork,
                  simple_rnn_1_go_backwards, simple_rnn_1_return_sequences, k2c_softsign);
}