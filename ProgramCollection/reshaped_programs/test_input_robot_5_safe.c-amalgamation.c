#include <stdio.h>
#include <math.h>
#include <assert.h>

// Prototype declaration
void entry(const float tensor_input[1][5], float tensor_output[1][5]);

int main() {
    float tensor_input[1][5];
    float tensor_output[1][5];

    // Fixed and deterministic inputs since randomness and I/O are not allowed
    tensor_input[0][0] = -1.5f;
    tensor_input[0][1] = -1.5f;
    tensor_input[0][2] = 0.78539816339f; // π/4
    tensor_input[0][3] = 1.25f;
    tensor_input[0][4] = 1.25f;

    // Validating input assumptions with assertions
    assert(tensor_input[0][0] >= -1.8f && tensor_input[0][0] <= -1.2f);
    assert(tensor_input[0][1] >= -1.8f && tensor_input[0][1] <= -1.2f);
    assert(tensor_input[0][2] >= 0.0f && tensor_input[0][2] <= 1.5707963267948966f);
    assert(tensor_input[0][3] >= 1.0f && tensor_input[0][3] <= 1.5f);
    assert(tensor_input[0][4] >= 0.0f && tensor_input[0][4] <= 2.5f);

    // Run the entry function
    entry(tensor_input, tensor_output);

    // Validate output with assertions
    assert(!((tensor_output[0][1] <= 0.03281770965307063) && (tensor_output[0][1] >= -0.03281770965307063) && 
             (tensor_output[0][2] <= 0.03281770965307063) && (tensor_output[0][2] >= -0.03281770965307063) && 
             (tensor_output[0][0] >= 0.17121804550093517)));

    return 0;
}

void entry(const float tensor_input[1][5], float tensor_output[1][5]) {
    // Define your entry function here or call necessary operations
    // Example:
    // node_Gemm_0(...);
    // node_Relu_1(...);
    // ...
}