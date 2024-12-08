#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <keras2c/k2c_include.h>
#include <string.h>

void hop_tanh_w4_r3(k2c_tensor* input_tensor, k2c_tensor* output_tensor);

int main() {
    // Initialize input and output arrays
    float input_array[12] = {0.0f};
    float output_array[12] = {0.0f};
    
    // Initialize input and output tensors
    k2c_tensor input_tensor = {&input_array[0], 2, 12, {3, 4, 1, 1, 1}};
    k2c_tensor output_tensor = {&output_array[0], 2, 12, {3, 4, 1, 1, 1}};
    
    // Set fixed deterministic inputs
    input_array[0] = 0.5f;  // Fixed value replacing __VERIFIER_nondet_float()
    input_array[1] = 1.0f;
    input_array[2] = 1.0f;
    input_array[3] = 1.0f;
    
    // Run the model
    hop_tanh_w4_r3(&input_tensor, &output_tensor);
    
    // Assert expected condition
    assert(!isgreaterequal(output_array[9], 0.999f));
    printf("Assertion checked. Output[9] = %f\n", output_array[9]);

    return 0;
}

void hop_tanh_w4_r3(k2c_tensor* simple_rnn_45_input_input, k2c_tensor* simple_rnn_45_output) {
    int simple_rnn_45_go_backwards = 0;
    int simple_rnn_45_return_sequences = 1;
    float simple_rnn_45_fwork[8] = {0}; 
    float simple_rnn_45_state[4] = {0}; 
    float simple_rnn_45_kernel_array[16] = {
        +1.00000000e+00f, +0.00000000e+00f, +0.00000000e+00f, +0.00000000e+00f, +0.00000000e+00f,
        +1.00000000e+00f, +0.00000000e+00f, +0.00000000e+00f, +0.00000000e+00f, +0.00000000e+00f,
        +1.00000000e+00f, +0.00000000e+00f, +0.00000000e+00f, +0.00000000e+00f, +0.00000000e+00f,
        +1.00000000e+00f,
    }; 
    k2c_tensor simple_rnn_45_kernel = {&simple_rnn_45_kernel_array[0], 2, 16, {4, 4, 1, 1, 1}};
    float simple_rnn_45_recurrent_kernel_array[16] = {
        +1.00000000e+00f, +1.00000000e+00f, +1.00000000e+00f, +1.00000000e+00f,
        +1.00000000e+00f, +1.00000000e+00f, +1.00000000e+00f, +1.00000000e+00f,
        +1.00000000e+00f, +1.00000000e+00f, +1.00000000e+00f, +1.00000000e+00f,
        +1.00000000e+00f, +1.00000000e+00f, +1.00000000e+00f, +1.00000000e+00f,
    }; 
    k2c_tensor simple_rnn_45_recurrent_kernel = {&simple_rnn_45_recurrent_kernel_array[0], 2, 16, {4, 4, 1, 1, 1}};
    float simple_rnn_45_bias_array[4] = {0}; 
    k2c_tensor simple_rnn_45_bias = {&simple_rnn_45_bias_array[0], 1, 4, {4, 1, 1, 1, 1}};

    k2c_simpleRNN(simple_rnn_45_output, 
                  simple_rnn_45_input_input, 
                  simple_rnn_45_state, 
                  &simple_rnn_45_kernel, 
                  &simple_rnn_45_recurrent_kernel, 
                  &simple_rnn_45_bias, 
                  simple_rnn_45_fwork, 
                  simple_rnn_45_go_backwards, 
                  simple_rnn_45_return_sequences, 
                  k2c_tanh);
}