#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <keras2c/k2c_include.h>
#include <keras2c/k2c_tensor_include.h>

// Placeholder function for the neural network call, potentially replaced by actual implementation
void poly_32_32_32(k2c_tensor* input, k2c_tensor* output) {
    // Dummy implementation - this needs the actual neural network logic
    // For demo purposes, we perform an identity operation.
    for (size_t i = 0; i < input->numel; ++i) {
        output->array[i] = input->array[i];
    }
}

int main() {
    // Predefined deterministic input
    float x = 2.95f;

    // Neural network input and output setup
    float input_array[1] = {x}, output_array[1] = {0.0f};
    k2c_tensor input_tensor = {&input_array[0], 1, 1, {1, 1, 1, 1, 1}};
    k2c_tensor output_tensor = {&output_array[0], 1, 1, {1, 1, 1, 1, 1}};

    // Call the neural network
    poly_32_32_32(&input_tensor, &output_tensor);

    // Compare the network output with a fixed affine approximation
    float y = 2.8873749999999974f * (x - 2.9f) - 0.16373749999999976f;
    float diff = fabsf(y - output_array[0]);

    // Assert the difference is within the acceptable threshold
    assert(islessequal(diff, 0.02730061500415329471483975989207f));

    printf("Verification successful: diff = %.10f\n", diff);

    return 0;
}