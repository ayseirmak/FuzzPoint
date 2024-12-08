#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <keras2c/k2c_include.h>
#include <keras2c/k2c_tensor_include.h>
#include <poly_approx/poly_32_32_32_32.h>

/* Function prototype for the custom neural network call */
void poly_32_32_32_32(k2c_tensor* dense_157_input_input, k2c_tensor* dense_161_output);

int main() {
    /* Initialize neural net input and output with fixed values */
    float input_array[1] = {3.0f}, output_array[1] = {0.0f};
    k2c_tensor input_tensor = {&input_array[0], 1, 1, {1, 1, 1, 1, 1}};
    k2c_tensor output_tensor = {&output_array[0], 1, 1, {1, 1, 1, 1, 1}};
    
    /* Fixed input value */
    float x = 3.0f; // Deterministic input for testing within range [2.9, 3.0]
    
    /* Call the neural network with this deterministic input */
    input_array[0] = x;
    poly_32_32_32_32(&input_tensor, &output_tensor);
    
    /* Compare the network output with an affine approximation of the ground truth */
    float y = 2.8873749999999974f * (x - 2.9f) - 0.16373749999999976f;
    float diff = fabsf(y - output_array[0]);
    
    /* Check assertion using fixed known threshold */
    assert(diff <= 0.07937737480867454336575484918528f);
    
    /* If assertion fails, report an error */
    if (diff > 0.07937737480867454336575484918528f) {
        printf("Verification failed: |%f - %f| = %f\n", y, output_array[0], diff);
    } else {
        printf("Verification successful\n");
    }
    
    return 0;
}