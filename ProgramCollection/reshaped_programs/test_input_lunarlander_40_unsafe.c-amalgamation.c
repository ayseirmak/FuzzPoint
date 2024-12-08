#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>
#include <stdint.h>

// Based on converted functions from the provided ONNX file
void entry(const float tensor_input[1][8], float tensor_output[1][4]);

void run_model() {
    // Fixed deterministic input values based on assumption ranges
    float tensor_input[1][8] = {
        {-0.9f, 0.0f, 0.5f, -0.1f, -0.4f, 0.0f, 1.0f, 1.0f}
    };
    float tensor_output[1][4] = {0};

    // Call the model entry function
    entry(tensor_input, tensor_output);

    // Assert to mimic the assertion in the original code
    assert(!(tensor_output[0][2] <= tensor_output[0][3]));

    // Print output for verification
    printf("Tensor output: [%.6f, %.6f, %.6f, %.6f]\n", 
            tensor_output[0][0], tensor_output[0][1], 
            tensor_output[0][2], tensor_output[0][3]);
}

int main() {
    run_model();
    return 0;
}