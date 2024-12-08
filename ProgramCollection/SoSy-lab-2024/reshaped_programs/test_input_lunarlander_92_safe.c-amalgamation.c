#include <stdio.h>
#include <float.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <assert.h>

// Function declarations for entry and helper functions
void entry(const float tensor_input[1][8], float tensor_output[1][4]);
static inline void node_Flatten_0(const float tensor_input[1][8], float tensor_7[1][8]);
static inline void node_Gemm_1(const float tensor_7[1][8], const float tensor_q_net_0_weight[64][8], const float tensor_q_net_0_bias[64], float tensor_8[1][64]);
static inline void node_Relu_2(const float tensor_8[1][64], float tensor_9[1][64]);
static inline void node_Gemm_3(const float tensor_9[1][64], const float tensor_q_net_2_weight[64][64], const float tensor_q_net_2_bias[64], float tensor_10[1][64]);
static inline void node_Relu_4(const float tensor_10[1][64], float tensor_11[1][64]);
static inline void node_Gemm_5(const float tensor_11[1][64], const float tensor_q_net_4_weight[4][64], const float tensor_q_net_4_bias[4], float tensor_output[1][4]);

// Define fixed tensor input for our deterministic test case
float tensor_input[1][8] = {
    {-0.8f, 0.1f, -0.03f, 0.02f, 0.04f, 0.05f, 0.0f, 1.0f}
};

int main() {
    float tensor_output[1][4];

    entry(tensor_input, tensor_output);

    assert(!(tensor_output[0][3] <= tensor_output[0][2]));
    
    printf("Execution completed successfully with deterministic input.\n");
    return 0;
}

// Provided static data
static const float tensor_q_net_0_weight[64][8] = { /* data */ }; // Replace with actual data
static const float tensor_q_net_0_bias[64] = { /* data */ }; // Replace with actual data
static const float tensor_q_net_2_weight[64][64] = { /* data */ }; // Replace with actual data
static const float tensor_q_net_2_bias[64] = { /* data */ }; // Replace with actual data
static const float tensor_q_net_4_weight[4][64] = { /* data */ }; // Replace with actual data
static const float tensor_q_net_4_bias[4] = { /* data */ }; // Replace with actual data

// Function implementations

void entry(const float tensor_input[1][8], float tensor_output[1][4]) {
    static union {
        float tensor_7[1][8];
        float tensor_9[1][64];
        float tensor_11[1][64];
    } tu0;

    static union {
        float tensor_8[1][64];
        float tensor_10[1][64];
    } tu1;

    node_Flatten_0(tensor_input, tu0.tensor_7);
    node_Gemm_1(tu0.tensor_7, tensor_q_net_0_weight, tensor_q_net_0_bias, tu1.tensor_8);
    node_Relu_2(tu1.tensor_8, tu0.tensor_9);
    node_Gemm_3(tu0.tensor_9, tensor_q_net_2_weight, tensor_q_net_2_bias, tu1.tensor_10);
    node_Relu_4(tu1.tensor_10, tu0.tensor_11);
    node_Gemm_5(tu0.tensor_11, tensor_q_net_4_weight, tensor_q_net_4_bias, tensor_output);
}

static inline void node_Flatten_0(const float tensor_input[1][8], float tensor_7[1][8]) {
    /* Flatten */
    float *input = (float*)tensor_input;
    float *output = (float*)tensor_7;
    for (uint32_t i = 0; i < 8; i++)
        output[i] = input[i];
}

static inline void node_Gemm_1(const float tensor_7[1][8], const float tensor_q_net_0_weight[64][8], const float tensor_q_net_0_bias[64], float tensor_8[1][64]) {
    /* Gemm */
    const int M = 1, K = 8, N = 64;
    float alpha = 1.0, beta = 1.0;
    for (uint32_t r = 0; r < M; r++)
        for (uint32_t c = 0; c < N; c++) {
            float ABrc = 0;
            for (uint32_t i = 0; i < K; i++)
                ABrc += tensor_7[r][i] * tensor_q_net_0_weight[c][i];
            tensor_8[r][c] = ABrc * alpha + tensor_q_net_0_bias[c] * beta;
        }
}

static inline void node_Relu_2(const float tensor_8[1][64], float tensor_9[1][64]) {
    float *X = (float*)tensor_8;
    float *Y = (float*)tensor_9;
    for (uint32_t i = 0; i < 64; i++)
        Y[i] = X[i] > 0 ? X[i] : 0;
}

static inline void node_Gemm_3(const float tensor_9[1][64], const float tensor_q_net_2_weight[64][64], const float tensor_q_net_2_bias[64], float tensor_10[1][64]) {
    const int M = 1, K = 64, N = 64;
    float alpha = 1.0, beta = 1.0;
    for (uint32_t r = 0; r < M; r++)
        for (uint32_t c = 0; c < N; c++) {
            float ABrc = 0;
            for (uint32_t i = 0; i < K; i++)
                ABrc += tensor_9[r][i] * tensor_q_net_2_weight[c][i];
            tensor_10[r][c] = ABrc * alpha + tensor_q_net_2_bias[c] * beta;
        }
}

static inline void node_Relu_4(const float tensor_10[1][64], float tensor_11[1][64]) {
    float *X = (float*)tensor_10;
    float *Y = (float*)tensor_11;
    for (uint32_t i = 0; i < 64; i++)
        Y[i] = X[i] > 0 ? X[i] : 0;
}

static inline void node_Gemm_5(const float tensor_11[1][64], const float tensor_q_net_4_weight[4][64], const float tensor_q_net_4_bias[4], float tensor_output[1][4]) {
    const int M = 1, K = 64, N = 4;
    float alpha = 1.0, beta = 1.0;
    for (uint32_t r = 0; r < M; r++)
        for (uint32_t c = 0; c < N; c++) {
            float ABrc = 0;
            for (uint32_t i = 0; i < K; i++)
                ABrc += tensor_11[r][i] * tensor_q_net_4_weight[c][i];
            tensor_output[r][c] = ABrc * alpha + tensor_q_net_4_bias[c] * beta;
        }
}