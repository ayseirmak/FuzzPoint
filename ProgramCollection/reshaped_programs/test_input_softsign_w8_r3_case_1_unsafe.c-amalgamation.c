#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <string.h>
#include <keras2c/k2c_include.h>

// Function declarations
void hop_softsign_w8_r3(k2c_tensor *simple_rnn_19_input_input, k2c_tensor *simple_rnn_19_output);
void k2c_simpleRNN(k2c_tensor *output, const k2c_tensor *input, float *state,
                   const k2c_tensor *kernel, const k2c_tensor *recurrent_kernel,
                   const k2c_tensor *bias, float *fwork, const int go_backwards,
                   const int return_sequences, k2c_activationType *output_activation);
void k2c_softsign_func(float *x, const size_t size);

// Activation function
void k2c_softsign_func(float *x, const size_t size) {
    for (size_t i = 0; i < size; ++i) {
        x[i] = x[i] / (1.0f + fabsf(x[i]));
    }
}

// Tensor structure
typedef struct {
    float *array;
    size_t ndim;
    size_t numel;
    size_t shape[5];
} k2c_tensor;

// Simple RNN implementation
void k2c_simpleRNN(k2c_tensor *output, const k2c_tensor *input, float *state,
                   const k2c_tensor *kernel, const k2c_tensor *recurrent_kernel,
                   const k2c_tensor *bias, float *fwork, const int go_backwards,
                   const int return_sequences, k2c_activationType *output_activation) {

    const size_t in_width = input->shape[1];
    const size_t in_height = input->shape[0];
    const size_t units = recurrent_kernel->shape[1];

    if (go_backwards) {
        for (int i = in_height - 1; i > -1; --i) {
            // Call to Simple RNN cell simulation (simplified)
            for (size_t j = 0; j < units; ++j) {
                state[j] = input->array[i * in_width + j] + 
                           state[j] * recurrent_kernel->array[j];
                fwork[j] = state[j] * kernel->array[j];
            }
            output_activation(fwork, units);
            if (return_sequences) {
                for (size_t j = 0; j < units; ++j) {
                    output->array[(in_height - 1 - i) * units + j] = fwork[j] + bias->array[j];
                }
            }
        }
    } else {
        for (size_t i = 0; i < in_height; ++i) {
            // Call to Simple RNN cell simulation (simplified)
            for (size_t j = 0; j < units; ++j) {
                state[j] = input->array[i * in_width + j] + 
                           state[j] * recurrent_kernel->array[j];
                fwork[j] = state[j] * kernel->array[j];
            }
            output_activation(fwork, units);
            if (return_sequences) {
                for (size_t j = 0; j < units; ++j) {
                    output->array[i * units + j] = fwork[j] + bias->array[j];
                }
            }
        }
    }
    if (!return_sequences) {
        for (size_t i = 0; i < units; ++i) {
            output->array[i] = state[i];
        }
    }
}

// Softsign RNN function
void hop_softsign_w8_r3(k2c_tensor *simple_rnn_19_input_input, k2c_tensor *simple_rnn_19_output) {
    int simple_rnn_19_go_backwards = 0;
    int simple_rnn_19_return_sequences = 1;
    float simple_rnn_19_fwork[16] = {0};
    float simple_rnn_19_state[8] = {0};
    float simple_rnn_19_kernel_array[64] = {1.0f, 0.0f}; // Simplified for illustration
    k2c_tensor simple_rnn_19_kernel = {&simple_rnn_19_kernel_array[0], 2, 64, {8, 8, 1, 1, 1}};
    float simple_rnn_19_recurrent_kernel_array[64] = {1.0f, 1.0f}; // Simplified
    k2c_tensor simple_rnn_19_recurrent_kernel = {&simple_rnn_19_recurrent_kernel_array[0], 2, 64, {8, 8, 1, 1, 1}};
    float simple_rnn_19_bias_array[8] = {0};
    k2c_tensor simple_rnn_19_bias = {&simple_rnn_19_bias_array[0], 1, 8, {8, 1, 1, 1, 1}};

    k2c_simpleRNN(simple_rnn_19_output, simple_rnn_19_input_input, simple_rnn_19_state, &simple_rnn_19_kernel,
                  &simple_rnn_19_recurrent_kernel, &simple_rnn_19_bias, simple_rnn_19_fwork, 
                  simple_rnn_19_go_backwards, simple_rnn_19_return_sequences, k2c_softsign_func);
}

int main() {
    float input_array[24] = {0.1f, -0.5f, 0.25f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f};
    float output_array[24] = {0.0f};

    k2c_tensor input_tensor = {input_array, 2, 24, {3, 8, 1, 1, 1}};
    k2c_tensor output_tensor = {output_array, 2, 24, {3, 8, 1, 1, 1}};

    hop_softsign_w8_r3(&input_tensor, &output_tensor);

    assert(isgreaterequal(output_array[17], 0.81f));
    printf("Assertion passed!\n");

    return 0;
}