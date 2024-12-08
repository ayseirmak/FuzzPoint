#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <keras2c/k2c_include.h>
#include <hopfield_nets/softsign/w4/hop_softsign_w4_r4.h>

int main() {
    // Initialize input and output arrays
    float input_array[16] = {0.0f}, output_array[16] = {0.0f};

    // Define input and output tensors
    k2c_tensor input_tensor = {&input_array[0], 2, 16, {4, 4, 1, 1, 1}};
    k2c_tensor output_tensor = {&output_array[0], 2, 16, {4, 4, 1, 1, 1}};

    // Assign fixed deterministic inputs
    input_array[0] = 0.5f; // Fixed value between -1.0f and 1.0f as assumed
    input_array[1] = 1.0f;
    input_array[2] = 1.0f;
    input_array[3] = 1.0f;

    // Execute the hopfield network function
    hop_softsign_w4_r4(&input_tensor, &output_tensor);

    // Assert the output condition
    assert(isgreaterequal(output_array[14], 0.0f));

    // Inform the result
    printf("Verification successful.\n");

    return 0;
}