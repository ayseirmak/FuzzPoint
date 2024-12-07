#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "keras2c/k2c_include.h" // Ensure this is the correct path to your headers
#include "hopfield_nets/tanh/w32/hop_tanh_w32_r1.h" // Ensure this is the correct path

int main() {
    // Initialize the input and output arrays with deterministic values
    float input_array[32] = {0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f,
                             0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
                             1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
                             1.0f, 1.0f};

    float output_array[32] = {0.0f};
   
    // Initialize tensor structures
    k2c_tensor input_tensor = {input_array, 2, 32, {1, 32, 1, 1, 1}};
    k2c_tensor output_tensor = {output_array, 2, 32, {1, 32, 1, 1, 1}};

    // Process the input through the network
    hop_tanh_w32_r1(&input_tensor, &output_tensor);

    // Assert that the output array's first value is zero or greater
    assert(output_array[0] >= 0.0f);

    printf("Output validation passed. Output[0]: %f\n", output_array[0]);

    return 0;
}