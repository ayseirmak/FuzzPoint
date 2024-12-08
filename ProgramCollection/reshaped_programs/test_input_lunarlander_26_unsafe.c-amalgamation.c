#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdint.h>

// Replace __VERIFIER_assert with standard assert
#include <assert.h>

// Required weights and bias data
static const float tensor_q_net_0_weight[64][8] = {/* ... */}; // Truncated for brevity
static const float tensor_q_net_0_bias[64] = {/* ... */}; // Truncated
static const float tensor_q_net_2_weight[64][64] = {/* ... */}; // Truncated
static const float tensor_q_net_2_bias[64] = {/* ... */}; // Truncated
static const float tensor_q_net_4_weight[4][64] = {/* ... */}; // Truncated
static const float tensor_q_net_4_bias[4] = {/* ... */}; // Truncated

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
    /* Flatten */
    float *input = (float *)tensor_input;
    float *output = (float *)tensor_7;
    for (uint32_t i = 0; i < 8; i++)
        output[i] = input[i];
}

static inline void node_Gemm_1(const float tensor_7[1][8], const float tensor_q_net_0_weight[64][8], const float tensor_q_net_0_bias[64], float tensor_8[1][64]) {
    const int M = 1;
    const int K = 8;
    const int N = 64;
    float (*A)[8] = (float (*)[8])tensor_7;
    float (*Y)[64] = (float (*)[64])tensor_8;
    float alpha = 1.0f;
    float beta = 1.0f;
    float (*C)[64] = (float (*)[64])tensor_q_net_0_bias;
    for (uint32_t r = 0; r < M; r++)
        for (uint32_t c = 0; c < N; c++) {
            float ABrc = 0;
            for (uint32_t i = 0; i < K; i++) {
                float B = tensor_q_net_0_weight[c][i];
                ABrc += A[r][i] * B;
            }
            float tmp = ABrc * alpha;
            tmp += C[0][c] * beta;
            Y[r][c] = tmp;
        }
}

static inline void node_Relu_2(const float tensor_8[1][64], float tensor_9[1][64]) {
    float *X = (float *)tensor_8;
    float *Y = (float *)tensor_9;
    for (uint32_t i = 0; i < 64; i++)
        Y[i] = fmaxf(X[i], 0);
}

static inline void node_Gemm_3(const float tensor_9[1][64], const float tensor_q_net_2_weight[64][64], const float tensor_q_net_2_bias[64], float tensor_10[1][64]) {
    const int M = 1;
    const int K = 64;
    const int N = 64;
    float (*A)[64] = (float (*)[64])tensor_9;
    float (*Y)[64] = (float (*)[64])tensor_10;
    float alpha = 1.0f;
    float beta = 1.0f;
    float (*C)[64] = (float (*)[64])tensor_q_net_2_bias;
    for (uint32_t r = 0; r < M; r++)
        for (uint32_t c = 0; c < N; c++) {
            float ABrc = 0;
            for (uint32_t i = 0; i < K; i++) {
                float B = tensor_q_net_2_weight[c][i];
                ABrc += A[r][i] * B;
            }
            float tmp = ABrc * alpha;
            tmp += C[0][c] * beta;
            Y[r][c] = tmp;
        }
}

static inline void node_Relu_4(const float tensor_10[1][64], float tensor_11[1][64]) {
    float *X = (float *)tensor_10;
    float *Y = (float *)tensor_11;
    for (uint32_t i = 0; i < 64; i++)
        Y[i] = fmaxf(X[i], 0);
}

static inline void node_Gemm_5(const float tensor_11[1][64], const float tensor_q_net_4_weight[4][64], const float tensor_q_net_4_bias[4], float tensor_output[1][4]) {
    const int M = 1;
    const int K = 64;
    const int N = 4;
    float (*A)[64] = (float (*)[64])tensor_11;
    float (*Y)[4] = (float (*)[4])tensor_output;
    float alpha = 1.0f;
    float beta = 1.0f;
    float (*C)[4] = (float (*)[4])tensor_q_net_4_bias;
    for (uint32_t r = 0; r < M; r++)
        for (uint32_t c = 0; c < N; c++) {
            float ABrc = 0;
            for (uint32_t i = 0; i < K; i++) {
                float B = tensor_q_net_4_weight[c][i];
                ABrc += A[r][i] * B;
            }
            float tmp = ABrc * alpha;
            tmp += C[0][c] * beta;
            Y[r][c] = tmp;
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
    float tensor_input[1][8] = {
        {-0.7296881158570574f, 0.04822218185705744f, 0.03053908185705745f, -0.05765323285705744f,
         -0.009961814857057444f, -0.07178652585705744f, 0.9997713441429425f, 0.9997713441429425f}};
    float tensor_output[1][4];
    
    entry(tensor_input, tensor_output);

    // Replacing the custom verifier assert
    assert(!(tensor_output[0][2] <= tensor_output[0][3]));

    printf("Program executed successfully.\n");

    return 0;
}