#include <stdio.h>
#include <math.h>
#include <keras2c/k2c_include.h>
#include <hopfield_nets/softsign/w8/hop_softsign_w8_r4.h>
#include <assert.h>

// This declaration assumes `hop_softsign_w8_r4` function is defined in one of the included headers
// If not, you'll need to provide the function signature from the corresponding header file.

int main(void) {
    // Initialize input and output arrays with zeros
    float input_array[32] = {0.0f};
    float output_array[32] = {0.0f};

    // Create k2c_tensor structures
    k2c_tensor input_tensor = {&input_array[0], 2, 32, {4, 8, 1, 1, 1}};
    k2c_tensor output_tensor = {&output_array[0], 2, 32, {4, 8, 1, 1, 1}};

    // Assign deterministic, fixed values to input_array
    input_array[0] = 0.5f; // Chose value within -1.0f to 1.0f
    input_array[1] = -0.5f; // Chose value within -1.0f to 1.0f
    input_array[2] = 0.25f; // Chose value within -1.0f to 1.0f
    input_array[3] = 1.0f;
    input_array[4] = 1.0f;
    input_array[5] = 1.0f;
    input_array[6] = 1.0f;
    input_array[7] = 1.0f;

    // Call function to perform operations on tensors
    hop_softsign_w8_r4(&input_tensor, &output_tensor);

    // Check the assertion, using standard assert function
    assert(output_array[30] >= 0.0f);

    return 0;
}