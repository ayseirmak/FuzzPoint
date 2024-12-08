#include <stdio.h>
#include <math.h>
#include <string.h>
#include <keras2c/k2c_include.h>
#include <keras2c/k2c_tensor_include.h>

// Define the hop_tanh_w4_r2 function used in the main program
void hop_tanh_w4_r2(k2c_tensor* input_tensor, k2c_tensor* output_tensor) {
    int simple_rnn_32_go_backwards = 0;
    int simple_rnn_32_return_sequences = 1;
    float simple_rnn_32_fwork[8] = {0};
    float simple_rnn_32_state[4] = {0};
    float simple_rnn_32_kernel_array[16] = {
        1.0f, 0.0f, 0.0f, 0.0f, 0.0f,
        1.0f, 0.0f, 0.0f, 0.0f, 0.0f,
        1.0f, 0.0f, 0.0f, 0.0f, 0.0f,
        1.0f,
    };
    k2c_tensor simple_rnn_32_kernel = {&simple_rnn_32_kernel_array[0], 2, 16, {4, 4, 1, 1, 1}};
    float simple_rnn_32_recurrent_kernel_array[16] = {
        1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
        1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
        1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
        1.0f,
    };
    k2c_tensor simple_rnn_32_recurrent_kernel = {&simple_rnn_32_recurrent_kernel_array[0], 2, 16, {4, 4, 1, 1, 1}};
    float simple_rnn_32_bias_array[4] = {0};
    k2c_tensor simple_rnn_32_bias = {&simple_rnn_32_bias_array[0], 1, 4, {4, 1, 1, 1, 1}};
    
    k2c_simpleRNN(output_tensor, input_tensor, simple_rnn_32_state, &simple_rnn_32_kernel,
                  &simple_rnn_32_recurrent_kernel, &simple_rnn_32_bias, simple_rnn_32_fwork,
                  simple_rnn_32_go_backwards, simple_rnn_32_return_sequences, k2c_tanh);
}

int main() {
    float input_array[8] = {0.0f}, output_array[8] = {0.0f};
    k2c_tensor input_tensor = {&input_array[0], 2, 8, {2, 4, 1, 1, 1}};
    k2c_tensor output_tensor = {&output_array[0], 2, 8, {2, 4, 1, 1, 1}};
    
    // Initialize input with deterministic values
    input_array[0] = 0.5f; // Fixed value within desired range [-1.0, 1.0]
    input_array[1] = 1.0f;
    input_array[2] = 1.0f;
    input_array[3] = 1.0f;
    
    // Perform the RNN operation
    hop_tanh_w4_r2(&input_tensor, &output_tensor);
    
    // Assert the expected result
    if (isgreaterequal(output_array[5], 0.91f)) {
        printf("Verification passed.\n");
    } else {
        printf("Verification failed.\n");
    }

    return 0;
}