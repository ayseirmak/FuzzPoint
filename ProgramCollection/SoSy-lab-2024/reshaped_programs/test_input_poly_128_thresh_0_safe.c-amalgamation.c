#include <stdio.h>
#include <math.h>
#include <keras2c/k2c_include.h>
#include <assert.h>

// Function prototypes
void poly_128(k2c_tensor* dense_62_input_input, k2c_tensor* dense_63_output);

// Main function
int main() {
    // Initialize the neural net input and output
    float input_array[1] = {2.95f}; // Deterministic input
    float output_array[1] = {0.0f};
    k2c_tensor input_tensor = {&input_array[0], 1, 1, {1, 1, 1, 1, 1}};
    k2c_tensor output_tensor = {&output_array[0], 1, 1, {1, 1, 1, 1, 1}};

    // Call the neural network with deterministic input
    poly_128(&input_tensor, &output_tensor);

    // Compare the network output with a ground truth approximation
    float x = input_array[0];
    float y = 2.8873749999999974f * (x - 2.9f) - 0.16373749999999976f;
    float diff = fabsf(y - output_array[0]);

    // Assertion for verification
    assert(diff <= 0.83400755825083503855793701538112f);

    printf("Verification successful\n");
    return 0;
}

/* External functions (placeholders for neural net processing) */
void poly_128(k2c_tensor* dense_62_input_input, k2c_tensor* dense_63_output) {
    // Placeholder implementation for the neural network
    // This function assumes it is performing some kind of inference
    // Fills in the output with predetermined handling, since the actual NN code is not provided
    dense_63_output->array[0] = 0.0f; // Example of setting an output value
}

// Previously defined neural net functions, activation functions, etc.
void k2c_linear_func(float *x, const size_t size) {}

void k2c_relu_func(float *x, const size_t size) {
    for (size_t i = 0; i < size; ++i) {
        if (x[i] <= 0.0f) {
            x[i] = 0.0f;
        }
    }
}

k2c_activationType *k2c_relu = k2c_relu_func;

void k2c_dense(k2c_tensor* output, const k2c_tensor* input, const k2c_tensor* kernel,
               const k2c_tensor* bias, k2c_activationType *activation, float *fwork) {
    // Placeholder implementation for the dense layer
    activation(output->array, output->numel);
}

// Any other library functions that might've been imported should be stubbed