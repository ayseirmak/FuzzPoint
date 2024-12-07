#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <keras2c/k2c_include.h>
#include <poly_approx/poly_64_64.h>

// Function declaration from poly_64_64.h
void poly_64_64(k2c_tensor* input, k2c_tensor* output);

// Main function
int main()
{
    /* neural net input and output */
    float input_array[1] = {0.0f}, output_array[1] = {0.0f};
    k2c_tensor input_tensor = {&input_array[0], 1, 1, {1, 1, 1, 1, 1}};
    k2c_tensor output_tensor = {&output_array[0], 1, 1, {1, 1, 1, 1, 1}};
    
    /* Static input value */
    float x = -2.0f; // Deterministic value, within the specified range

    /* Call the neural network with deterministic input */
    input_array[0] = x;
    poly_64_64(&input_tensor, &output_tensor);

    /* Compare the network output with an affine approximation of the ground truth */
    float y = -2.637375f * (x + 2.0f) - 0.5f;
    float diff = fabsf(y - output_array[0]);

    /* Threshold validation using assert */
    assert(diff <= 0.10732424298442547132504551677366f); // Expected result: verification successful

    printf("Test passed. Difference: %f\n", diff);

    return 0;
}

// Function implementations (place other includes and function implementations here)
// ...