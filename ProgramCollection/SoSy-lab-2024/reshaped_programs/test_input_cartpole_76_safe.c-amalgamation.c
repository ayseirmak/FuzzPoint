#include <stdio.h>
#include <math.h>
#include <assert.h>

// Function prototype
void entry(const float tensor_input[1][4], float tensor_output[1][2]);

int main() {
    float tensor_input[1][4];
    float tensor_output[1][2];

    // Initialize tensor_input with fixed deterministic values
    tensor_input[0][0] = -0.255;
    tensor_input[0][1] = 0.140;
    tensor_input[0][2] = -0.023;
    tensor_input[0][3] = -0.592;

    // Call the entry function
    entry(tensor_input, tensor_output);

    // Assert that the condition is met (changed from __VERIFIER_assert)
    assert(!(tensor_output[0][0] <= tensor_output[0][1]));

    for (int i = 0; i < 2; ++i) {
        printf("tensor_output[0][%d] = %f\n", i, tensor_output[0][i]);
    }

    return 0;
}

// Variable declarations and definitions

static const float tensor_q_net_0_weight[64][4] = {
    // Initialization data ...
};

static const float tensor_q_net_0_bias[64] = {
    // Initialization data ...
};

static const float tensor_q_net_2_weight[64][64] = {
    // Initialization data ...
};

static const float tensor_q_net_2_bias[64] = {
    // Initialization data ...
};

static const float tensor_q_net_4_weight[2][64] = {
    // Initialization data ...
};

static const float tensor_q_net_4_bias[2] = {
    // Initialization data ...
};

// Union declarations remain unchanged
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

// Function definitions for each node

static inline void node_Flatten_0(const float tensor_input[1][4], float tensor_7[1][4]) {
    // Flatten function
    for (uint32_t i = 0; i < 4; i++)
        tensor_7[0][i] = tensor_input[0][i];
}

static inline void node_Gemm_1(const float tensor_7[1][4], const float tensor_q_net_0_weight[64][4],
    const float tensor_q_net_0_bias[64], float tensor_8[1][64]) {
    // Gemm function
    for (uint32_t i = 0; i < 64; i++) {
        tensor_8[0][i] = tensor_q_net_0_bias[i];
        for (uint32_t j = 0; j < 4; j++) {
            tensor_8[0][i] += tensor_7[0][j] * tensor_q_net_0_weight[i][j];
        }
    }
}

static inline void node_Relu_2(const float tensor_8[1][64], float tensor_9[1][64]) {
    // Relu function
    for (uint32_t i = 0; i < 64; i++)
        tensor_9[0][i] = fmaxf(tensor_8[0][i], 0);
}

static inline void node_Gemm_3(const float tensor_9[1][64], const float tensor_q_net_2_weight[64][64],
    const float tensor_q_net_2_bias[64], float tensor_10[1][64]) {
    // Gemm function
    for (uint32_t i = 0; i < 64; i++) {
        tensor_10[0][i] = tensor_q_net_2_bias[i];
        for (uint32_t j = 0; j < 64; j++) {
            tensor_10[0][i] += tensor_9[0][j] * tensor_q_net_2_weight[i][j];
        }
    }
}

static inline void node_Relu_4(const float tensor_10[1][64], float tensor_11[1][64]) {
    // Relu function
    for (uint32_t i = 0; i < 64; i++)
        tensor_11[0][i] = fmaxf(tensor_10[0][i], 0);
}

static inline void node_Gemm_5(const float tensor_11[1][64], const float tensor_q_net_4_weight[2][64],
    const float tensor_q_net_4_bias[2], float tensor_output[1][2]) {
    // Gemm function
    for (uint32_t i = 0; i < 2; i++) {
        tensor_output[0][i] = tensor_q_net_4_bias[i];
        for (uint32_t j = 0; j < 64; j++) {
            tensor_output[0][i] += tensor_11[0][j] * tensor_q_net_4_weight[i][j];
        }
    }
}

void entry(const float tensor_input[1][4], float tensor_output[1][2]) {
    node_Flatten_0(tensor_input, tu0.tensor_7);
    node_Gemm_1(tu0.tensor_7, tensor_q_net_0_weight, tensor_q_net_0_bias, tu1.tensor_8);
    node_Relu_2(tu1.tensor_8, tu0.tensor_9);
    node_Gemm_3(tu0.tensor_9, tensor_q_net_2_weight, tensor_q_net_2_bias, tu1.tensor_10);
    node_Relu_4(tu1.tensor_10, tu0.tensor_11);
    node_Gemm_5(tu0.tensor_11, tensor_q_net_4_weight, tensor_q_net_4_bias, tensor_output);
}