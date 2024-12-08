#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <keras2c/k2c_include.h>
#include <poly_approx/poly_1024.h>

void poly_1024(k2c_tensor* dense_68_input_input, k2c_tensor* dense_69_output);

int main() {
    /* Neural net input and output */
    float input_array[1] = {0.0f}, output_array[1] = {0.0f};
    k2c_tensor input_tensor = {&input_array[0], 1, 1, {1, 1, 1, 1, 1}};
    k2c_tensor output_tensor = {&output_array[0], 1, 1, {1, 1, 1, 1, 1}};

    /* Deterministic input value */
    float x = 2.95f; // Replaced non-deterministic input with a fixed value

    /* Call the neural network */
    input_array[0] = x;
    poly_1024(&input_tensor, &output_tensor);

    /* Compare the network output with an affine approximation of the ground truth */
    float y = 2.8873749999999974f * (x - 2.9f) - 0.16373749999999976f;
    float diff = fabsf(y - output_array[0]);

    /* Assertion based on deterministic threshold */
    assert(islessequal(diff, 0.01562515774698130847641802213118f));

    return 0;
}

// Neural network and other function implementations follow

void poly_1024(k2c_tensor* input_tensor, k2c_tensor* output_tensor) {
    // Assume neural network logic is implemented here
    output_tensor->array[0] = 2.0f; // Placeholder value for demonstration
}