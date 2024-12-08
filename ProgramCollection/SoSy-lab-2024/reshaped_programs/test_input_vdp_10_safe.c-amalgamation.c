#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

// Predefined arrays and biases, as given in your code
// Static constants defining weights, biases, etc., with some removed for brevity

// Functions for each node (Gemm, Relu) and the composed entry function
// Static functions are defined here...

// Replace this section with your full program definitions as needed
// For example, node_Gemm_0, node_Relu_1, node_Gemm_2, node_Relu_3, node_Gemm_4, and entry.

// Here's the main function with deterministic inputs
int main() {
    float tensor_input[1][3];
    float tensor_output[1][3];

    // Fixed deterministic input values
    tensor_input[0][0] = 1.5f;
    tensor_input[0][1] = -1.2f;
    tensor_input[0][2] = 3.3f;

    // Ensure the fixed input fits within the expected ranges
    assert(tensor_input[0][0] >= -2.5f && tensor_input[0][0] <= 2.5f);
    assert(tensor_input[0][1] >= -2.5f && tensor_input[0][1] <= 2.5f);
    assert(tensor_input[0][2] >= 0.0f && tensor_input[0][2] <= 5.0f);

    // Perform the 'entry' function computation
    entry(tensor_input, tensor_output);

    // Assert the output according to condition
    assert(!((tensor_output[0][1] <= 0.6611040870813922) &&
             (tensor_output[0][1] >= -0.6611040870813922) &&
             (tensor_output[0][2] <= 0.6611040870813922) &&
             (tensor_output[0][2] >= -0.6611040870813922) &&
             (tensor_output[0][0] >= 0.28075401898993385)));

    return 0;
}