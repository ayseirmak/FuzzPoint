#include <math.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <keras2c/k2c_include.h>
#include <keras2c/k2c_tensor_include.h>

// Function prototype for the neural network
void poly_16_16_16_16(k2c_tensor* dense_152_input_input, k2c_tensor* dense_156_output);

int main() {
    // Neural net input and output
    float input_array[1] = {-1.53f}; // Fixed deterministic input value
    float output_array[1] = {0.0f};
    k2c_tensor input_tensor = {&input_array[0], 1, 1, {1, 1, 1, 1, 1}};
    k2c_tensor output_tensor = {&output_array[0], 1, 1, {1, 1, 1, 1, 1}};

    // Call the neural network with fixed input
    poly_16_16_16_16(&input_tensor, &output_tensor);

    // Compare the network output with an affine approximation of the ground truth
    float x = -1.53f; // Aligns with modified deterministic input
    float y = -0.25400099999999926f * (x + 1.58f) - 1.18722038f;
    float diff = fabsf(y - output_array[0]);

    // Assertion replaced with assert from <assert.h> to verify the condition
    assert(diff <= 0.00707839343811856787636123636864f); // Verification condition

    return 0;
}

// Include the k2c_linear, k2c_relu, and other functions necessary
// ...

// Include the entire poly_16_16_16_16 function implementation as it contains
// specific detailed neural network calculations
void poly_16_16_16_16(k2c_tensor* dense_152_input_input, k2c_tensor* dense_156_output) {
    // Original poly_16_16_16_16 function code goes here
    // ...
}