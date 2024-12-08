#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <assert.h>

// Function prototypes
void entry(const float tensor_input[1][4], float tensor_output[1][2]);

int main() {
    float tensor_input[1][4];
    float tensor_output[1][2];

    // Initialize the tensor_input with fixed deterministic values
    tensor_input[0][0] = -0.26f;
    tensor_input[0][1] = -0.44f;
    tensor_input[0][2] = -0.05f;
    tensor_input[0][3] = 0.21f;

    // Here are the conditions originally assumed by __VERIFIER_assume
    // assert(tensor_input[0][0] >= -0.2673144981930642f && tensor_input[0][0] <= -0.2599194618069358f);
    // assert(tensor_input[0][1] >= -0.4450191581930642f && tensor_input[0][1] <= -0.43762412180693583f);
    // assert(tensor_input[0][2] >= -0.05413893619306421f && tensor_input[0][2] <= -0.046743899806935794f);
    // assert(tensor_input[0][3] >= 0.20545317180693579f && tensor_input[0][3] <= 0.21284820819306421f);

    entry(tensor_input, tensor_output);

    // Original assertion with __VERIFIER_assert
    assert(!(tensor_output[0][1] <= tensor_output[0][0]));

    printf("Tensor Output: [%f, %f]\n", tensor_output[0][0], tensor_output[0][1]);

    return 0;
}

// Include function definitions from the provided preconverted code (such as node_Flatten_0, node_Gemm_1, etc.)
// Ensure all variables are initialized before use within these functions.