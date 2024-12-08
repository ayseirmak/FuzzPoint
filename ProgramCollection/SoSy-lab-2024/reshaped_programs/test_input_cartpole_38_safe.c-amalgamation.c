#include <stdio.h>
#include <math.h>
#include <stdint.h>
#include <stdbool.h>
#include <assert.h>

// Function declarations
void entry(const float tensor_input[1][4], float tensor_output[1][2]);

// Custom deterministic assertions
void assume(bool condition) {
    assert(condition);
}
void assert_custom(bool condition) {
    assert(condition);
}

int main() {
    float tensor_input[1][4];
    float tensor_output[1][2];

    // Deterministically initialized inputs
    tensor_input[0][0] = 0.47f;
    tensor_input[0][1] = -0.68f;
    tensor_input[0][2] = 0.01f;
    tensor_input[0][3] = 0.86f;

    // Assumptions using custom deterministic assertions
    assume(tensor_input[0][0] >= 0.4653275650674913f && tensor_input[0][0] <= 0.48315743493250873f);
    assume(tensor_input[0][1] >= -0.6935869349325087f && tensor_input[0][1] <= -0.6757570650674912f);
    assume(tensor_input[0][2] >= 0.001748264067491262f && tensor_input[0][2] <= 0.019578133932508738f);
    assume(tensor_input[0][3] >= 0.8538347650674912f && tensor_input[0][3] <= 0.8716646349325087f);

    entry(tensor_input, tensor_output);

    // Use custom assertion to verify expectation
    assert_custom(!(tensor_output[0][0] <= tensor_output[0][1]));

    return 0;
}

// Definitions of the required functions and variables
static const float tensor_q_net_0_weight[64][4] = {
    // The weights matrix used in the entry function
    // ... (initialize as per original array values)
};
static const float tensor_q_net_0_bias[64] = {
    // The bias vector used in the entry function
    // ... (initialize as per original array values)
};
static const float tensor_q_net_2_weight[64][64] = {
    // The weights matrix used in the entry function
    // ... (initialize as per original array values)
};
static const float tensor_q_net_2_bias[64] = {
    // The bias vector used in the entry function
    // ... (initialize as per original array values)
};
static const float tensor_q_net_4_weight[2][64] = {
    // The weight matrix for the output layer
    // ... (initialize as per original array values)
};
static const float tensor_q_net_4_bias[2] = {
    // The bias vector for the output layer
    // ... (initialize as per original array values)
};

union tensor_union_0 {
    float tensor_7[1][4];
    float tensor_9[1][64];
    float tensor_11[1][64];
};
static union tensor_union_0 tu0;

union tensor_union_1 {
    float tensor_8[1][64];
    float tensor_10[1][64];
};
static union tensor_union_1 tu1;

static inline void node_Flatten_0(const float tensor_input[1][4], float tensor_7[1][4]) {
    // Flatten function implementation
}

static inline void node_Gemm_1(const float tensor_7[1][4], const float tensor_q_net_0_weight[64][4], const float tensor_q_net_0_bias[64], float tensor_8[1][64]) {
    // Gemm function implementation
}

static inline void node_Relu_2(const float tensor_8[1][64], float tensor_9[1][64]) {
    // Relu function implementation
}

static inline void node_Gemm_3(const float tensor_9[1][64], const float tensor_q_net_2_weight[64][64], const float tensor_q_net_2_bias[64], float tensor_10[1][64]) {
    // Gemm function implementation
}

static inline void node_Relu_4(const float tensor_10[1][64], float tensor_11[1][64]) {
    // Relu function implementation
}

static inline void node_Gemm_5(const float tensor_11[1][64], const float tensor_q_net_4_weight[2][64], const float tensor_q_net_4_bias[2], float tensor_output[1][2]) {
    // Gemm function implementation
}

void entry(const float tensor_input[1][4], float tensor_output[1][2]) {
    node_Flatten_0(tensor_input, tu0.tensor_7);
    node_Gemm_1(tu0.tensor_7, tensor_q_net_0_weight, tensor_q_net_0_bias, tu1.tensor_8);
    node_Relu_2(tu1.tensor_8, tu0.tensor_9);
    node_Gemm_3(tu0.tensor_9, tensor_q_net_2_weight, tensor_q_net_2_bias, tu1.tensor_10);
    node_Relu_4(tu1.tensor_10, tu0.tensor_11);
    node_Gemm_5(tu0.tensor_11, tensor_q_net_4_weight, tensor_q_net_4_bias, tensor_output);
}