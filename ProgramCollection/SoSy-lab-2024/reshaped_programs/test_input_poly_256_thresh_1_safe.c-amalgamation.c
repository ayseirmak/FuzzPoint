#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <keras2c/k2c_include.h>
#include <keras2c/k2c_tensor_include.h>

// Define deterministic input
#define FIXED_INPUT 2.95f

// Function declaration
void poly_256(k2c_tensor* input_tensor, k2c_tensor* output_tensor);

int main() {
    // Initialize neural net input and output
    float input_array[1] = {0.0f}, output_array[1] = {0.0f};
    k2c_tensor input_tensor = {input_array, 1, 1, {1, 1, 1, 1, 1}};
    k2c_tensor output_tensor = {output_array, 1, 1, {1, 1, 1, 1, 1}};

    // Set the fixed input value
    float x = FIXED_INPUT;

    // Call the neural network with the fixed input
    input_array[0] = x;
    poly_256(&input_tensor, &output_tensor);

    // Compare the network output with an affine approximation of the ground truth
    float y = 2.8873749999999974f * (x - 2.9f) - 0.16373749999999976f;
    float diff = fabsf(y - output_array[0]);

    // Assert to verify the result
    assert(diff <= 0.29568518583452908589850588014649f);

    return 0;
}

// Neural network processing function
void poly_256(k2c_tensor* input_tensor, k2c_tensor* output_tensor) {
    // Simulated neural network operation (for demonstration purposes)
    // Here, you would include the actual neural network computation.
    // For simplicity and to adhere to constraints, let's assume a simple linear transform.
    output_tensor->array[0] = input_tensor->array[0] * 2.0f;  // Simple arbitrary operation
}