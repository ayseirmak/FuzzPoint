#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <keras2c/k2c_include.h>

// Function prototypes for the neural network operations
void poly_256(k2c_tensor* input_tensor, k2c_tensor* output_tensor);
void k2c_dense(k2c_tensor* output, const k2c_tensor* input, const k2c_tensor* kernel,
               const k2c_tensor* bias, k2c_activationType *activation, float *fwork);

void k2c_linear_func(float *x, const size_t size);
void k2c_relu_func(float *x, const size_t size);

// Main function
int main() {
    // Neural Net input and output
    float input_array[1] = {3.0f}, output_array[1] = {0.0f};
    k2c_tensor input_tensor = {&input_array[0], 1, 1, {1, 1, 1, 1, 1}};
    k2c_tensor output_tensor = {&output_array[0], 1, 1, {1, 1, 1, 1, 1}};

    // Neural network computation with deterministic input
    poly_256(&input_tensor, &output_tensor);

    // Compare the network output with an affine approximation of the ground truth
    float x = input_array[0];
    float y = 2.8873749999999974f * (x - 2.9f) - 0.16373749999999976f;
    float diff = fabsf(y - output_array[0]);

    // Assertion for verification
    assert(islessequal(diff, 0.07392129645863227147462647003662f));

    return 0;
}

// Linear activation function
void k2c_linear_func(float *x, const size_t size) {
    // Input is output in linear activation
}

// ReLU activation function
void k2c_relu_func(float *x, const size_t size) {
    for (size_t i = 0; i < size; ++i) {
        if (x[i] <= 0.0f) {
            x[i] = 0.0f;
        }
    }
}

// Poly approximation function (simplified)
void poly_256(k2c_tensor* input_tensor, k2c_tensor* output_tensor) {
    // Dummy implementation for demonstration
    output_tensor->array[0] = input_tensor->array[0] + 0.1f; // Simple operation
}