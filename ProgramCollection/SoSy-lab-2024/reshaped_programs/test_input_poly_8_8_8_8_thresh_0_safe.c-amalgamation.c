#include <stdio.h>
#include <math.h>
#include <string.h>
#include <arm_neon.h>  // ARM compatibility
#include <keras2c/k2c_include.h>

// Prototypes for the neural network and activation functions
void poly_8_8_8_8(k2c_tensor* dense_147_input_input, k2c_tensor* dense_151_output);
void k2c_linear_func(float * x, const size_t size);
void k2c_relu_func(float * x, const size_t size);

// Define the activations
k2c_activationType *k2c_linear = k2c_linear_func;
k2c_activationType *k2c_relu = k2c_relu_func;

int main() {
    // Initialize input and output
    float input_array[1] = {3.0f}, output_array[1] = {0.0f};
    k2c_tensor input_tensor = {&input_array[0], 1, 1, {1, 1, 1, 1, 1}};
    k2c_tensor output_tensor = {&output_array[0], 1, 1, {1, 1, 1, 1, 1}};

    // Call the neural network with a fixed input
    poly_8_8_8_8(&input_tensor, &output_tensor);

    // Compare the network output with an affine approximation of the ground truth
    float x = input_array[0];
    float y = 2.8873749999999974f * (x - 2.9f) - 0.16373749999999976f;
    float diff = fabsf(y - output_array[0]);

    // Assert the output is within the expected difference
    if (!(diff <= 0.78488626437536795513285915923442f)) {
        printf("Assertion failed: output difference %f exceeds threshold.\n", diff);
        return 1;
    }
    
    printf("Verification successful.\n");
    return 0;
}

// Neural network function
void poly_8_8_8_8(k2c_tensor* dense_147_input_input, k2c_tensor* dense_151_output) {
    // Implement your neural network layers here using the helper functions
    // as seen in the original code
}

// Linear activation function
void k2c_linear_func(float * x, const size_t size) {
    // Linear activation: y = x (function is a placeholder here)
}

// ReLU activation function
void k2c_relu_func(float * x, const size_t size) {
    for (size_t i = 0; i < size; ++i) {
        if (x[i] <= 0.0f) {
            x[i] = 0.0f;
        }
    }
}