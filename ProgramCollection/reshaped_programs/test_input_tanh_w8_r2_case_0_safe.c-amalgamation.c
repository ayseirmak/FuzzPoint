#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <keras2c/k2c_include.h>
#include <keras2c/k2c_tensor_include.h>

// Define the hop_tanh_w8_r2 function based on the existing implementation
void hop_tanh_w8_r2(k2c_tensor* input, k2c_tensor* output) {
    int simple_rnn_33_go_backwards = 0;
    int simple_rnn_33_return_sequences = 1;
    float simple_rnn_33_fwork[16] = {0};
    float simple_rnn_33_state[8] = {0};

    float simple_rnn_33_kernel_array[64] = {
        1.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,
        0.0f,1.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,
        0.0f,0.0f,1.0f,0.0f,0.0f,0.0f,0.0f,0.0f,
        0.0f,0.0f,0.0f,1.0f,0.0f,0.0f,0.0f,0.0f,
        0.0f,0.0f,0.0f,0.0f,1.0f,0.0f,0.0f,0.0f,
        0.0f,0.0f,0.0f,0.0f,0.0f,1.0f,0.0f,0.0f,
        0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,1.0f,0.0f,
        0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,1.0f,
    };

    k2c_tensor simple_rnn_33_kernel = {&simple_rnn_33_kernel_array[0], 2, 64, {8, 8, 1, 1, 1}};
    
    float simple_rnn_33_recurrent_kernel_array[64] = {
        1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,
        1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,
        1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,
        1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,
        1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,
        1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,
        1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,
        1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,
    };
    
    k2c_tensor simple_rnn_33_recurrent_kernel = {&simple_rnn_33_recurrent_kernel_array[0], 2, 64, {8, 8, 1, 1, 1}};
    
    float simple_rnn_33_bias_array[8] = {0};
    k2c_tensor simple_rnn_33_bias = {&simple_rnn_33_bias_array[0], 1, 8, {8, 1, 1, 1, 1}};
    
    k2c_simpleRNN(output, input, simple_rnn_33_state, &simple_rnn_33_kernel, 
                  &simple_rnn_33_recurrent_kernel, &simple_rnn_33_bias, simple_rnn_33_fwork, 
                  simple_rnn_33_go_backwards, simple_rnn_33_return_sequences, k2c_tanh);
}

int main() {
    float input_array[16] = {0.0f}, output_array[16] = {0.0f};
    k2c_tensor input_tensor = {&input_array[0], 2, 16, {2, 8, 1, 1, 1}};
    k2c_tensor output_tensor = {&output_array[0], 2, 16, {2, 8, 1, 1, 1}};

    // Deterministic inputs (fixed values)
    input_array[0] = 0.5f;
    input_array[1] = -0.5f;
    input_array[2] = 0.25f;
    input_array[3] = 1.0f;
    input_array[4] = 1.0f;
    input_array[5] = 1.0f;
    input_array[6] = 1.0f;
    input_array[7] = 1.0f;
    
    assert(input_array[0] >= -1.0f && input_array[0] <= 1.0f);
    assert(input_array[1] >= -1.0f && input_array[1] <= 1.0f);
    assert(input_array[2] >= -1.0f && input_array[2] <= 1.0f);

    hop_tanh_w8_r2(&input_tensor, &output_tensor);

    assert(isgreaterequal(output_array[8], 0.0f)); // Expected result: verification successful

    return 0;
}