#include <math.h>
#include <stdio.h>
#include <assert.h>
#include <keras2c/k2c_include.h>
#include <poly_approx/poly_8_8_8.h>

/* Function prototypes */
void poly_8_8_8(k2c_tensor* dense_101_input_input, k2c_tensor* dense_104_output);

int main() {
    /* neural net input and output */
    float input_array[1] = {0.0f};
    float output_array[1] = {0.0f};
    k2c_tensor input_tensor = {&input_array[0], 1, 1, {1, 1, 1, 1, 1}};
    k2c_tensor output_tensor = {&output_array[0], 1, 1, {1, 1, 1, 1, 1}};

    /* Fixed input value in the range of [2.9, 3.0] */
    float x = 2.95f;

    /* Call the neural network with fixed input */
    input_array[0] = x;
    poly_8_8_8(&input_tensor, &output_tensor);

    /* Compare the network output with an affine approximation of the ground truth */
    float y = 2.8873749999999974f * (x - 2.9f) - 0.16373749999999976f;
    float diff = fabsf(y - output_array[0]);

    /* Assertion check */
    assert(diff <= 0.07797400826432484995597746941359f);

    return 0;
}

void poly_8_8_8(k2c_tensor* dense_101_input_input, k2c_tensor* dense_104_output) {
    float dense_101_output_array[8] = {0}; 
    k2c_tensor dense_101_output = {&dense_101_output_array[0], 1, 8, {8, 1, 1, 1, 1}};
    float dense_101_kernel_array[8] = {
        -4.25288856e-01f, +6.03239119e-01f, -7.15621054e-01f, -6.22532547e-01f,
        -1.24681555e-01f, -5.77558637e-01f, +5.45904338e-01f, +4.63141859e-01f
    };
    k2c_tensor dense_101_kernel = {&dense_101_kernel_array[0], 2, 8, {1, 8, 1, 1, 1}};
    float dense_101_bias_array[8] = {
        +6.74528033e-02f, -1.26489744e-01f, -5.07017374e-01f, -1.05312444e-01f,
        +8.43151569e-01f, +9.21806023e-02f, +1.20195806e-01f, -2.02748120e-01f
    };
    k2c_tensor dense_101_bias = {&dense_101_bias_array[0], 1, 8, {8, 1, 1, 1, 1}};
    float dense_101_fwork[9] = {0};

    /* Subsequent layers functions and declarations omitted for brevity */
    /* This area includes initialization of subsequent layers, similar to the above */
    /* And calls to k2c_dense for different layers. */

    /* Last layer dense 104 calculation */
    float dense_104_kernel_array[8] = {
        -3.42816889e-01f, +6.74038351e-01f, +4.54611957e-01f, -1.52814460e+00f,
        -4.31146562e-01f, -6.46010101e-01f, +8.45992446e-01f, -4.15614337e-01f
    };
    k2c_tensor dense_104_kernel = {&dense_104_kernel_array[0], 2, 8, {8, 1, 1, 1, 1}};
    float dense_104_bias_array[1] = {+9.88248270e-03f};
    k2c_tensor dense_104_bias = {&dense_104_bias_array[0], 1, 1, {1, 1, 1, 1, 1}};
    float dense_104_fwork[16] = {0};

    k2c_dense(dense_104_output, &dense_103_output, &dense_104_kernel,
        &dense_104_bias, k2c_linear, dense_104_fwork);
}