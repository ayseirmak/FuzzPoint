#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <keras2c/k2c_include.h>

// Replace the nondeterministic function with a defined fixed value
#define FIXED_INPUT -1.95f

void poly_16_16(k2c_tensor* input_tensor, k2c_tensor* output_tensor) {
    // Assuming poly_16_16 is implemented correctly in keras2c/k2c_include.h or provided elsewhere
}

int main() {
    // Neural net input and output
    float input_array[1] = {0.0f}, output_array[1] = {0.0f};
    k2c_tensor input_tensor = {&input_array[0], 1, 1, {1, 1, 1, 1, 1}};
    k2c_tensor output_tensor = {&output_array[0], 1, 1, {1, 1, 1, 1, 1}};
    
    // Fixed input
    float x = FIXED_INPUT;

    // Call the neural network with fixed input
    input_array[0] = x;
    poly_16_16(&input_tensor, &output_tensor);

    // Compare the network output with an affine approximation of the ground truth
    float y = -2.637375000000004f * (x + 2.0f) - 0.5f;
    float diff = fabsf(y - output_array[0]);
    
    // Replace custom verifier functions with standard assertions
    assert(diff <= 0.35153247941264260937568456786553f); 

    return 0;
}

// Important Note: Ensure to provide the definition of poly_16_16 function if it is custom.
// Include all necessary activation functions and auxiliary functions if not part of keras2c.