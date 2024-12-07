// Required Libraries for Standard Compliance
#include <float.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>

// Model Weights and Biases
static const float tensor_q_net_0_weight[64][8] = {/* copied from above */};
static const float tensor_q_net_0_bias[64] = {/* copied from above */};

static const float tensor_q_net_2_weight[64][64] = {/* copied from above */};
static const float tensor_q_net_2_bias[64] = {/* copied from above */};

static const float tensor_q_net_4_weight[4][64] = {/* copied from above */};
static const float tensor_q_net_4_bias[4] = {/* copied from above */};

// Union for Intermediate Tensors
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

// Function Implementations
static inline void node_Flatten_0(const float tensor_input[1][8], float tensor_7[1][8]) {
    for (uint32_t i = 0; i < 8; i++)
        tensor_7[0][i] = tensor_input[0][i];
}

static inline void node_Gemm_1(const float tensor_7[1][8], const float tensor_q_net_0_weight[64][8], const float tensor_q_net_0_bias[64], float tensor_8[1][64]) {
    const int M = 1, K = 8, N = 64;
    for (int r = 0; r < M; r++) {
        for (int c = 0; c < N; c++) {
            float ABrc = 0;
            for (int i = 0; i < K; i++) {
                ABrc += tensor_7[r][i] * tensor_q_net_0_weight[c][i];
            }
            tensor_8[r][c] = ABrc + tensor_q_net_0_bias[c];
        }
    }
}

static inline void node_Relu_2(const float tensor_8[1][64], float tensor_9[1][64]) {
    for (uint32_t i = 0; i < 64; i++)
        tensor_9[0][i] = tensor_8[0][i] > 0 ? tensor_8[0][i] : 0;
}

static inline void node_Gemm_3(const float tensor_9[1][64], const float tensor_q_net_2_weight[64][64], const float tensor_q_net_2_bias[64], float tensor_10[1][64]) {
    const int M = 1, K = 64, N = 64;
    for (int r = 0; r < M; r++) {
        for (int c = 0; c < N; c++) {
            float ABrc = 0;
            for (int i = 0; i < K; i++) {
                ABrc += tensor_9[r][i] * tensor_q_net_2_weight[c][i];
            }
            tensor_10[r][c] = ABrc + tensor_q_net_2_bias[c];
        }
    }
}

static inline void node_Relu_4(const float tensor_10[1][64], float tensor_11[1][64]) {
    for (uint32_t i = 0; i < 64; i++)
        tensor_11[0][i] = tensor_10[0][i] > 0 ? tensor_10[0][i] : 0;
}

static inline void node_Gemm_5(const float tensor_11[1][64], const float tensor_q_net_4_weight[4][64], const float tensor_q_net_4_bias[4], float tensor_output[1][4]) {
    const int M = 1, K = 64, N = 4;
    for (int r = 0; r < M; r++) {
        for (int c = 0; c < N; c++) {
            float ABrc = 0;
            for (int i = 0; i < K; i++) {
                ABrc += tensor_11[r][i] * tensor_q_net_4_weight[c][i];
            }
            tensor_output[r][c] = ABrc + tensor_q_net_4_bias[c];
        }
    }
}

void entry(const float tensor_input[1][8], float tensor_output[1][4]) {
    node_Flatten_0(tensor_input, tu0.tensor_7);
    node_Gemm_1(tu0.tensor_7, tensor_q_net_0_weight, tensor_q_net_0_bias, tu1.tensor_8);
    node_Relu_2(tu1.tensor_8, tu0.tensor_9);
    node_Gemm_3(tu0.tensor_9, tensor_q_net_2_weight, tensor_q_net_2_bias, tu1.tensor_10);
    node_Relu_4(tu1.tensor_10, tu0.tensor_11);
    node_Gemm_5(tu0.tensor_11, tensor_q_net_4_weight, tensor_q_net_4_bias, tensor_output);
}

int main() {
    // Fixed tensor input defined directly within the program
    float tensor_input[1][8] = {
        {-0.685, 0.074, 0.029, -0.030, -0.004, -0.052, 0.000, 1.000}
    };
    float tensor_output[1][4] = {0};

    // Run the processing entry
    entry(tensor_input, tensor_output);

    // Example assertion
    if (!(tensor_output[0][2] <= tensor_output[0][3])) {
        printf("Assertion failed: tensor_output[0][2] > tensor_output[0][3]\n");
    } else {
        printf("Passed: tensor_output[0][2] <= tensor_output[0][3]\n");
    }
    
    return 0;
}