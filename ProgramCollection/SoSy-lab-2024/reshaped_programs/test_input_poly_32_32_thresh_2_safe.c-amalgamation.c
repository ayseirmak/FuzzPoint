#include <math.h>
#include <stdio.h>
#include <assert.h> // Standard assert library
#include <keras2c/k2c_include.h>
#include <poly_approx/poly_32_32.h>

// Define and initialize the neural network's input and output
float input_array[1] = {3.0f}; // Fixed input within the specified range
float output_array[1] = {0.0f};
k2c_tensor input_tensor = {&input_array[0], 1, 1, {1, 1, 1, 1, 1}};
k2c_tensor output_tensor = {&output_array[0], 1, 1, {1, 1, 1, 1, 1}};

// Neural network model calling function
void run_model() {
    poly_32_32(&input_tensor, &output_tensor);
}

// Validation function
void validate_result(float x) {
    float y = 2.8873749999999974f * (x - 2.9f) - 0.16373749999999976f;
    float diff = fabsf(y - output_array[0]);
    assert(diff <= 0.13659214219092473110037232981620f); // Assert to replace __VERIFIER_assert
}

int main() {
    // Call the model function with the initialized input tensor
    run_model();

    // Validate the model output with a fixed input within the desired range
    validate_result(input_array[0]);

    // Return with successful execution
    return 0;
}