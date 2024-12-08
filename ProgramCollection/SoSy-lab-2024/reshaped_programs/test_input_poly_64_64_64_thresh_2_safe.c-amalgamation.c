#include <stdio.h>
#include <math.h>
#include <stddef.h>
#include <assert.h>
#include <keras2c/k2c_include.h>

// Activation function declarations
void k2c_relu_func(float *x, const size_t size);
k2c_activationType *k2c_relu = k2c_relu_func;

// Dense layer and model functions
void k2c_dense(k2c_tensor *output, const k2c_tensor *input, const k2c_tensor *kernel,
               const k2c_tensor *bias, k2c_activationType *activation, float *fwork);
void poly_64_64_64(k2c_tensor* dense_113_input_input, k2c_tensor* dense_116_output);

// Main function with deterministic input
int main() {
    // Neural network input and output
    float input_array[1] = {3.0f}; // Fixed value x = 3.0
    float output_array[1] = {0.0f};
    k2c_tensor input_tensor = {&input_array[0], 1, 1, {1, 1, 1, 1, 1}};
    k2c_tensor output_tensor = {&output_array[0], 1, 1, {1, 1, 1, 1, 1}};
    
    // Call the neural network with deterministic input
    poly_64_64_64(&input_tensor, &output_tensor);
    
    // Compare the network output with an affine approximation of the ground truth
    float x = 3.0f; // Using the fixed value of x directly for comparisons
    float y = 2.8873749999999974f * (x - 2.9f) - 0.16373749999999976f;
    float diff = fabsf(y - output_array[0]);
    
    // Verification with a fixed threshold
    assert(islessequal(diff, 0.01692513820885372f));
    
    // Output the result
    printf("Output: %f, Difference: %f\n", output_array[0], diff);
    
    return 0;
}

// Implementation of ReLU activation function
void k2c_relu_func(float *x, const size_t size) {
    for (size_t i = 0; i < size; ++i) {
        if (x[i] <= 0.0f) {
            x[i] = 0.0f;
        }
    }
}