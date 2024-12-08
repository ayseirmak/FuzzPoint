#include <stdio.h>
#include <assert.h>
#include <math.h>

// Function declaration
void entry(const float tensor_input[1][8], float tensor_output[1][4]);

int main() {
    // Initialize the input tensor with fixed deterministic values
    const float tensor_input[1][8] = {
        {-0.558913f, 0.118752f, 0.023578f, -0.024104f, -0.009154f, -0.134464f, 0.0f, 1.0f}
    };
    float tensor_output[1][4];

    // Run the entry function
    entry(tensor_input, tensor_output);

    // Assert that tensor_output[0][2] > tensor_output[0][3]
    assert(!(tensor_output[0][2] <= tensor_output[0][3]));

    printf("Assertions passed.\n");
    return 0;
}

// Other supporting functions and constants go here
// ...

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

// Definition of weight and bias constants, functions node_Flatten_0, node_Gemm_1, etc. go here
// For example:

static inline void node_Flatten_0(const float tensor_input[1][8], float tensor_7[1][8]) {
    /* Flatten */
    float *input = (float*)tensor_input;
    float *output = (float*)tensor_7;
    for (uint32_t i = 0; i < 8; i++)
        output[i] = input[i];
}

// Additional functions node_Gemm_1, node_Relu_2, node_Gemm_3, node_Relu_4, node_Gemm_5, etc.
// with tensor calculations here...

void entry(const float tensor_input[1][8], float tensor_output[1][4]) {
    node_Flatten_0(tensor_input, tu0.tensor_7);
    node_Gemm_1(tu0.tensor_7, tensor_q_net_0_weight, tensor_q_net_0_bias, tu1.tensor_8);
    node_Relu_2(tu1.tensor_8, tu0.tensor_9);
    node_Gemm_3(tu0.tensor_9, tensor_q_net_2_weight, tensor_q_net_2_bias, tu1.tensor_10);
    node_Relu_4(tu1.tensor_10, tu0.tensor_11);
    node_Gemm_5(tu0.tensor_11, tensor_q_net_4_weight, tensor_q_net_4_bias, tensor_output);
}