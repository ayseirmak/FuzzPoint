#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <string.h>
#include <keras2c/k2c_include.h>

// Dummy definition for k2c_simpleRNN which is assumed to exist
// This function needs to be properly defined or linked during actual use.
void k2c_simpleRNN(k2c_tensor* output, const k2c_tensor* input, float * state,
                   const k2c_tensor* kernel, const k2c_tensor* recurrent_kernel,
                   const k2c_tensor* bias, float * fwork, const int go_backwards,
                   const int return_sequences, k2c_activationType *output_activation) {
    // Function implementation goes here
}

void hop_softsign_w4_r3(k2c_tensor* simple_rnn_21_input_input, k2c_tensor* simple_rnn_21_output) {
    int simple_rnn_21_go_backwards = 0;
    int simple_rnn_21_return_sequences = 1;
    float simple_rnn_21_fwork[8] = {0}; 
    float simple_rnn_21_state[4] = {0}; 
    float simple_rnn_21_kernel_array[16] = {
        1.0f, 0.0f, 0.0f, 0.0f, 0.0f,
        1.0f, 0.0f, 0.0f, 0.0f, 0.0f,
        1.0f, 0.0f, 0.0f, 0.0f, 0.0f,
        1.0f};
    k2c_tensor simple_rnn_21_kernel = {simple_rnn_21_kernel_array, 2, 16, {4, 4, 1, 1, 1}};
    float simple_rnn_21_recurrent_kernel_array[16] = {
        1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
        1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
        1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
        1.0f};
    k2c_tensor simple_rnn_21_recurrent_kernel = {simple_rnn_21_recurrent_kernel_array, 2, 16, {4, 4, 1, 1, 1}};
    float simple_rnn_21_bias_array[4] = {0}; 
    k2c_tensor simple_rnn_21_bias = {simple_rnn_21_bias_array, 1, 4, {4, 1, 1, 1, 1}};

    k2c_simpleRNN(simple_rnn_21_output, simple_rnn_21_input_input, simple_rnn_21_state, &simple_rnn_21_kernel, 
        &simple_rnn_21_recurrent_kernel, &simple_rnn_21_bias, simple_rnn_21_fwork, 
        simple_rnn_21_go_backwards, simple_rnn_21_return_sequences, k2c_softsign);
}

int main(void) {
    float input_array[12] = {0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f};
    float output_array[12] = {0};

    k2c_tensor input_tensor = {input_array, 2, 12, {3, 4, 1, 1, 1}};
    k2c_tensor output_tensor = {output_array, 2, 12, {3, 4, 1, 1, 1}};

    hop_softsign_w4_r3(&input_tensor, &output_tensor);

    assert(isgreaterequal(output_array[9], 0.68f));

    printf("_All assertions passed!_\n");

    return 0;
}