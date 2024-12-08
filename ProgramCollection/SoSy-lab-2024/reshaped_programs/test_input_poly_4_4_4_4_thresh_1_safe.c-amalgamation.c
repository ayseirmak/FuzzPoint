#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <keras2c/k2c_include.h>
#include <assert.h>

// Define a deterministic float value within the desired range
#define DETERMINISTIC_INPUT_FLOAT 3.0f

// Function declarations
void poly_4_4_4_4(k2c_tensor* input, k2c_tensor* output);
void k2c_dense(k2c_tensor* output, const k2c_tensor* input, const k2c_tensor* kernel,
               const k2c_tensor* bias, k2c_activationType *activation, float * fwork);

// Dummy implementations of activation functions for the sake of example
void k2c_relu_func(float * x, const size_t size) {
    for (size_t i = 0; i < size; ++i) {
        if (x[i] <= 0.0f) {
            x[i] = 0.0f;
        }
    }
}
k2c_activationType * k2c_relu = k2c_relu_func;

// Main function
int main()
{
    // Define fixed input and output arrays
    float input_array[1] = {DETERMINISTIC_INPUT_FLOAT};
    float output_array[1] = {0.0f};
    k2c_tensor input_tensor = {&input_array[0], 1, 1, {1,1,1,1,1}};
    k2c_tensor output_tensor = {&output_array[0], 1, 1, {1,1,1,1,1}};

    // Call the neural network function with deterministic input
    poly_4_4_4_4(&input_tensor, &output_tensor);

    // Compute the expected output using affine approximation
    float x = DETERMINISTIC_INPUT_FLOAT;
    float y = 2.8873749999999974f * (x - 2.9f) - 0.16373749999999976f;
    float diff = fabsf(y - output_array[0]);

    // Assert that the difference is within the acceptable range
    assert(islessequal(diff, 0.46752655864119633989740883736295f));

    // Output the result for verification purposes
    printf("Verification successful: %s\n", islessequal(diff, 0.46752655864119633989740883736295f) ? "Yes" : "No");

    return 0;
}

// Dummy function for neural network inference
void poly_4_4_4_4(k2c_tensor* input, k2c_tensor* output) {
    // Implement neural network inference logic here
    // Placeholder logic to demonstrate code structure
    output->array[0] = 0.0f; // Replace with actual computation
}