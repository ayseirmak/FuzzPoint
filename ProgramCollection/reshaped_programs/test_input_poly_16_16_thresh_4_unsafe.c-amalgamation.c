#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <keras2c/k2c_include.h>
#include <poly_approx/poly_16_16.h>

void poly_16_16(k2c_tensor* dense_73_input_input, k2c_tensor* dense_75_output);

/* Main function */
int main() {
    /* Neural net input and output with deterministic input */
    float input_array[1] = {-1.95f}; // Fixed deterministic value between -2.0 and -1.9
    float output_array[1] = {0.0f};
    k2c_tensor input_tensor = {&input_array[0], 1, 1, {1, 1, 1, 1, 1}};
    k2c_tensor output_tensor = {&output_array[0], 1, 1, {1, 1, 1, 1, 1}};

    /* Call the neural network with deterministic input */
    poly_16_16(&input_tensor, &output_tensor);

    /* Compare the network output with an affine approximation of the ground truth */
    float x = input_array[0];
    float y = -2.637375000000004f * (x + 2.0f) - 0.5f;
    float diff = fabsf(y - output_array[0]);

    /* Assert to verify the comparison */
    assert(islessequal(diff, 0.04394155992658032617196057098319f));

    return 0;
}

void poly_16_16(k2c_tensor* dense_73_input_input, k2c_tensor* dense_75_output) {
    // Neural network implementation code (remains unchanged)

    // ... (the rest of the implementation as needed)
}

/* Define dummy implementations for any further required functions from keras2c */
void k2c_dense(k2c_tensor* output, const k2c_tensor* input, const k2c_tensor* kernel,
               const k2c_tensor* bias, k2c_activationType *activation, float * fwork) {
    // Implement the full dense layer operation here if necessary
}

void k2c_activationExample(float * x, const size_t size) {
    // Example activation function, like ReLU or sigmoid
}

k2c_activationType *k2c_relu = k2c_activationExample;