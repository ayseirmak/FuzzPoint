#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <string.h>
#include <keras2c/k2c_include.h>
#include <keras2c/k2c_tensor_include.h>

// Function signature for the model
void hop_tanh_w4_r4(k2c_tensor *simple_rnn_9_input_input, k2c_tensor *simple_rnn_9_output);

int main() {
    // Initialize input and output arrays for the neural network
    float input_array[16] = {0.0f};
    float output_array[16] = {0.0f};

    // Initialize input tensor descriptor
    k2c_tensor input_tensor = {&input_array[0], 2, 16, {4, 4, 1, 1, 1}};

    // Initialize output tensor descriptor
    k2c_tensor output_tensor = {&output_array[0], 2, 16, {4, 4, 1, 1, 1}};

    // Set a fixed input value in place of non-deterministic input
    input_array[0] = 0.5f;  // Example fixed value within the desired range
    input_array[1] = 1.0f;
    input_array[2] = 1.0f;
    input_array[3] = 1.0f;

    // Call the neural network function
    hop_tanh_w4_r4(&input_tensor, &output_tensor);

    // Use an assertion to verify that the output meets the expected condition
    assert(output_array[15] >= 0.9995f);

    // Inform that verification passed
    printf("Verification passed.\n");

    return 0;
}

void hop_tanh_w4_r4(k2c_tensor *simple_rnn_9_input_input, k2c_tensor *simple_rnn_9_output) {
    int simple_rnn_9_go_backwards = 0;
    int simple_rnn_9_return_sequences = 1;
    float simple_rnn_9_fwork[8] = {0};
    float simple_rnn_9_state[4] = {0};
    float simple_rnn_9_kernel_array[16] = {
        +1.00000000e+00f, +0.00000000e+00f, +0.00000000e+00f, +0.00000000e+00f, +0.00000000e+00f,
        +1.00000000e+00f, +0.00000000e+00f, +0.00000000e+00f, +0.00000000e+00f, +0.00000000e+00f,
        +1.00000000e+00f, +0.00000000e+00f, +0.00000000e+00f, +0.00000000e+00f, +0.00000000e+00f,
        +1.00000000e+00f
    };
    k2c_tensor simple_rnn_9_kernel = {&simple_rnn_9_kernel_array[0], 2, 16, {4, 4, 1, 1, 1}};
    float simple_rnn_9_recurrent_kernel_array[16] = {
        +1.00000000e+00f, +1.00000000e+00f, +1.00000000e+00f, +1.00000000e+00f, +1.00000000e+00f,
        +1.00000000e+00f, +1.00000000e+00f, +1.00000000e+00f, +1.00000000e+00f, +1.00000000e+00f,
        +1.00000000e+00f, +1.00000000e+00f, +1.00000000e+00f, +1.00000000e+00f, +1.00000000e+00f,
        +1.00000000e+00f
    };
    k2c_tensor simple_rnn_9_recurrent_kernel = {&simple_rnn_9_recurrent_kernel_array[0], 2, 16, {4, 4, 1, 1, 1}};
    float simple_rnn_9_bias_array[4] = {0};
    k2c_tensor simple_rnn_9_bias = {&simple_rnn_9_bias_array[0], 1, 4, {4, 1, 1, 1, 1}};

    // Use the simple RNN function
    k2c_simpleRNN(simple_rnn_9_output, simple_rnn_9_input_input, simple_rnn_9_state, &simple_rnn_9_kernel,
                  &simple_rnn_9_recurrent_kernel, &simple_rnn_9_bias, simple_rnn_9_fwork, 
                  simple_rnn_9_go_backwards, simple_rnn_9_return_sequences, k2c_tanh);
}