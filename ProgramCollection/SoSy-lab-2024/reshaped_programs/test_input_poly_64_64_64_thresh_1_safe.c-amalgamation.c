#include <math.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <keras2c/k2c_include.h>
#include <poly_approx/poly_64_64_64.h>

/**
 * This code executes a neural network using fixed inputs and checks the output
 * against an affine approximation of the expected result.
 */

int main()
{
    // Neural net input and output
    float input_array[1] = {3.0f}, output_array[1] = {0.0f}; // Fixed input of x = 3.0
    k2c_tensor input_tensor = {&input_array[0], 1, 1, {1,1,1,1,1}};
    k2c_tensor output_tensor = {&output_array[0], 1, 1, {1,1,1,1,1}};
    
    // Call the neural network with fixed input
    poly_64_64_64(&input_tensor, &output_tensor);
    
    // Compare the network output with an affine approximation of the ground truth
    float x = input_array[0];
    float y = 2.8873749999999974f * (x - 2.9f) - 0.16373749999999976f;
    float diff = fabsf(y - output_array[0]);
    
    // Verify the result is within the threshold
    assert(islessequal(diff, 0.03385027641770743354530550889739f)); 

    printf("Test passed!\n");
    return 0;
}