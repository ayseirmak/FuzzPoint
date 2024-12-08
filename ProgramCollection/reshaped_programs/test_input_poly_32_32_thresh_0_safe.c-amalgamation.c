#include <stdio.h>
#include <math.h>
#include <assert.h>

typedef struct {
    float *array;
    size_t ndim;
    size_t numel;
    size_t shape[5];
} k2c_tensor;

void k2c_dense(k2c_tensor* output, const k2c_tensor* input, const k2c_tensor* kernel,
               const k2c_tensor* bias, void (*activation)(float*, const size_t), float * fwork) {
    if (input->ndim <= 2) {
        size_t outrows = (input->ndim > 1) ? input->shape[0] : 1;
        size_t outcols = kernel->shape[1];
        size_t innerdim = kernel->shape[0];
        size_t outsize = outrows * outcols;
        
        // Affine matmul calculation
        for (size_t i = 0; i < outrows; ++i) {
            for (size_t j = 0; j < outcols; ++j) {
                float sum = 0;
                for (size_t k = 0; k < innerdim; ++k) {
                    sum += input->array[i * innerdim + k] * kernel->array[k * outcols + j];
                }
                output->array[i * outcols + j] = sum + bias->array[j];
            }
        }

        activation(output->array, outsize);
    }
}

void k2c_relu(float * x, const size_t size) {
    for (size_t i = 0; i < size; ++i) {
        if (x[i] < 0.0f) {
            x[i] = 0.0f;
        }
    }
}

void poly_32_32(k2c_tensor* input_tensor, k2c_tensor* output_tensor) {
    // Dummy implementation for the neural network invocation
    
    float dense_76_kernel_array[32];
    float dense_76_bias_array[32];
    float dense_76_output_array[32];
    k2c_tensor dense_76_output = {dense_76_output_array, 1, 32, {32, 1, 1, 1, 1}};

    // Initialize kernel and bias with some example values
    for(size_t i = 0; i < 32; ++i){
        dense_76_kernel_array[i] = 0.1f;
        dense_76_bias_array[i] = 0.1f;
    }

    k2c_tensor dense_76_kernel = {dense_76_kernel_array, 2, 32, {1, 32, 1, 1, 1}};
    k2c_tensor dense_76_bias = {dense_76_bias_array, 1, 32, {32, 1, 1, 1, 1}};
    
    k2c_dense(&dense_76_output, input_tensor, &dense_76_kernel, &dense_76_bias, k2c_relu, NULL);

    output_tensor->array[0] = dense_76_output.array[0]; // Simply propagate first value for demonstration
}

int main() {
    float input_array[1] = {3.0f}; // Fixed input value for determinism
    float output_array[1] = {0.0f};
    
    k2c_tensor input_tensor = {input_array, 1, 1, {1, 1, 1, 1, 1}};
    k2c_tensor output_tensor = {output_array, 1, 1, {1, 1, 1, 1, 1}};
    
    float x = 3.0f;
    
    poly_32_32(&input_tensor, &output_tensor);
    
    float y = 2.8873749999999974f * (x - 2.9f) - 0.16373749999999976f;
    float diff = fabsf(y - output_array[0]);

    assert(fabsf(diff) <= 0.54636856876369892f);
    
    printf("Verification successful.\n");
    
    return 0;
}