#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdint.h>

void entry(const float tensor_input[1][8], float tensor_output[1][4]);

int main() {
    float tensor_input[1][8];
    float tensor_output[1][4];

    // Initialize with deterministic values within the specified ranges
    tensor_input[0][0] = -0.9f;
    tensor_input[0][1] = 0.05f;
    tensor_input[0][2] = 0.7f;
    tensor_input[0][3] = -0.2f;
    tensor_input[0][4] = -0.4f;
    tensor_input[0][5] = 0.0f;
    tensor_input[0][6] = 1.0f;
    tensor_input[0][7] = 1.0f;

    entry(tensor_input, tensor_output);

    // Assert that tensor_output[0][2] is greater than tensor_output[0][3]
    assert(!(tensor_output[0][2] <= tensor_output[0][3]));

    printf("Program completed without assertion errors.\n");
    return 0;
}

// Add the complete set of functions `entry`, `node_Flatten_0`, `node_Gemm_1`, `node_Relu_2`,
// `node_Gemm_3`, `node_Relu_4`, and `node_Gemm_5` as per the original code
// with their accurate implementations here.
// You have already provided initialization of `tensor_q_net_0_weight`,
// `tensor_q_net_0_bias`, `tensor_q_net_2_weight`, `tensor_q_net_2_bias`,
// `tensor_q_net_4_weight`, `tensor_q_net_4_bias`, and the unions.

// The static inline nodes have been implemented as in the original code provided:

static inline void node_Flatten_0(const float tensor_input[1][8], float tensor_7[1][8]) {
    /* Flatten */
    for(uint32_t i = 0; i < 8; i++) {
        tensor_7[0][i] = tensor_input[0][i];
    }
}

static inline void node_Gemm_1(const float tensor_7[1][8], const float tensor_q_net_0_weight[64][8], const float tensor_q_net_0_bias[64], float tensor_8[1][64]) {
    const int M = 1;
    const int K = 8;
    const int N = 64;
    for(uint32_t r = 0; r < M; r++)
        for(uint32_t c = 0; c < N; c++) {
            float ABrc = 0;
            for(uint32_t i = 0; i < K; i++) {
                float B = tensor_q_net_0_weight[c][i];
                ABrc += tensor_7[r][i] * B;
            }
            float tmp = ABrc + tensor_q_net_0_bias[c];
            tensor_8[r][c] = tmp;
        }
}

static inline void node_Relu_2(const float tensor_8[1][64], float tensor_9[1][64]) {
    for(uint32_t i = 0; i < 64; i++) {
        tensor_9[0][i] = fmaxf(tensor_8[0][i], 0);
    }
}

static inline void node_Gemm_3(const float tensor_9[1][64], const float tensor_q_net_2_weight[64][64], const float tensor_q_net_2_bias[64], float tensor_10[1][64]) {
    const int M = 1;
    const int K = 64;
    const int N = 64;
    for(uint32_t r = 0; r < M; r++)
        for(uint32_t c = 0; c < N; c++) {
            float ABrc = 0;
            for(uint32_t i = 0; i < K; i++) {
                float B = tensor_q_net_2_weight[c][i];
                ABrc += tensor_9[r][i] * B;
            }
            float tmp = ABrc + tensor_q_net_2_bias[c];
            tensor_10[r][c] = tmp;
        }
}

static inline void node_Relu_4(const float tensor_10[1][64], float tensor_11[1][64]) {
    for(uint32_t i = 0; i < 64; i++) {
        tensor_11[0][i] = fmaxf(tensor_10[0][i], 0);
    }
}

static inline void node_Gemm_5(const float tensor_11[1][64], const float tensor_q_net_4_weight[4][64], const float tensor_q_net_4_bias[4], float tensor_output[1][4]) {
    const int M = 1;
    const int K = 64;
    const int N = 4;
    for(uint32_t r = 0; r < M; r++)
        for(uint32_t c = 0; c < N; c++) {
            float ABrc = 0;
            for(uint32_t i = 0; i < K; i++) {
                float B = tensor_q_net_4_weight[c][i];
                ABrc += tensor_11[r][i] * B;
            }
            float tmp = ABrc + tensor_q_net_4_bias[c];
            tensor_output[r][c] = tmp;
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