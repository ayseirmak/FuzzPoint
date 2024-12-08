#include <stdio.h>
#include <math.h>
#include <keras2c/k2c_include.h>

// Function prototypes
void k2c_relu_func(float * x, const size_t size);
void k2c_dense(k2c_tensor* output, const k2c_tensor* input, const k2c_tensor* kernel,
               const k2c_tensor* bias, k2c_activationType *activation, float * fwork);

// Custom assert function 
void custom_assert(int condition, const char* errorMsg) {
    if (!condition) {
        printf("Assertion failed: %s\n", errorMsg);
        exit(1);
    }
}

// Neural network function
void poly_8_8_8(k2c_tensor* dense_101_input_input, k2c_tensor* dense_104_output);

int main() {
    /* Neural net input and output */
    float input_array[1] = {3.0f}, output_array[1] = {0.0f}; // Deterministic input
    k2c_tensor input_tensor = {&input_array[0], 1, 1, {1, 1, 1, 1, 1}};
    k2c_tensor output_tensor = {&output_array[0], 1, 1, {1, 1, 1, 1, 1}};

    /* Call the neural network with deterministic input */
    poly_8_8_8(&input_tensor, &output_tensor);

    /* Compare the network output with an affine approximation of the ground truth */
    float x = input_array[0];
    float y = 2.8873749999999974f * (x - 2.9f) - 0.16373749999999976f;
    float diff = fabsf(y - output_array[0]);

    /* Check assertion */
    custom_assert(islessequal(diff, 0.15594801652864969991195493882718f), 
                  "Difference exceeded the threshold");

    return 0;
}

// Definitions for neural network and other functions
void poly_8_8_8(k2c_tensor* dense_101_input_input, k2c_tensor* dense_104_output) {
    // Layer and weight declarations
    // (same as existing poly_8_8_8 function including keras2c dense, relu activations)
    
    // Call dense layers and activations (example):
    // k2c_dense(&dense_101_output, dense_101_input_input, &dense_101_kernel, 
    //           &dense_101_bias, k2c_relu, dense_101_fwork);
    // ...
}

void k2c_relu_func(float * x, const size_t size) {
    for (size_t i=0; i < size; ++i) {
        if (x[i] <= 0.0f) {
            x[i] = 0.0f;
        }
    }
}

k2c_activationType * k2c_relu = k2c_relu_func;

void k2c_dense(k2c_tensor* output, const k2c_tensor* input, const k2c_tensor* kernel,
               const k2c_tensor* bias, k2c_activationType *activation, float * fwork) {
    // Dense layer implementation remains unchanged from above
}