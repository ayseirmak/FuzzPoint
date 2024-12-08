#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdint.h>

// Declare the tensor weights and biases
static const float tensor_q_net_0_weight[64][8] = { ... }; // Truncated for brevity
static const float tensor_q_net_0_bias[64] = { ... };
static const float tensor_q_net_2_weight[64][64] = { ... };
static const float tensor_q_net_2_bias[64] = { ... };
static const float tensor_q_net_4_weight[4][64] = { ... };
static const float tensor_q_net_4_bias[4] = { ... };

// Define the union tensors
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

// Define the functions for tensor operations
static inline void node_Flatten_0(const float tensor_input[1][8], float tensor_7[1][8]) {
    for (uint32_t i = 0; i < 8; i++)
        tensor_7[0][i] = tensor_input[0][i];
}

static inline void node_Gemm_1(const float tensor_7[1][8], const float tensor_q_net_0_weight[64][8], const float tensor_q_net_0_bias[64], float tensor_8[1][64]) {
    float alpha = 1.0f;
    float beta = 1.0f;
    
    for (uint32_t c = 0; c < 64; c++) {
        float sum = tensor_q_net_0_bias[c] * beta;
        for (uint32_t i = 0; i < 8; i++) {
            sum += tensor_7[0][i] * tensor_q_net_0_weight[c][i] * alpha;
        }
        tensor_8[0][c] = sum;
    }
}

static inline void node_Relu_2(const float tensor_8[1][64], float tensor_9[1][64]) {
    for (uint32_t i = 0; i < 64; i++)
        tensor_9[0][i] = fmaxf(0.0f, tensor_8[0][i]);
}

static inline void node_Gemm_3(const float tensor_9[1][64], const float tensor_q_net_2_weight[64][64], const float tensor_q_net_2_bias[64], float tensor_10[1][64]) {
    float alpha = 1.0f;
    float beta = 1.0f;

    for (uint32_t c = 0; c < 64; c++) {
        float sum = tensor_q_net_2_bias[c] * beta;
        for (uint32_t i = 0; i < 64; i++) {
            sum += tensor_9[0][i] * tensor_q_net_2_weight[c][i] * alpha;
        }
        tensor_10[0][c] = sum;
    }
}

static inline void node_Relu_4(const float tensor_10[1][64], float tensor_11[1][64]) {
    for (uint32_t i = 0; i < 64; i++)
        tensor_11[0][i] = fmaxf(0.0f, tensor_10[0][i]);
}

static inline void node_Gemm_5(const float tensor_11[1][64], const float tensor_q_net_4_weight[4][64], const float tensor_q_net_4_bias[4], float tensor_output[1][4]) {
    float alpha = 1.0f;
    float beta = 1.0f;

    for (uint32_t c = 0; c < 4; c++) {
        float sum = tensor_q_net_4_bias[c] * beta;
        for (uint32_t i = 0; i < 64; i++) {
            sum += tensor_11[0][i] * tensor_q_net_4_weight[c][i] * alpha;
        }
        tensor_output[0][c] = sum;
    }
}

// Entry function
void entry(const float tensor_input[1][8], float tensor_output[1][4]) {
    node_Flatten_0(tensor_input, tu0.tensor_7);
    node_Gemm_1(tu0.tensor_7, tensor_q_net_0_weight, tensor_q_net_0_bias, tu1.tensor_8);
    node_Relu_2(tu1.tensor_8, tu0.tensor_9);
    node_Gemm_3(tu0.tensor_9, tensor_q_net_2_weight, tensor_q_net_2_bias, tu1.tensor_10);
    node_Relu_4(tu1.tensor_10, tu0.tensor_11);
    node_Gemm_5(tu0.tensor_11, tensor_q_net_4_weight, tensor_q_net_4_bias, tensor_output);
}

int main() {
    float tensor_input[1][8] = {{-0.7f, 0.05f, 0.03f, -0.05f, 0.08f, -0.06f, 1.0f, 1.0f}};
    float tensor_output[1][4];

    entry(tensor_input, tensor_output);

    assert(tensor_output[0][2] > tensor_output[0][3]);

    for (int i = 0; i < 4; i++) {
        printf("Output %d: %f\n", i, tensor_output[0][i]);
    }

    return 0;
}