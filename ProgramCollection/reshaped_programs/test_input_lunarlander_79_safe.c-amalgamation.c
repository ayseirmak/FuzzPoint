#include <stdio.h>
#include <float.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <assert.h>

#define MAX(X,Y) ( X > Y ? X : Y)
#define MIN(X,Y) ( X < Y ? X : Y)

void entry(const float tensor_input[1][8], float tensor_output[1][4]);

int main() {
    float tensor_input[1][8];
    float tensor_output[1][4];

    // Initialize tensor_input with fixed deterministic values within the assumed ranges
    tensor_input[0][0] = -0.5718635124521179f; // Midpoint of [-0.5818635124521179, -0.5612386875478821]
    tensor_input[0][1] = 0.1575f; // Midpoint of [0.1471872775478821, 0.1678121024521179]
    tensor_input[0][2] = -0.011839741f; // Midpoint of [-0.022152153452117886, -0.001527328547882116]
    tensor_input[0][3] = 0.030455362f; // Midpoint of [0.020142949547882115, 0.040767774452117884]
    tensor_input[0][4] = 0.049534935f; // Midpoint of [0.03922252354788212, 0.059847348452117886]
    tensor_input[0][5] = -0.002190947f; // Midpoint of [-0.012503359452117885, 0.008121465452117884]
    tensor_input[0][6] = 0.0f; // Midpoint of [-0.010312412452117885, 0.010312412452117885]
    tensor_input[0][7] = 0.0f; // Midpoint of [-0.010312412452117885, 0.010312412452117885]

    entry(tensor_input, tensor_output);

    assert(!(tensor_output[0][3] <= tensor_output[0][2]));

    return 0;
}

// Copied tensor network weights and biases omitted for brevity
// Please include the provided tensor weights and biases here

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

static inline void node_Flatten_0(const float tensor_input[1][8], float tensor_7[1][8]) {
    float *input = (float*)tensor_input;
    float *output = (float*)tensor_7;
    for (uint32_t i = 0; i < 8; i++)
        output[i] = input[i];
}

static inline void node_Gemm_1(const float tensor_7[1][8], const float tensor_q_net_0_weight[64][8], const float tensor_q_net_0_bias[64], float tensor_8[1][64]) {
    const int M = 1, K = 8, N = 64;
    float (*A)[8]  = (float(*)[8])tensor_7;
    float (*Y)[64] = (float(*)[64])tensor_8;
    float alpha = 1.0f, beta = 1.0f;
    float (*C)[64] = (float(*)[64])tensor_q_net_0_bias;
    for (uint32_t r = 0; r < M; r++)
        for (uint32_t c = 0; c < N; c++) {
            float ABrc = 0;
            for (uint32_t i = 0; i < K; i++) {
                float B = tensor_q_net_0_weight[c][i];
                ABrc += A[r][i] * B;
            }
            Y[r][c] = ABrc * alpha + C[0][c] * beta;
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
    float (*A)[64] = (float(*)[64])tensor_9;
    float (*Y)[64] = (float(*)[64])tensor_10;
    float alpha = 1.0f, beta = 1.0f;
    float (*C)[64] = (float(*)[64])tensor_q_net_2_bias;
    for (uint32_t r = 0; r < M; r++)
        for (uint32_t c = 0; c < N; c++) {
            float ABrc = 0;
            for (uint32_t i = 0; i < K; i++) {
                float B = tensor_q_net_2_weight[c][i];
                ABrc += A[r][i] * B;
            }
            Y[r][c] = ABrc * alpha + C[0][c] * beta;
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
    float (*A)[64] = (float(*)[64])tensor_11;
    float (*Y)[4]  = (float(*)[4])tensor_output;
    float alpha = 1.0f, beta = 1.0f;
    float (*C)[4]  = (float(*)[4])tensor_q_net_4_bias;
    for (uint32_t r = 0; r < M; r++)
        for (uint32_t c = 0; c < N; c++) {
            float ABrc = 0;
            for (uint32_t i = 0; i < K; i++) {
                float B = tensor_q_net_4_weight[c][i];
                ABrc += A[r][i] * B;
            }
            Y[r][c] = ABrc * alpha + C[0][c] * beta;
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