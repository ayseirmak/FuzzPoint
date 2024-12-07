#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <keras2c/k2c_include.h>
#include <poly_approx/poly_16_16_16_16.h>

// Function declaration for poly_16_16_16_16
void poly_16_16_16_16(k2c_tensor* input_tensor, k2c_tensor* output_tensor);

int main() {
    // Neural network input and output
    float input_array[1] = {-1.53f};  // Fixed deterministic input value
    float output_array[1] = {0.0f};
    
    k2c_tensor input_tensor = {&input_array[0], 1, 1, {1, 1, 1, 1, 1}};
    k2c_tensor output_tensor = {&output_array[0], 1, 1, {1, 1, 1, 1, 1}};
    
    // Call the neural network function
    poly_16_16_16_16(&input_tensor, &output_tensor);
    
    // Compare the network output with an affine approximation of the ground truth
    float y = -0.25400099999999926f * (input_array[0] + 1.58f) - 1.18722038f;
    float diff = fabsf(y - output_array[0]);
    
    // Use assert to verify if the difference is within the expected threshold
    assert(diff <= 0.02831357375247427150544494547456f);
    
    printf("Verification successful! Difference: %f\n", diff);
    
    return 0;
}

/* Add the body of the poly_16_16_16_16 function here if not included externally. */