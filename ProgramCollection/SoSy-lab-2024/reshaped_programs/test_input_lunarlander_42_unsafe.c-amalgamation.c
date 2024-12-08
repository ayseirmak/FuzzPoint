#include <assert.h>
#include <stdio.h>
#include <math.h>

// Define the functions that were originally verifier functions
void assume(int cond) {
    assert(cond);
}

void assert_safe(int cond) {
    if (!cond) {
        printf("Assertion failed!\n");
        assert(0);
    }
}

// Prototypes of internal implementation functions
void entry(const float tensor_input[1][8], float tensor_output[1][4]);

// Main function to test functionality
int main() {
    float tensor_input[1][8];
    float tensor_output[1][4];

    // Initialize inputs with fixed deterministic values
    tensor_input[0][0] = -0.9f;
    tensor_input[0][1] = 0.05f;
    tensor_input[0][2] = 0.06f;
    tensor_input[0][3] = -0.02f;
    tensor_input[0][4] = -0.4f;
    tensor_input[0][5] = 0.0f;
    tensor_input[0][6] = 1.0f;
    tensor_input[0][7] = 1.0f;

    // Assumed ranges check for the given initialized values
    assume(tensor_input[0][0] >= -0.9360955824029287f && tensor_input[0][0] <= -0.8709910175970714f);
    assume(tensor_input[0][1] >= 0.031764667597071375f && tensor_input[0][1] <= 0.09686923240292862f);
    assume(tensor_input[0][2] >= 0.029440403597071375f && tensor_input[0][2] <= 0.09454496840292861f);
    assume(tensor_input[0][3] >= -0.05046328840292862f && tensor_input[0][3] <= 0.014641276402928623f);
    assume(tensor_input[0][4] >= -0.4414273024029286f && tensor_input[0][4] <= -0.37632273759707136f);
    assume(tensor_input[0][5] >= -0.03255227446791762f && tensor_input[0][5] <= 0.032552290337939625f);
    assume(tensor_input[0][6] >= 0.9674477175970714f && tensor_input[0][6] <= 1.0325522824029285f);
    assume(tensor_input[0][7] >= 0.9674477175970714f && tensor_input[0][7] <= 1.0325522824029285f);

    // Run the entry function
    entry(tensor_input, tensor_output);

    // Assert condition check
    assert_safe(!(tensor_output[0][2] <= tensor_output[0][3]));

    return 0;
}

// [The content of the entry function and the other necessary functions and data follow unchanged]