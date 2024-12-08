#include <math.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

// Custom headers are removed due to the simplification of the program.

typedef struct {
    float * array;
    int ndim;
    int numel;
    size_t shape[5];
} k2c_tensor;

typedef void (k2c_activationType)(float *, const size_t);

void k2c_linear(float * x, const size_t size) {
    // Linear activation: no change.
}

void k2c_relu(float * x, const size_t size) {
    for (size_t i = 0; i < size; ++i) {
        if (x[i] < 0.0f) {
            x[i] = 0.0f;
        }
    }
}

void k2c_dense(k2c_tensor* output, const k2c_tensor* input, const k2c_tensor* kernel,
               const k2c_tensor* bias, k2c_activationType *activation, float * fwork) {

    if (input->ndim <= 2) {
        size_t outrows;

        if (input->ndim > 1) {
            outrows = input->shape[0];
        } else {
            outrows = 1;
        }
        const size_t outcols = kernel->shape[1];
        const size_t innerdim = kernel->shape[0];
        const size_t outsize = outrows * outcols;

        // Here one would perform affine matrix multiplication and add bias,
        // but since we're considering fixed inputs with known weights, we skip direct matrix multiplication.
        for (size_t i = 0; i < outrows; ++i) {
            for (size_t j = 0; j < outcols; ++j) {
                // Initialize result to bias
                output->array[i * outcols + j] = bias->array[j];
                // Perform matrix multiplication
                for (size_t k = 0; k < innerdim; ++k) {
                    output->array[i * outcols + j] += input->array[i * innerdim + k] * kernel->array[k * outcols + j];
                }
            }
        }
        activation(output->array, outsize);
    } else {
        // This part is skipped for simplicity as the process is similar for high dimensions.
    }
}

void poly_32_32_32(k2c_tensor* input, k2c_tensor* output) {
    static float dense_kernels[4][32] = { /* Placeholder for actual values */ };
    static float dense_biases[4][32] = { /* Placeholder for actual values */ };
    float work_space[32] = { 0 };
    k2c_tensor intermediate_output = { work_space, 1, 32, {32,1,1,1,1} };

    for (int i = 0; i < 3; ++i) {
        k2c_tensor kernel = { dense_kernels[i], 2, 1024, {32,32,1,1,1} };
        k2c_tensor bias = { dense_biases[i], 1, 32, {32,1,1,1,1} };
        k2c_dense(&intermediate_output, input, &kernel, &bias, k2c_relu, work_space);
        *input = intermediate_output;
    }

    k2c_tensor kernel_last = { dense_kernels[3], 2, 32, {32,1,1,1,1} };
    k2c_tensor bias_last = { dense_biases[3], 1, 1, {1,1,1,1,1} };
    k2c_dense(output, input, &kernel_last, &bias_last, k2c_linear, work_space);
}

int main() {
    float input_array[1] = {3.0f}, output_array[1] = {0.0f};
    k2c_tensor input_tensor = {input_array, 1, 1, {1,1,1,1,1}};
    k2c_tensor output_tensor = {output_array, 1, 1, {1,1,1,1,1}};

    poly_32_32_32(&input_tensor, &output_tensor);

    float x = input_array[0];
    float y = 2.8873749999999974f * (x - 2.9f) - 0.16373749999999976f;
    float diff = fabsf(y - output_array[0]);

    assert(diff <= 0.05460123000830658942967951978414f);

    return 0;
}