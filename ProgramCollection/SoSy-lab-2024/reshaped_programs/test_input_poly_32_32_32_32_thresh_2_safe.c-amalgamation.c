#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <string.h>
#include <keras2c/k2c_include.h>

// Define deterministic input for testing
#define TEST_INPUT_VALUE 2.95f

// Forward declaration
void poly_32_32_32_32(k2c_tensor* dense_157_input_input, k2c_tensor* dense_161_output);

// Main function
int main() {
    /* Neural network input and output */
    float input_array[1] = {TEST_INPUT_VALUE}, output_array[1] = {0.0f};
    k2c_tensor input_tensor = {input_array, 1, 1, {1, 1, 1, 1, 1}};
    k2c_tensor output_tensor = {output_array, 1, 1, {1, 1, 1, 1, 1}};

    /* Call the neural network function with deterministic input */
    poly_32_32_32_32(&input_tensor, &output_tensor);

    /* Compare the network output with an affine approximation of the ground truth */
    float x = TEST_INPUT_VALUE;
    float y = 2.8873749999999974f * (x - 2.9f) - 0.16373749999999976f;
    float diff = fabsf(y - output_tensor.array[0]);

    /* Assert check on the difference threshold */
    assert(diff <= 0.01984434370216864f);

    return 0;
}

// Neural network definition
void poly_32_32_32_32(k2c_tensor* dense_157_input_input, k2c_tensor* dense_161_output) {
    /* Layer specific arrays for sample neural network model. Replace with actual values as needed. */
    float dense_157_output_array[32] = {0};
    k2c_tensor dense_157_output = {dense_157_output_array, 1, 32, {32, 1, 1, 1, 1}};
    float dense_157_kernel_array[32] = {
        /* Initialized weights for dense_157 kernel; replace with actual values */
    };
    k2c_tensor dense_157_kernel = {dense_157_kernel_array, 2, 32, {1, 32, 1, 1, 1}};
    float dense_157_bias_array[32] = {
        /* Initialized biases for dense_157, replace with real biases */
    };
    k2c_tensor dense_157_bias = {dense_157_bias_array, 1, 32, {32, 1, 1, 1, 1}};
    float dense_157_fwork[33] = {0};

    // Perform operations typical of a layer
    k2c_dense(&dense_157_output, dense_157_input_input, &dense_157_kernel, &dense_157_bias, k2c_relu, dense_157_fwork);

    /* More layers would follow similarly for dense_158, dense_159, dense_160, and output layer, dense_161. */
}