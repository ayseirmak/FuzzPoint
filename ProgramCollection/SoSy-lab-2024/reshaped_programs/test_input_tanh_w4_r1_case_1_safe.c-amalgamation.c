#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>
#include <keras2c/k2c_include.h>
#include <keras2c/k2c_tensor_include.h>

void hop_tanh_w4_r1(k2c_tensor* simple_rnn_31_input_input, k2c_tensor* simple_rnn_31_output);
void k2c_simpleRNN(k2c_tensor* output, const k2c_tensor* input, float* state, 
                   const k2c_tensor* kernel, const k2c_tensor* recurrent_kernel, 
                   const k2c_tensor* bias, float* fwork, int go_backwards, 
                   int return_sequences, k2c_activationType* output_activation);

int main() {
    // Initialize input and output arrays with predefined values
    // Assuming a deterministic float value for VERIFIER_nondet_float
    float input_array[4] = {0.5f, 1.0f, 1.0f, 1.0f}; // 0.5f replaces nondeterministic value
    float output_array[4] = {0.0f};

    k2c_tensor input_tensor = {&input_array[0], 2, 4, {1, 4, 1, 1, 1}};
    k2c_tensor output_tensor = {&output_array[0], 2, 4, {1, 4, 1, 1, 1}};

    // Ensure input array is within expected range via assertion
    assert(input_array[0] >= -1.0f && input_array[0] <= 1.0f);

    // Call the Hopfield tanh function
    hop_tanh_w4_r1(&input_tensor, &output_tensor);

    // Use assert for verification of output
    assert(isgreaterequal(output_array[2], 0.0f));

    return 0;
}

void hop_tanh_w4_r1(k2c_tensor* simple_rnn_31_input_input, k2c_tensor* simple_rnn_31_output) {
    int simple_rnn_31_go_backwards = 0;
    int simple_rnn_31_return_sequences = 1;
    float simple_rnn_31_fwork[8] = {0}; 
    float simple_rnn_31_state[4] = {0}; 
    float simple_rnn_31_kernel_array[16] = {
        +1.00000000e+00f, +0.00000000e+00f, +0.00000000e+00f, +0.00000000e+00f,
        +0.00000000e+00f, +1.00000000e+00f, +0.00000000e+00f, +0.00000000e+00f,
        +0.00000000e+00f, +0.00000000e+00f, +1.00000000e+00f, +0.00000000e+00f,
        +0.00000000e+00f, +0.00000000e+00f, +0.00000000e+00f, +1.00000000e+00f
    }; 
    k2c_tensor simple_rnn_31_kernel = {&simple_rnn_31_kernel_array[0], 2, 16, {4, 4, 1, 1, 1}};
    float simple_rnn_31_recurrent_kernel_array[16] = {
        +1.00000000e+00f, +1.00000000e+00f, +1.00000000e+00f, +1.00000000e+00f,
        +1.00000000e+00f, +1.00000000e+00f, +1.00000000e+00f, +1.00000000e+00f,
        +1.00000000e+00f, +1.00000000e+00f, +1.00000000e+00f, +1.00000000e+00f,
        +1.00000000e+00f, +1.00000000e+00f, +1.00000000e+00f, +1.00000000e+00f
    }; 
    k2c_tensor simple_rnn_31_recurrent_kernel = {&simple_rnn_31_recurrent_kernel_array[0], 2, 16, {4, 4, 1, 1, 1}};
    float simple_rnn_31_bias_array[4] = {0}; 
    k2c_tensor simple_rnn_31_bias = {&simple_rnn_31_bias_array[0], 1, 4, {4, 1, 1, 1, 1}};

    k2c_simpleRNN(simple_rnn_31_output, simple_rnn_31_input_input, simple_rnn_31_state, 
                  &simple_rnn_31_kernel, &simple_rnn_31_recurrent_kernel,
                  &simple_rnn_31_bias, simple_rnn_31_fwork, 
                  simple_rnn_31_go_backwards, simple_rnn_31_return_sequences, k2c_tanh); 
}