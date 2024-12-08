#include <math.h>
#include <stdio.h>
#include <assert.h>
#include <keras2c/k2c_include.h>
#include <poly_approx/poly_16_16_16.h>

// Initialize fixed input within required range
#define FIXED_INPUT -1.95f

void poly_16_16_16(k2c_tensor* input_tensor, k2c_tensor* output_tensor);

int main() {
    /* Neural net input and output */
    float input_array[1] = {0.0f}, output_array[1] = {0.0f};
    k2c_tensor input_tensor = {input_array, 1, 1, {1, 1, 1, 1, 1}};
    k2c_tensor output_tensor = {output_array, 1, 1, {1, 1, 1, 1, 1}};

    /* Use fixed input value */
    float x = FIXED_INPUT;

    /* Call the neural network with the fixed input */
    input_array[0] = x;
    poly_16_16_16(&input_tensor, &output_tensor);

    /* Compare the network output with an affine approximation of the ground truth */
    float y = -2.637375000000004f * (x + 2.0f) - 0.5f;
    float diff = fabsf(y - output_array[0]);

    /* Assertion instead of custom verifier function */
    assert(diff <= 0.08362154284644119145481262118174f);
    printf("Assertion successful, difference: %f\n", diff);

    return 0;
}

// Dummy implementation of poly_16_16_16 just for illustration
// In practice, this function will define the NN operations as in original code
void poly_16_16_16(k2c_tensor* input_tensor, k2c_tensor* output_tensor) {
    // This dummy function just copies input to output.
    // Replace code here with actual NN logic or function calls
    output_tensor->array[0] = 0.0f; // Example: set output to fixed 0.0f
}