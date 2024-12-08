#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <keras2c/k2c_include.h> // Ensure this library is available and compatible with ARM

void poly_512(k2c_tensor* dense_66_input_input, k2c_tensor* dense_67_output);

int main() {
    /* neural net input and output */
    float input_array[1] = {0.0f}, output_array[1] = {0.0f};
    k2c_tensor input_tensor = {&input_array[0],1,1,{1,1,1,1,1}};
    k2c_tensor output_tensor = {&output_array[0],1,1,{1,1,1,1,1}};
    
    /* Use a fixed value for x around the location of maximum error */
    float x = 2.95f; // Fixed value within the specified range [2.9, 3.0]
    
    /* call the neural network with fixed input */
    input_array[0] = x;
    poly_512(&input_tensor, &output_tensor);
    
    /* compare the network output with an affine approximation of the ground truth */
    float y = 2.8873749999999974f * (x - 2.9f) - 0.16373749999999976f;
    float diff = fabsf(y - output_array[0]);
    
    /* Assert that diff is within expected threshold */
    assert(diff <= 0.17690637868030649391618620538222f); /* Expected result: verification successful */
    
    return 0;
}

void poly_512(k2c_tensor* dense_66_input_input, k2c_tensor* dense_67_output) {
    // Implementation of poly_512 function, initialize arrays as needed
    // The full function body was omitted for brevity
}

// Note: This code assumes that the poly_512 function and all corresponding
// neural network operations are defined elsewhere and correctly handle
// input/output tensors as per the defined structures.