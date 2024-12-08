#include <stdio.h>
#include <math.h>
#include <keras2c/k2c_include.h>
#include <keras2c/k2c_tensor_include.h>

// Fixed input value for determinism
static const float fixed_input_value = 0.5f;

void hop_softsign_w4_r2(k2c_tensor* input_tensor, k2c_tensor* output_tensor) {
    int simple_rnn_7_go_backwards = 0;
    int simple_rnn_7_return_sequences = 1;
    float simple_rnn_7_fwork[8] = {0};
    float simple_rnn_7_state[4] = {0};
    float simple_rnn_7_kernel_array[16] = {
        1.0f, 0.0f, 0.0f, 0.0f, 0.0f,
        1.0f, 0.0f, 0.0f, 0.0f, 0.0f,
        1.0f, 0.0f, 0.0f, 0.0f, 0.0f,
        1.0f,
    };
    k2c_tensor simple_rnn_7_kernel = {&simple_rnn_7_kernel_array[0], 2, 16, {4, 4, 1, 1, 1}};
    float simple_rnn_7_recurrent_kernel_array[16] = {
        1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
        1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
        1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
        1.0f,
    };
    k2c_tensor simple_rnn_7_recurrent_kernel = {&simple_rnn_7_recurrent_kernel_array[0], 2, 16, {4, 4, 1, 1, 1}};
    float simple_rnn_7_bias_array[4] = {0};
    k2c_tensor simple_rnn_7_bias = {&simple_rnn_7_bias_array[0], 1, 4, {4, 1, 1, 1, 1}};

    k2c_simpleRNN(output_tensor, input_tensor, simple_rnn_7_state, &simple_rnn_7_kernel,
                  &simple_rnn_7_recurrent_kernel, &simple_rnn_7_bias, simple_rnn_7_fwork,
                  simple_rnn_7_go_backwards, simple_rnn_7_return_sequences, k2c_softsign);
}

int main() {
    float input_array[8] = {0.0f}, output_array[8] = {0.0f};
    k2c_tensor input_tensor = {&input_array[0], 2, 8, {2, 4, 1, 1, 1}};
    k2c_tensor output_tensor = {&output_array[0], 2, 8, {2, 4, 1, 1, 1}};

    // Fixed deterministic input
    input_array[0] = fixed_input_value;
    input_array[1] = 1.0f;
    input_array[2] = 1.0f;
    input_array[3] = 1.0f;

    hop_softsign_w4_r2(&input_tensor, &output_tensor);

    // Check condition and print result
    if (isgreaterequal(output_array[4], 0.0f)) {
        printf("Verification successful: output_array[4] = %f\n", output_array[4]);
    } else {
        printf("Verification failed: output_array[4] = %f\n", output_array[4]);
    }

    return 0;
}