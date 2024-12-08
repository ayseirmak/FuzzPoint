#include <stdio.h>
#include <math.h>
#include <keras2c/k2c_include.h>
#include <assert.h>

// Define realistic fixed inputs for deterministic behavior
#define FIXED_INPUT 2.95f

// Function prototype
void poly_256(k2c_tensor* dense_64_input_input, k2c_tensor* dense_65_output);

int main() {
    /* Neural net input and output */
    float input_array[1] = {0.0f}, output_array[1] = {0.0f};
    k2c_tensor input_tensor = {&input_array[0], 1, 1, {1, 1, 1, 1, 1}};
    k2c_tensor output_tensor = {&output_array[0], 1, 1, {1, 1, 1, 1, 1}};

    // Use fixed value as input instead of nondeterministic value
    float x = FIXED_INPUT;

    /* Call the neural network with the fixed input */
    input_array[0] = x;
    poly_256(&input_tensor, &output_tensor);

    /* Compare the network output with an affine approximation of the ground truth */
    float y = 2.8873749999999974f * (x - 2.9f) - 0.16373749999999976f;
    float diff = fabsf(y - output_array[0]);

    /* Assert the condition (acts as __VERIFIER_assert) */
    // Threshold provided as fixed for verifying the output
    assert(diff <= 0.01848032411465806786865661750916f);

    printf("Verification passed with diff = %f\n", diff);

    return 0;
}

// This is an example function for illustration; you should replace it with your actual neural network processing
void poly_256(k2c_tensor* dense_64_input_input, k2c_tensor* dense_65_output) {
    // This function would presumably do some processing with a neural net
}