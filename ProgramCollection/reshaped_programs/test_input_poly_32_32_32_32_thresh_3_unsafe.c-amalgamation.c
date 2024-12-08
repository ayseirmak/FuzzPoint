#include <math.h>
#include <stdio.h>
#include <assert.h>
#include <keras2c/k2c_include.h>
#include <poly_approx/poly_32_32_32_32.h>

void poly_32_32_32_32(k2c_tensor* input_tensor, k2c_tensor* output_tensor);

int main() {
    /* Neural net input and output */
    float input_array[1] = {0.0f}, output_array[1] = {0.0f};
    k2c_tensor input_tensor = {&input_array[0], 1, 1, {1, 1, 1, 1, 1}};
    k2c_tensor output_tensor = {&output_array[0], 1, 1, {1, 1, 1, 1, 1}};

    /* Fixed deterministic input */
    float x = 2.95f; // Fixed deterministic value within the given range
    
    /* Set the input into neural network */
    input_array[0] = x;
    poly_32_32_32_32(&input_tensor, &output_tensor);

    /* Compare the network output with an affine approximation of the ground truth */
    float y = 2.8873749999999974f * (x - 2.9f) - 0.16373749999999976f;
    float diff = fabsf(y - output_array[0]);

    /* Assert that the difference is within the allowed threshold */
    assert(diff <= 0.00992217185108431792071935614816f); // Expected result: verification failure

    return 0;
}

void poly_32_32_32_32(k2c_tensor* dense_157_input_input, k2c_tensor* dense_161_output) {

    // Neural Network implementation, including layers and activations
    // This example assumes the complete implementation of these functions:
    // k2c_dense, k2c_relu, among others.

    // Input tensor, kernel, bias, etc. are defined elsewhere as constants or variables
    // (Implementation of neural network is not shown here for brevity)

    // Call each layer function, e.g.:
    // k2c_dense(&dense_157_output, dense_157_input_input, &dense_157_kernel, &dense_157_bias, k2c_relu, dense_157_fwork);

    // End of the neural network function
}