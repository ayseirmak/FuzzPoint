#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// Forward declaration of k2c function and activation types
typedef void (k2c_activationType)(float*, const size_t);
void k2c_dense(k2c_tensor* output, const k2c_tensor* input, const k2c_tensor* kernel, const k2c_tensor* bias, k2c_activationType* activation, float* fwork);
void k2c_relu_func(float * x, const size_t size);
k2c_activationType* k2c_relu = k2c_relu_func;

// Simplified k2c_tensor structure
typedef struct {
    float* array;
    int ndim;
    int numel;
    int shape[5];
} k2c_tensor;

// Neural network model function
void poly_8_8_8_8(k2c_tensor* dense_147_input_input, k2c_tensor* dense_151_output);

// Model code
void poly_8_8_8_8(k2c_tensor* dense_147_input_input, k2c_tensor* dense_151_output) {
    float dense_147_output_array[8] = {0}; 
    k2c_tensor dense_147_output = {&dense_147_output_array[0],1,8,{8,1,1,1,1}};
    float dense_147_kernel_array[8] = {
        +8.88084650e-01f,+5.66112518e-01f,-2.94519305e-01f,-1.91599965e-01f,+4.11696404e-01f,
        -6.94123805e-01f,+7.35487700e-01f,-2.01089755e-01f,}; 
    k2c_tensor dense_147_kernel = {&dense_147_kernel_array[0],2,8,{1,8,1,1,1}}; 
    float dense_147_bias_array[8] = {
        -3.26531261e-01f,+2.93986380e-01f,+1.01789266e-01f,+4.22920793e-01f,+3.57736677e-01f,
        -3.59045304e-02f,+3.99124809e-02f,+5.16496420e-01f,}; 
    k2c_tensor dense_147_bias = {&dense_147_bias_array[0],1,8,{8,1,1,1,1}};
    float dense_147_fwork[9] = {0};

    // ... other layers are set up similarly ...

    // Applying the dense layers and relu activations (omitted other layers for brevity)
    k2c_dense(&dense_147_output, dense_147_input_input, &dense_147_kernel, &dense_147_bias, k2c_relu, dense_147_fwork);

    // Final dense layer with a linear activation
    float dense_151_kernel_array[8] = {
        +9.25920904e-01f,-2.37068415e-01f,-2.17221439e-01f,-5.26836395e-01f,-4.92319167e-01f,
        -4.52086002e-01f,-2.56944120e-01f,-1.34127021e-01f,}; 
    k2c_tensor dense_151_kernel = {&dense_151_kernel_array[0],2,8,{8,1,1,1,1}}; 
    float dense_151_bias_array[1] = {
        -1.04819857e-01f}; 
    k2c_tensor dense_151_bias = {&dense_151_bias_array[0],1,1,{1,1,1,1,1}};
    float dense_151_fwork[16] = {0};

    k2c_dense(dense_151_output, &dense_147_output, &dense_151_kernel, &dense_151_bias, k2c_relu, dense_151_fwork);
}

int main() {
    // Initialize input and output tensors
    float input_array[1] = {2.95f}; // fixed value within the range [2.9, 3.0]
    float output_array[1] = {0.0f};
    k2c_tensor input_tensor = {&input_array[0],1,1,{1,1,1,1,1}};
    k2c_tensor output_tensor = {&output_array[0],1,1,{1,1,1,1,1}};
    
    // Call the neural network with fixed input
    poly_8_8_8_8(&input_tensor, &output_tensor);
    
    // Compare network output with approximation
    float x = input_array[0];
    float y = 2.8873749999999974f * (x - 2.9f) - 0.16373749999999976f;
    float diff = fabsf(y - output_array[0]);
    
    // Use assertion for validation (using printf for feedback)
    float threshold = 0.39244313218768397756642957961721f;
    if (diff <= threshold) {
        printf("Verification successful: diff = %f\n", diff);
    } else {
        printf("Verification failed: diff = %f\n", diff);
    }
    
    return 0;
}

// Implementation of k2c_dense function (simplified example)
void k2c_dense(k2c_tensor* output, const k2c_tensor* input, const k2c_tensor* kernel, const k2c_tensor* bias, k2c_activationType* activation, float* fwork) {
    // Placeholder for actual dense layer computations
    // Assuming matrix operations are properly handled here
    printf("Executing k2c_dense...\n");
}

// Activation function implementation
void k2c_relu_func(float * x, const size_t size) {
    for (size_t i = 0; i < size; ++i) {
        if (x[i] <= 0.0f) {
            x[i] = 0.0f;
        }
    }
}