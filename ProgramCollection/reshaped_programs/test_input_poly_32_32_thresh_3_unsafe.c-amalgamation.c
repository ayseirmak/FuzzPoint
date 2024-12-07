#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <stdint.h>
#include <string.h>
#include <keras2c/k2c_include.h>

// Define the neural network layers and activation functions used (placeholders)
void poly_32_32(k2c_tensor* dense_76_input_input, k2c_tensor* dense_78_output) {
    // Placeholder for the neural network function
    // Add the specific neural network computation here
}

// The main function
int main() {
    // Neural net input and output
    float input_array[1] = {0.0f}, output_array[1] = {0.0f};
    k2c_tensor input_tensor = {&input_array[0], 1, 1, { 1, 1, 1, 1, 1 }};
    k2c_tensor output_tensor = {&output_array[0], 1, 1, { 1, 1, 1, 1, 1 }};
    
    // Define a concrete value for x
    float x = 2.95f;  // Example fixed value within the range [2.9, 3.0]

    // Assign the deterministic input to the network
    input_array[0] = x;
    poly_32_32(&input_tensor, &output_tensor);

    // Compare network output with an affine approximation of the ground truth
    float y = 2.8873749999999974f * (x - 2.9f) - 0.16373749999999976f;
    float diff = fabsf(y - output_array[0]);

    // Assert to check condition
    assert(diff <= 0.06829607109546236555018616490810f);

    return 0;
}