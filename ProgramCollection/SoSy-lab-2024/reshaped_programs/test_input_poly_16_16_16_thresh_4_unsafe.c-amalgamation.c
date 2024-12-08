#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <keras2c/k2c_include.h>
#include <poly_approx/poly_16_16_16.h>

// Defining assert equivalent based on __VERIFIER_assert
#define ASSERT(expr) assert((expr))

// Declaration of the poly_16_16_16 function is assumed to exist similarly to its original context.

int main() {
    /* Neural net input and output */
    float input_array[1] = {0.0f}, output_array[1] = {0.0f};
    k2c_tensor input_tensor = {&input_array[0], 1, 1, {1, 1, 1, 1, 1}};
    k2c_tensor output_tensor = {&output_array[0], 1, 1, {1, 1, 1, 1, 1}};

    /* Deterministic input around the location of maximum error (x=-2) */
    float x = -1.95f;  // Fixed value within [-2.0, -1.9]

    /* Call the neural network with non-deterministic input */
    input_array[0] = x;
    poly_16_16_16(&input_tensor, &output_tensor);

    /* Compare the network output with an affine approximation of the ground truth */
    float y = -2.637375000000004f * (x + 2.0f) - 0.5f;
    float diff = fabsf(y - output_array[0]);

    /* Try decreasing thresholds by a factor of two */
    ASSERT(diff <= 0.02090538571161029786370315529543f); /* Expected result: assertion may fail */

    return 0;
}