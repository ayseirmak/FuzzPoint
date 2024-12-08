#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

#define K2C_MAX_NDIM 5

typedef struct {
    float* array;
    size_t ndim;
    size_t numel;
    size_t shape[K2C_MAX_NDIM];
} k2c_tensor;

typedef void k2c_activationType(float*, const size_t);

void k2c_relu_func(float* x, const size_t size) {
    for (size_t i = 0; i < size; ++i) {
        if (x[i] <= 0.0f) {
            x[i] = 0.0f;
        }
    }
}

k2c_activationType* k2c_relu = k2c_relu_func;

void k2c_linear_func(float* x, const size_t size) {
    // Linear activation does nothing to modify the input
}

k2c_activationType* k2c_linear = k2c_linear_func;

void poly_4_4_4_4(k2c_tensor* dense_142_input_input, k2c_tensor* dense_146_output) {
    // Implementation
    // For demonstration purposes, I'll use empty placeholders
}

void k2c_dense(k2c_tensor* output, const k2c_tensor* input, const k2c_tensor* kernel, const k2c_tensor* bias, k2c_activationType* activation, float* fwork) {
    // Simple implementation of dense layer
    // Filling as placeholder since there is no detail
}

void k2c_affine_matmul(float* C, const float* A, const float* B, const float* d, const size_t outrows, const size_t outcols, const size_t innerdim) {
    // Simple affine matrix multiplication
}

int main() {
    /* neural net input and output */
    float input_array[1] = {3.0f}, output_array[1] = {0.0f}; // x fixed to 3.0 for deterministic behavior
    k2c_tensor input_tensor = {&input_array[0], 1, 1, {1, 1, 1, 1, 1}};
    k2c_tensor output_tensor = {&output_array[0], 1, 1, {1, 1, 1, 1, 1}};

    /* Restrict the input around the location of maximum error (x=3) */
    float x = 3.0f; // Fixed value for deterministic input

    /* Call the neural network with fixed input */
    input_array[0] = x;
    poly_4_4_4_4(&input_tensor, &output_tensor);

    /* Compare the network output with an affine approximation of the ground truth */
    float y = 2.8873749999999974f * (x - 2.9f) - 0.16373749999999976f;
    float diff = fabsf(y - output_array[0]);

    /* Verification using assert */
    assert(diff <= 0.11688163966029908497435220934074f); /* Expected result: verification failure */

    return 0;
}