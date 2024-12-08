#include <stdio.h>
#include <math.h>
#include <string.h>
#include <assert.h>
#include <keras2c/k2c_include.h> 

void poly_32_32_32_32(k2c_tensor* input, k2c_tensor* output);

int main() {
    float input_array[1] = {3.0f}, output_array[1] = {0.0f}; // Deterministic input
    k2c_tensor input_tensor = {&input_array[0], 1, 1, {1, 1, 1, 1, 1}};
    k2c_tensor output_tensor = {&output_array[0], 1, 1, {1, 1, 1, 1, 1}};

    // Run the neural network with the fixed input
    poly_32_32_32_32(&input_tensor, &output_tensor);

    // Affine approximation for comparison
    float x = input_array[0];
    float y = 2.8873749999999974f * (x - 2.9f) - 0.16373749999999976f;
    float diff = fabsf(y - output_array[0]);

    // Using assert to replace __VERIFIER_assert
    assert(diff <= 0.03968868740433727168287742459264f); // Verification condition

    printf("Verification successful.\n");
    return 0;
}

void poly_32_32_32_32(k2c_tensor* input, k2c_tensor* output) {
    // Neural network simulation (content based on original logic)
    float dense_157_output_array[32] = {0};
    k2c_tensor dense_157_output = {&dense_157_output_array[0], 1, 32, {32, 1, 1, 1, 1}};
    float dense_157_kernel_array[32] = {
        -3.28245848e-01f,+5.83321713e-02f,+3.05656970e-01f, /*...*/ +4.00420815e-01f
    };
    k2c_tensor dense_157_kernel = {&dense_157_kernel_array[0], 2, 32, {1, 32, 1, 1, 1}};
    float dense_157_bias_array[32] = {
        -3.23861372e-03f,+2.87837297e-01f,+5.84023818e-02f, /*...*/ -1.72660500e-01f
    };
    k2c_tensor dense_157_bias = {&dense_157_bias_array[0], 1, 32, {32, 1, 1, 1, 1}};
    float dense_157_fwork[33] = {0};

    // Example layer operation, dependent on user implementation
    k2c_dense(&dense_157_output, input, &dense_157_kernel, &dense_157_bias, k2c_relu, dense_157_fwork);
    // Continue the operations as needed for other layers...
}