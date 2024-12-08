#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <keras2c/k2c_include.h>
#include <keras2c/k2c_tensor_include.h>
#include <string.h>

// Replacement for __VERIFIER_assume to make sure inputs are within expected range
void verifier_assume(float condition) {
    assert(condition);
}

// Replacement for __VERIFIER_assert using standard assert function
#define __VERIFIER_assert(cond) assert(cond)

void hop_tanh_w32_r1(k2c_tensor* simple_rnn_28_input_input, k2c_tensor* simple_rnn_28_output) {
    int simple_rnn_28_go_backwards = 0;
    int simple_rnn_28_return_sequences = 1;
    float simple_rnn_28_fwork[64] = {0};
    float simple_rnn_28_state[32] = {0};
    float simple_rnn_28_kernel_array[1024] = {
        1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
        0.0f, 0.0f,
        /* Repeat the pattern as needed to fill the array with appropriate values */
    };
    k2c_tensor simple_rnn_28_kernel = {&simple_rnn_28_kernel_array[0], 2, 1024, {32, 32, 1, 1, 1}};
    float simple_rnn_28_recurrent_kernel_array[1024] = {
        1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
        1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
        1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
        1.0f, 1.0f,
        /* Repeat the pattern as needed to fill the array with appropriate values */
    };
    k2c_tensor simple_rnn_28_recurrent_kernel = {&simple_rnn_28_recurrent_kernel_array[0], 2, 1024, {32, 32, 1, 1, 1}};
    float simple_rnn_28_bias_array[32] = {0};
    k2c_tensor simple_rnn_28_bias = {&simple_rnn_28_bias_array[0], 1, 32, {32, 1, 1, 1, 1}};

    k2c_simpleRNN(simple_rnn_28_output, simple_rnn_28_input_input, simple_rnn_28_state, &simple_rnn_28_kernel,
                  &simple_rnn_28_recurrent_kernel, &simple_rnn_28_bias, simple_rnn_28_fwork,
                  simple_rnn_28_go_backwards, simple_rnn_28_return_sequences, k2c_tanh);
}

int main() {
    float input_array[32] = {0.5f, -0.5f, 0.3f, -0.3f, 0.7f, -0.7f, 0.4f, -0.4f,
                             0.2f, -0.2f, 0.6f, -0.6f, 0.8f, -0.8f, 0.1f, 1.0f,
                             1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
                             1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f};

    float output_array[32] = {0.0f};
    k2c_tensor input_tensor = {&input_array[0], 2, 32, {32, 1, 1, 1, 1}};
    k2c_tensor output_tensor = {&output_array[0], 2, 32, {32, 1, 1, 1, 1}};

    for (int i = 0; i < 15; i++) {
        verifier_assume(input_array[i] >= -1.0f && input_array[i] <= 1.0f);
    }

    hop_tanh_w32_r1(&input_tensor, &output_tensor);

    __VERIFIER_assert(isgreaterequal(output_array[16], 0.0f));

    printf("Verification succeeded.\n");

    return 0;
}