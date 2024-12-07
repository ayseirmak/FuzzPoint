#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <keras2c/k2c_include.h>
#include <string.h>

// Function prototypes for neural network
void k2c_relu(float * x, const size_t size);
void k2c_linear(float * x, const size_t size);
void k2c_dense(k2c_tensor* output, const k2c_tensor* input, const k2c_tensor* kernel,
               const k2c_tensor* bias, void (*activation)(float*, const size_t), float * fwork);

// Function prototype for the poly_512 function
void poly_512(k2c_tensor* input, k2c_tensor* output);

int main() {
    // Neural net input and output
    float input_array[1] = {3.0f};  // Using a fixed deterministic input value
    float output_array[1] = {0.0f};
    k2c_tensor input_tensor = {&input_array[0], 1, 1, {1, 1, 1, 1, 1}};
    k2c_tensor output_tensor = {&output_array[0], 1, 1, {1, 1, 1, 1, 1}};

    // Call the neural network with fixed input
    poly_512(&input_tensor, &output_tensor);

    // Compare the network output with an affine approximation of the ground truth
    float x = input_array[0];
    float y = 2.887375 * (x - 2.9f) - 0.1637375;
    float diff = fabsf(y - output_array[0]);

    // Assertion to check the difference is within the expected range
    assert(diff <= 0.04422659467007662347904655134556f);

    // Output result
    printf("Difference: %f\n", diff);

    return 0;
}

// Definition of the poly_512 function
void poly_512(k2c_tensor* input, k2c_tensor* output) {
    float dense_66_output_array[512] = {0};
    k2c_tensor dense_66_output = {&dense_66_output_array[0], 1, 512, {512, 1, 1, 1, 1}};
    float dense_67_fwork[1024] = {0};

    // Assuming `dense_66_kernel`, `dense_66_bias`, `dense_67_kernel`, and `dense_67_bias` are defined elsewhere
    /* Placeholder variable definitions. In a real scenario, you would replace these with actual model weights and biases. */
    float dense_66_kernel_array[512] = {0};  // Initialize based on the model's requirements
    float dense_66_bias_array[512] = {0};    // Initialize based on the model's requirements
    float dense_67_kernel_array[512] = {0};  // Initialize based on the model's requirements
    float dense_67_bias_array[1] = {0};      // Initialize based on the model's requirements

    k2c_tensor dense_66_kernel = {&dense_66_kernel_array[0], 2, 512, {1, 512, 1, 1, 1}};
    k2c_tensor dense_66_bias = {&dense_66_bias_array[0], 1, 512, {512, 1, 1, 1, 1}};
    k2c_tensor dense_67_kernel = {&dense_67_kernel_array[0], 2, 512, {512, 1, 1, 1, 1}};
    k2c_tensor dense_67_bias = {&dense_67_bias_array[0], 1, 1, {1, 1, 1, 1, 1}};

    // Perform dense layer calculation with ReLU activation
    k2c_dense(&dense_66_output, input, &dense_66_kernel, &dense_66_bias, k2c_relu, dense_67_fwork);

    // Perform dense layer calculation with linear activation
    k2c_dense(output, &dense_66_output, &dense_67_kernel, &dense_67_bias, k2c_linear, dense_67_fwork);
}