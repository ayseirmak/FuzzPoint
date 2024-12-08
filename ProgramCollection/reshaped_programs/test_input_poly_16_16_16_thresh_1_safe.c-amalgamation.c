#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <keras2c/k2c_include.h>
#include <poly_approx/poly_16_16_16.h>

/* Constants */
#define FIXED_X -1.95f // Fixed input within the range [-2.0f, -1.9f]

void poly_16_16_16(k2c_tensor* dense_105_input_input, k2c_tensor* dense_108_output);

int main() {
    /* Neural net input and output */
    float input_array[1] = {0.0f}, output_array[1] = {0.0f};
    k2c_tensor input_tensor = {&input_array[0], 1, 1, {1, 1, 1, 1, 1}};
    k2c_tensor output_tensor = {&output_array[0], 1, 1, {1, 1, 1, 1, 1}};

    /* Use fixed value for input */
    float x = FIXED_X;

    /* Call the neural network with deterministic input */
    input_array[0] = x;
    poly_16_16_16(&input_tensor, &output_tensor);

    /* Compare the network output with an affine approximation of the ground truth */
    float y = -2.637375000000004f * (x + 2.0f) - 0.5f;
    float diff = fabsf(y - output_array[0]);

    /* Assertion check */
    assert(diff <= 0.16724308569288238290962524236347f);

    printf("Verification successful: diff = %f\n", diff);
    return 0;
}

void poly_16_16_16(k2c_tensor* dense_105_input_input, k2c_tensor* dense_108_output) {
    // Implementation of poly_16_16_16 goes here.
    // For the sake of example, we'll assume a dummy transformation
    // Modify this section according to your actual neural network implementation
    dense_108_output->array[0] = dense_105_input_input->array[0]; // Identity function example
    // Real implementation should be provided here
}

// Dummy implementations for required functions from the k2c library
void k2c_dense(k2c_tensor* output, const k2c_tensor* input, const k2c_tensor* kernel,
               const k2c_tensor* bias, k2c_activationType *activation, float *fwork) {
    // Implementation based on your neural network design
}