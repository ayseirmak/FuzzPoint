#include <stdio.h>
#include <math.h>
#include <assert.h>

// Function Prototypes
void entry(const float tensor_input[1][5], float tensor_output[1][5]);

// Entry Point
int main() {
    // Define input and expected output tensors
    float tensor_input[1][5] = {{-1.5f, -1.5f, 0.785398163f, 1.25f, 1.25f}};
    float tensor_output[1][5] = {0};

    // Call entry function
    entry(tensor_input, tensor_output);

    // Manually derived assertions based on expected behavior
    // These assertions check some expected properties or values of the output
    assert(!(tensor_output[0][1] <= 0.22510209287602703 && 
             tensor_output[0][1] >= -0.22510209287602703 && 
             tensor_output[0][2] <= 0.22510209287602703 && 
             tensor_output[0][2] >= -0.22510209287602703 && 
             tensor_output[0][0] >= 0.1362501380036763));

    // Print the output tensor for confirmation
    for (int i = 0; i < 1; i++) {
        for (int j = 0; j < 5; j++) {
            printf("tensor_output[%d][%d] = %f\n", i, j, tensor_output[i][j]);
        }
    }

    return 0;
}