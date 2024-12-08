#include <stdio.h>
#include <math.h>
#include <stdint.h>
#include <assert.h>

// Necessary data and function declarations

void entry(const float tensor_input[1][8], float tensor_output[1][4]);

int main()
{
    float tensor_input[1][8];
    float tensor_output[1][4];

    // Provide deterministic inputs
    tensor_input[0][0] = -0.9f;
    tensor_input[0][1] = 0.05f;
    tensor_input[0][2] = 0.95f;
    tensor_input[0][3] = -0.3f;
    tensor_input[0][4] = -0.4f;
    tensor_input[0][5] = 0.0f;
    tensor_input[0][6] = 1.0f;
    tensor_input[0][7] = 1.0f;

    // Pass the input through the neural network
    entry(tensor_input, tensor_output);

    // Assert to check the condition
    assert(!(tensor_output[0][2] <= tensor_output[0][3]));

    // Print output for debugging
    printf("Output tensor values:\n");
    for (int i = 0; i < 4; i++) {
        printf("tensor_output[0][%d]: %f\n", i, tensor_output[0][i]);
    }

    return 0;
}

// Implementation of entry and related functions follows here