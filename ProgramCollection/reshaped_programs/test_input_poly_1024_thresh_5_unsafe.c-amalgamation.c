#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <keras2c/k2c_include.h>
#include <keras2c/k2c_tensor_include.h>

// Define the structs as needed for keras2c operations

void poly_1024(k2c_tensor* input_tensor, k2c_tensor* output_tensor) {
    // Arrays with fixed values used in the function
    float dense_68_output_array[1024] = {0};
    k2c_tensor dense_68_output = {dense_68_output_array, 1, 1024, {1024, 1, 1, 1, 1}};
    static const float dense_68_kernel_array[1024] = { /* Large predefined array of float values */ };
    k2c_tensor dense_68_kernel = {dense_68_kernel_array, 2, 1024, {1, 1024, 1, 1, 1}};
    static const float dense_68_bias_array[1024] = { /* Large predefined array of float values */ };
    k2c_tensor dense_68_bias = {dense_68_bias_array, 1, 1024, {1024, 1, 1, 1, 1}};
    float dense_68_fwork[1025] = {0};

    static const float dense_69_kernel_array[1024] = { /* Large predefined array of float values */ };
    k2c_tensor dense_69_kernel = {dense_69_kernel_array, 2, 1024, {1024, 1, 1, 1, 1}};
    static const float dense_69_bias_array[1] = { -1.86060406e-02f };
    k2c_tensor dense_69_bias = {dense_69_bias_array, 1, 1, {1, 1, 1, 1, 1}};
    float dense_69_fwork[2048] = {0};

    // Perform operations
    k2c_dense(&dense_68_output, input_tensor, &dense_68_kernel, &dense_68_bias, k2c_relu, dense_68_fwork);
    k2c_dense(output_tensor, &dense_68_output, &dense_69_kernel, &dense_69_bias, k2c_linear, dense_69_fwork);
}

int main() {
    // Deterministic input value
    float deterministic_x = 3.0f;

    // Neural net input and output
    float input_array[1] = {deterministic_x}, output_array[1] = {0.0f};
    k2c_tensor input_tensor = {input_array, 1, 1, {1, 1, 1, 1, 1}};
    k2c_tensor output_tensor = {output_array, 1, 1, {1, 1, 1, 1, 1}};

    // Call neural network
    poly_1024(&input_tensor, &output_tensor);

    // Compare the network output with an approximation
    float y = 2.8873749999999974f * (deterministic_x - 2.9f) - 0.16373749999999976f;
    float diff = fabsf(y - output_array[0]);

    // Assert whether the calculated difference is within the acceptable threshold
    assert(diff <= 0.00781257887349065423820901106559f);

    // Print assertion success
    printf("Assertion passed, difference is within acceptable threshold.\n");

    return 0;
}