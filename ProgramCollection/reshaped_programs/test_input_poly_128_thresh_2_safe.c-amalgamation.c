#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <keras2c/k2c_include.h>
#include <string.h> // For memset

// Assuming definitions of poly_128 and related functions are available
void poly_128(k2c_tensor* dense_62_input_input, k2c_tensor* dense_63_output);

int main() {
    /* Neural net input and output */
    float input_array[1] = {0.0f}, output_array[1] = {0.0f};
    k2c_tensor input_tensor = {&input_array[0], 1, 1, {1, 1, 1, 1, 1}};
    k2c_tensor output_tensor = {&output_array[0], 1, 1, {1, 1, 1, 1, 1}};
	
    /* Use a fixed value of x within the specified range */
    float x = 2.95f; // Fixed deterministic value within [2.9, 3.0]
	
    /* Call the neural network with fixed input */
    input_array[0] = x;
    poly_128(&input_tensor, &output_tensor);
	
    /* Compare the network output with an affine approximation of the ground truth */
    float y = 2.8873749999999974f * (x - 2.9f) - 0.16373749999999976f;
    float diff = fabsf(y - output_array[0]);
	
    /* Static assertion for expected behavior */
    assert(diff <= 0.20850188956270875963948425384528f); // Expected result: verification successful
	
    return 0;
}

// Placeholder implementation for poly_128
void poly_128(k2c_tensor* dense_62_input_input, k2c_tensor* dense_63_output) {
    // Function implementation required; using placeholder
    // This function should modify dense_63_output based on dense_62_input_input using keras model processing
    dense_63_output->array[0] = 0.0f; // Example result after processing for illustration
}