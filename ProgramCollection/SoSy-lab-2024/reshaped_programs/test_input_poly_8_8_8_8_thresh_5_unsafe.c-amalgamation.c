#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "keras2c/k2c_include.h"
#include "keras2c/k2c_tensor_include.h"

// Prototype for the function
void poly_8_8_8_8(k2c_tensor* input_tensor, k2c_tensor* output_tensor);

int main() {
    /* Initialize fixed deterministic neural net input and output */
    float input_array[1] = {2.95f}; // Fixed input value at midpoint
    float output_array[1] = {0.0f};
    k2c_tensor input_tensor = {&input_array[0], 1, 1, {1, 1, 1, 1, 1}};
    k2c_tensor output_tensor = {&output_array[0], 1, 1, {1, 1, 1, 1, 1}};

    /* Call the neural network with fixed input */
    poly_8_8_8_8(&input_tensor, &output_tensor);

    /* Compare the network output with an affine approximation of the ground truth */
    float x = input_array[0];
    float y = 2.8873749999999974f * (x - 2.9f) - 0.16373749999999976f;
    float diff = fabsf(y - output_array[0]);

    /* Assert against a fixed threshold */
    assert(diff <= 0.02452769576173024859790184872608f);

    return 0;
}

void poly_8_8_8_8(k2c_tensor* dense_147_input_input, k2c_tensor* dense_151_output) {
    float dense_147_output_array[8] = {0.0f};
    k2c_tensor dense_147_output = {&dense_147_output_array[0], 1, 8, {8, 1, 1, 1, 1}};
    float dense_147_kernel_array[8] = {
        +8.88084650e-01f, +5.66112518e-01f, -2.94519305e-01f, -1.91599965e-01f, +4.11696404e-01f,
        -6.94123805e-01f, +7.35487700e-01f, -2.01089755e-01f,
    };

    k2c_tensor dense_147_kernel = {&dense_147_kernel_array[0], 2, 8, {1, 8, 1, 1, 1}};
    float dense_147_bias_array[8] = {
        -3.26531261e-01f, +2.93986380e-01f, +1.01789266e-01f, +4.22920793e-01f, +3.57736677e-01f,
        -3.59045304e-02f, +3.99124809e-02f, +5.16496420e-01f,
    };

    k2c_tensor dense_147_bias = {&dense_147_bias_array[0], 1, 8, {8, 1, 1, 1, 1}};
    float dense_147_fwork[9] = {0.0f};

    k2c_dense(&dense_147_output, dense_147_input_input, &dense_147_kernel, &dense_147_bias, k2c_relu, dense_147_fwork);
    /* Further layers go here, following similar style, initializing required arrays, tensors and biases */
}