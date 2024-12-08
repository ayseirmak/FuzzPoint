#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

/* Dummy declarations for keras2c functions and data structures */
typedef struct {
    float *array;
    int ndim;
    int dim[5];
} k2c_tensor;

void poly_64_64_64(k2c_tensor *input, k2c_tensor *output) {
    // Emulating the same functionality as provided functions
    output->array[0] = 8.6012345; // Dummy output, replace with actual neural net call
}

/* Function for poly_64_64_64_initialization and termination can be added if needed */

int main() {
    /* Set deterministic neural network input */
    float input_array[1] = {3.0f};  // Set a fixed input value of x to 3
    float output_array[1] = {0.0f};

    k2c_tensor input_tensor = {&input_array[0], 1, {1}};
    k2c_tensor output_tensor = {&output_array[0], 1, {1}};

    /* Call the poly_64_64_64 function with the deterministic input */
    poly_64_64_64(&input_tensor, &output_tensor);

    /* Compare with expected result */
    float x = 3.0f;  // Fixed input value
    float expected_y = 2.8873749999999974f * (x - 2.9f) - 0.16373749999999976f;
    float diff = fabsf(expected_y - output_array[0]);

    /* Assert that the output matches within a specific error threshold */
    assert(diff <= 0.06770055283541486709061101779478f);
    
    printf("Verification successful: difference = %f\n", diff);

    return 0;
}