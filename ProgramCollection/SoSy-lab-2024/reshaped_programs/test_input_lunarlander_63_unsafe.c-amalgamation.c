#include <assert.h>
#include <stdio.h>
#include <float.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#define MAX(X,Y) ( X > Y ? X : Y)
#define MIN(X,Y) ( X < Y ? X : Y)
#define CLIP(X,L) ( MAX(MIN(X,L), -L) )

// Entry function prototype
void entry(const float tensor_input[1][8], float tensor_output[1][4]);

// Main execution
int main() {
    // Deterministic input values, replacing nondet functions
    float tensor_input[1][8] = {
        {-0.926, 0.080, 0.070, -0.020, -0.409, 0.000, 1.000, 1.000}
    };
    float tensor_output[1][4];

    // Without any nondeterministic generation, we use fixed values
    assert(tensor_input[0][0] >= -0.9607981250000003f && tensor_input[0][0] <= -0.8931549949999996f);
    assert(tensor_input[0][1] >= 0.04572882499999967f && tensor_input[0][1] <= 0.11337195500000033f);
    assert(tensor_input[0][2] >= 0.035068694999999664f && tensor_input[0][2] <= 0.10271182500000033f);
    assert(tensor_input[0][3] >= -0.053725426000000326f && tensor_input[0][3] <= 0.013917704000000333f);
    assert(tensor_input[0][4] >= -0.44269673500000034f && tensor_input[0][4] <= -0.3750536049999997f);
    assert(tensor_input[0][5] >= -0.03382155939838693f && tensor_input[0][5] <= 0.03382157060161373f);
    assert(tensor_input[0][6] >= 0.9661784349999997f && tensor_input[0][6] <= 1.0338215650000002f);
    assert(tensor_input[0][7] >= 0.9661784349999997f && tensor_input[0][7] <= 1.0338215650000002f);

    entry(tensor_input, tensor_output);
    assert(!(tensor_output[0][2] <= tensor_output[0][3]));

    printf("Assertions passed successfully.\n");

    return 0;
}

// Predefined weights and biases for functions
static const float tensor_q_net_0_weight[64][8] = {...};  // weights from original code
static const float tensor_q_net_0_bias[64] = {...};  // biases from original code
static const float tensor_q_net_2_weight[64][64] = {...};  // weights from original code
static const float tensor_q_net_2_bias[64] = {...};  // biases from original code
static const float tensor_q_net_4_weight[4][64] = {...};  // weights from original code
static const float tensor_q_net_4_bias[4] = {...};  // biases from original code

// Nodes and layers functions
union tensor_union_0 {
    float tensor_7[1][8];
    float tensor_9[1][64];
    float tensor_11[1][64];
};
static union tensor_union_0 tu0;

union tensor_union_1 {
    float tensor_8[1][64];
    float tensor_10[1][64];
};
static union tensor_union_1 tu1;

// Perform operations as per model predictions
void entry(const float tensor_input[1][8], float tensor_output[1][4]) {
    node_Flatten_0(tensor_input, tu0.tensor_7);
    node_Gemm_1(tu0.tensor_7, tensor_q_net_0_weight, tensor_q_net_0_bias, tu1.tensor_8);
    node_Relu_2(tu1.tensor_8, tu0.tensor_9);
    node_Gemm_3(tu0.tensor_9, tensor_q_net_2_weight, tensor_q_net_2_bias, tu1.tensor_10);
    node_Relu_4(tu1.tensor_10, tu0.tensor_11);
    node_Gemm_5(tu0.tensor_11, tensor_q_net_4_weight, tensor_q_net_4_bias, tensor_output);
}

// Function definitions for operations
// Flatten operation, Gemm operations, Relu activation, etc...

// Implement node functions and other necessary functions from original code