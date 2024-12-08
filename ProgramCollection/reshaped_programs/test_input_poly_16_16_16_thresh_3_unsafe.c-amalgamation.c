#include <math.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <keras2c/k2c_include.h>
#include <poly_approx/poly_16_16_16.h>

// Function Prototypes
void poly_16_16_16_initialize();
void poly_16_16_16_terminate();

int main() {
    // Neural net input and output
    float input_array[1] = {0.0f}, output_array[1] = {0.0f};
    k2c_tensor input_tensor = {&input_array[0], 1, 1, {1, 1, 1, 1, 1}};
    k2c_tensor output_tensor = {&output_array[0], 1, 1, {1, 1, 1, 1, 1}};

    // Fixed input value, simulating non-deterministic choice within range [-2.0f, -1.9f]
    float x = -1.95f;  // Choose a fixed value within [-2.0, -1.90]

    // Call the neural network with fixed input
    input_array[0] = x;
    poly_16_16_16(&input_tensor, &output_tensor);

    // Compare the network output with an affine approximation of the ground truth
    float y = -2.637375000000004f * (x + 2.0f) - 0.5f;
    float diff = fabsf(y - output_array[0]);

    // Assert the output is within the expected threshold
    assert(islessequal(diff, 0.04181077142322059572740631059087f));

    return 0;
}

// Implement the function stubs
void poly_16_16_16_initialize() {
    // Any required initialization code
}

void poly_16_16_16_terminate() {
    // Any required termination code
}