#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <keras2c/k2c_include.h>

/* Function Prototypes */
void k2c_dense(k2c_tensor*, const k2c_tensor*, const k2c_tensor*, const k2c_tensor*, void (*)(float*, const size_t), float*);
void k2c_relu_func(float*, const size_t);
void poly_64_64(k2c_tensor*, k2c_tensor*);

/* Activation function */
void k2c_relu_func(float * x, const size_t size) {
    for (size_t i=0; i < size; ++i) {
        if (x[i] <= 0.0f) {
            x[i] = 0.0f;
        }
    }
}

/* Dense layer function */
void k2c_dense(k2c_tensor* output, const k2c_tensor* input, const k2c_tensor* kernel,
               const k2c_tensor* bias, void (*activation)(float*, const size_t), float * fwork) {
    size_t outsize = kernel->shape[1];
    for (size_t i = 0; i < outsize; i++) {
        output->array[i] = bias->array[i];
    }
    
    for (size_t i = 0; i < outsize; i++) {
        for (size_t j = 0; j < kernel->shape[0]; j++) {
            output->array[i] += input->array[j] * kernel->array[j * outsize + i];
        }
    }
    activation(output->array, outsize);
}

/* Neural network function */
void poly_64_64(k2c_tensor* input_tensor, k2c_tensor* output_tensor) {
    // Assume this function computes the output using the given neural network weights
}

/* Main function */
int main() {
    /* Define fixed input value */
    float x = -1.95f;

    /* Neural net input and output */
    float input_array[1] = {0.0f}, output_array[1] = {0.0f};
    k2c_tensor input_tensor = {&input_array[0], 1, 1, {1, 1, 1, 1, 1}};
    k2c_tensor output_tensor = {&output_array[0], 1, 1, {1, 1, 1, 1, 1}};

    /* Call the neural network with the deterministic input */
    input_array[0] = x;
    poly_64_64(&input_tensor, &output_tensor);

    /* Compare the network output with an affine approximation of the ground truth */
    float y = -2.637375000000004f * (x + 2.0f) - 0.5f;
    float diff = fabsf(y - output_array[0]);

    /* Assertion to verify output is as expected */
    assert(diff <= 0.01341553037305318391563068959671f);

    printf("Program completed. Difference: %f\n", diff);

    return 0;
}