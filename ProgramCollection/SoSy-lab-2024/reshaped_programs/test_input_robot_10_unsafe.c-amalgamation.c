#include <stdio.h>
#include <assert.h>
#include <math.h>

// Function declaration
void entry(const float tensor_input[1][5], float tensor_output[1][5]);

// Main function
int main() {
    // Initialize input tensors with fixed deterministic values
    float tensor_input[1][5] = {{-1.5f, -1.5f, 0.7853981633974483f, 1.25f, 1.25f}};
    float tensor_output[1][5];

    // Call the entry function
    entry(tensor_input, tensor_output);

    // Assert the conditions as per your original logic
    assert(!((tensor_output[0][1] <= 0.16943059486986362) && 
             (tensor_output[0][1] >= -0.16943059486986362) && 
             (tensor_output[0][2] <= 0.16943059486986362) && 
             (tensor_output[0][2] >= -0.16943059486986362) && 
             (tensor_output[0][0] >= 0.16744696798540254)));

    // Print output
    printf("Output: [%.6f, %.6f, %.6f, %.6f, %.6f]\n", 
           tensor_output[0][0], tensor_output[0][1], tensor_output[0][2], 
           tensor_output[0][3], tensor_output[0][4]);

    return 0;
}