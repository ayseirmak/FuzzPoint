#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "k2c_include.h"  // Assuming you have a k2c include file
#include "poly_128.h"     // Assuming you have a poly approximation header

// Static variable to replace nondeterministic input
const float FIXED_X = 3.0f;

void poly_128(k2c_tensor* input_tensor, k2c_tensor* output_tensor);

int main() {
    /* neural net input and output */
    float input_array[1] = {0.0f}, output_array[1] = {0.0f};
    k2c_tensor input_tensor = {&input_array[0], 1, 1, {1, 1, 1, 1, 1}};
    k2c_tensor output_tensor = {&output_array[0], 1, 1, {1, 1, 1, 1, 1}};

    // Fixed input based on original assumption checks
    float x = FIXED_X;

    /* call the neural network with fixed input */
    input_array[0] = x;
    poly_128(&input_tensor, &output_tensor);

    /* compare the network output with an affine approximation of the ground truth */
    float y = 2.8873749999999974f * (x - 2.9f) - 0.16373749999999976f;
    float diff = fabsf(y - output_array[0]);

    /* Use standard assertion for verification */
    assert(diff <= 0.05212547239067718990987106346132f); // Expected result: verification failure

    return 0;
}

void poly_128(k2c_tensor* dense_62_input_input, k2c_tensor* dense_63_output) {
    // Implementation of poly_128
}

void poly_128_initialize() {
    // Initialization code if needed
}

void poly_128_terminate() {
    // Termination code if needed
}