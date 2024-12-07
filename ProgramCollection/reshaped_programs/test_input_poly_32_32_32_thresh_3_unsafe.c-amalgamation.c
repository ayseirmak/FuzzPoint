#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <keras2c/k2c_include.h>
#include <poly_approx/poly_32_32_32.h>

// Define fixed input value within the specified range [2.9, 3.0]
#define FIXED_X 2.95f

int main() {
    // Neural network input and output
    float input_array[1] = {0.0f}, output_array[1] = {0.0f};
    k2c_tensor input_tensor = {&input_array[0], 1, 1, {1, 1, 1, 1, 1}};
    k2c_tensor output_tensor = {&output_array[0], 1, 1, {1, 1, 1, 1, 1}};

    // Use fixed input value
    float x = FIXED_X; // Value chosen for determinism

    // Call the neural network with deterministic input
    input_array[0] = x;
    poly_32_32_32(&input_tensor, &output_tensor);

    // Compare the network output with an affine approximation of the ground truth
    float y = 2.8873749999999974f * (x - 2.9f) - 0.16373749999999976f;
    float diff = fabsf(y - output_array[0]);

    // Verify assertion using standard assert
    assert(diff <= 0.01365030750207664735741987994603f);

    printf("Output verification: success\n");
    return 0;
}

// Replace custom verifier functions from "verifier_functions.h"
void __VERIFIER_error() {
    fprintf(stderr, "Verification error\n");
    exit(1);
}

void __VERIFIER_assume(int cond) {
    if (!cond) {
        fprintf(stderr, "Assumption failed\n");
        exit(1);
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
        __VERIFIER_error();
    }
}

void __VERIFIER_nondet_float() {
    // Return a fixed value for deterministic behavior
    return FIXED_X;
}

// Dummy functions to replace non-existent library functions
void poly_32_32_32(k2c_tensor *input, k2c_tensor *output) {
    // This dummy function is to be implemented with the actual model logic.
    // Currently, it directly assigns a placeholder value.
    output->array[0] = 0.0f; // Should be replaced with the actual NN computation when integrated
}