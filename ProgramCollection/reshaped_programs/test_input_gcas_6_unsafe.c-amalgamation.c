#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <float.h>
#include <stdint.h>

// Constants for initial deterministic values
const float tensor_input_constants[14] = {0.0f, 0.0f, 0.0f, 0.0f, 
                                          0.0f, 0.0f, 0.0f, 0.0f, 
                                          0.0f, 0.0f, 0.0f, 0.0f, 
                                          0.0f, 0.0f};

// Declarations of the tensor weights and biases (unchanged, assuming they're included elsewhere in this code)
extern const float tensor_linear_list_0_weight[32][14];
extern const float tensor_linear_list_0_bias[32];
extern const float tensor_linear_list_1_weight[32][32];
extern const float tensor_linear_list_1_bias[32];
extern const float tensor_linear_list_2_weight[14][32];
extern const float tensor_linear_list_2_bias[14];

// Union types for intermediate calculations
union tensor_union_0 {
    float tensor_7[1][32];
    float tensor_9[1][32];
};
union tensor_union_1 {
    float tensor_8[1][32];
    float tensor_10[1][32];
};

// Function declarations
void entry(const float tensor_input[1][14], float tensor_output[1][14]);
static inline void node_Gemm_0(const float tensor_input[1][14], const float tensor_linear_list_0_weight[32][14], const float tensor_linear_list_0_bias[32], float tensor_7[1][32]);
static inline void node_Relu_1(const float tensor_7[1][32], float tensor_8[1][32]);
static inline void node_Gemm_2(const float tensor_8[1][32], const float tensor_linear_list_1_weight[32][32], const float tensor_linear_list_1_bias[32], float tensor_9[1][32]);
static inline void node_Relu_3(const float tensor_9[1][32], float tensor_10[1][32]);
static inline void node_Gemm_4(const float tensor_10[1][32], const float tensor_linear_list_2_weight[14][32], const float tensor_linear_list_2_bias[14], float tensor_output[1][14]);

int main() {
    float tensor_input[1][14];
    float tensor_output[1][14];

    // Initialize deterministic input values
    for (int i = 0; i < 14; i++) {
        tensor_input[0][i] = tensor_input_constants[i];
    }

    entry(tensor_input, tensor_output);

    // The deterministic check that the output satisfies some condition
    assert(!(tensor_output[0][12] <= -2.2838113986655717f && tensor_output[0][0] >= -0.0f));

    return 0;
}

// Function Definitions (Nodes)
void entry(const float tensor_input[1][14], float tensor_output[1][14]) {
    union tensor_union_0 tu0;
    union tensor_union_1 tu1;

    node_Gemm_0(tensor_input, tensor_linear_list_0_weight, tensor_linear_list_0_bias, tu0.tensor_7);
    node_Relu_1(tu0.tensor_7, tu1.tensor_8);
    node_Gemm_2(tu1.tensor_8, tensor_linear_list_1_weight, tensor_linear_list_1_bias, tu0.tensor_9);
    node_Relu_3(tu0.tensor_9, tu1.tensor_10);
    node_Gemm_4(tu1.tensor_10, tensor_linear_list_2_weight, tensor_linear_list_2_bias, tensor_output);
}

static inline void node_Gemm_0(const float tensor_input[1][14], const float tensor_linear_list_0_weight[32][14], const float tensor_linear_list_0_bias[32], float tensor_7[1][32]) {
    // ... (implementation of node_Gemm_0) ...
}

static inline void node_Relu_1(const float tensor_7[1][32], float tensor_8[1][32]) {
    // ... (implementation of node_Relu_1) ...
}

static inline void node_Gemm_2(const float tensor_8[1][32], const float tensor_linear_list_1_weight[32][32], const float tensor_linear_list_1_bias[32], float tensor_9[1][32]) {
    // ... (implementation of node_Gemm_2) ...
}

static inline void node_Relu_3(const float tensor_9[1][32], float tensor_10[1][32]) {
    // ... (implementation of node_Relu_3) ...
}

static inline void node_Gemm_4(const float tensor_10[1][32], const float tensor_linear_list_2_weight[14][32], const float tensor_linear_list_2_bias[14], float tensor_output[1][14]) {
    // ... (implementation of node_Gemm_4) ...
}