#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <string.h>

// Custom data structure for tensors
typedef struct {
    float* array;
    int size;
    int numel;
    int shape[5];
} k2c_tensor;

// Dummy definition to make program self-contained
void k2c_dense(k2c_tensor* output, const k2c_tensor* input, const k2c_tensor* kernel,
               const k2c_tensor* bias, void (*activation)(float *, size_t), float * fwork) {
    // Simplified dense layer function
    for (int i = 0; i < output->numel; ++i) {
        output->array[i] = 0;
        for (int j = 0; j < input->numel; ++j) {
            output->array[i] += input->array[j] * kernel->array[i * input->numel + j];
        }
        output->array[i] += bias->array[i];
    }
    activation(output->array, output->numel);
}

// Activation functions
void k2c_relu(float * x, const size_t size) {
    for (size_t i = 0; i < size; ++i) {
        if (x[i] < 0) x[i] = 0;
    }
}

void k2c_linear(float * x, const size_t size) {
    // Linear activation does nothing
}

// Neural network model
void poly_1024(k2c_tensor* input, k2c_tensor* output) {
    static float kernel_data[1024] = { /* Kernel values from the original */ };
    static float bias_data[1024] = { /* Bias values from the original */ };
    k2c_tensor kernel = {kernel_data, 1, sizeof(kernel_data) / sizeof(float)};
    k2c_tensor bias = {bias_data, 1, sizeof(bias_data) / sizeof(float)};

    // Simulated layer process
    k2c_tensor dense_out;
    float dense_out_data[1024];
    dense_out.array = dense_out_data;
    dense_out.numel = 1024;
    
    k2c_dense(&dense_out, input, &kernel, &bias, k2c_relu, NULL);

    // Final layer processing
    static float output_kernel_data[1024] = { /* Final layer kernel values */ };
    static float output_bias_data[1] = { /* Final layer bias value */ };
    k2c_tensor output_kernel = {output_kernel_data, 1, sizeof(output_kernel_data) / sizeof(float)};
    k2c_tensor output_bias = {output_bias_data, 1, sizeof(output_bias_data) / sizeof(float)};
    
    k2c_dense(output, &dense_out, &output_kernel, &output_bias, k2c_linear, NULL);
}

int main() {
    float input_array[1] = {0.0f};
    float output_array[1] = {0.0f};
    k2c_tensor input_tensor = {input_array, 1, 1, {1, 1, 1, 1, 1}};
    k2c_tensor output_tensor = {output_array, 1, 1, {1, 1, 1, 1, 1}};

    // Fixed deterministic input for verification
    float x = 2.95f;
    input_array[0] = x;
    poly_1024(&input_tensor, &output_tensor);

    // Compare network output with affine approximation
    float y = 2.8873749999999974f * (x - 2.9f) - 0.16373749999999976f;
    float diff = fabsf(y - output_array[0]);

    // Assertion for verification
    assert(diff <= 0.25000252395170093562268835409893f);

    printf("Verification successful\n");
    return 0;
}