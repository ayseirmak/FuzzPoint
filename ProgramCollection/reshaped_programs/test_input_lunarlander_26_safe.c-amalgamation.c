#include <assert.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

// Helper definitions
#define MAX(X, Y) ((X) > (Y) ? (X) : (Y))
#define MIN(X, Y) ((X) < (Y) ? (X) : (Y))
#define CLIP(X, L) (MAX(MIN(X, L), -L))

// Static weights and biases (only relevant parts shown for simplicity due to size constraints)
static const float tensor_q_net_0_weight[64][8] = {/* ... */};
static const float tensor_q_net_0_bias[64] = {/* ... */};
static const float tensor_q_net_2_weight[64][64] = {/* ... */};
static const float tensor_q_net_2_bias[64] = {/* ... */};
static const float tensor_q_net_4_weight[4][64] = {/* ... */};
static const float tensor_q_net_4_bias[4] = {/* ... */};

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
    for (uint32_t i = 0; i < 8; i++)
        tensor_7[0][i] = tensor_input[0][i];
}

static inline void node_Gemm_1(const float tensor_7[1][8], const float tensor_q_net_0_weight[64][8], const float tensor_q_net_0_bias[64], float tensor_8[1][64]) {
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
    for (uint32_t i = 0; i < 64; i++)
        tensor_9[0][i] = tensor_8[0][i] > 0 ? tensor_8[0][i] : 0;
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
    for (uint32_t i = 0; i < 64; i++)
        tensor_11[0][i] = tensor_10[0][i] > 0 ? tensor_10[0][i] : 0;
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

void entry(const float tensor_input[1][8], float tensor_output[1][4]) {
    node_Flatten_0(tensor_input, tu0.tensor_7);
    node_Gemm_1(tu0.tensor_7, tensor_q_net_0_weight, tensor_q_net_0_bias, tu1.tensor_8);
    node_Relu_2(tu1.tensor_8, tu0.tensor_9);
    node_Gemm_3(tu0.tensor_9, tensor_q_net_2_weight, tensor_q_net_2_bias, tu1.tensor_10);
    node_Relu_4(tu1.tensor_10, tu0.tensor_11);
    node_Gemm_5(tu0.tensor_11, tensor_q_net_4_weight, tensor_q_net_4_bias, tensor_output);
}

int main() {
    // Fixed deterministic input values
    float tensor_input[1][8] = {
        {-0.72f, 0.04f, 4.0f, -0.05f, -0.01f, -0.08f, 1.0f, 1.0f}
    };
    
    float tensor_output[1][4];
    
    entry(tensor_input, tensor_output);
    
    // Output verification, equivalent to __VERIFIER_assert(!((tensor_output[0][2] <= tensor_output[0][3])));
    assert(tensor_output[0][2] > tensor_output[0][3]);
    
    printf("Assertion passed, output[2] is greater than output[3]\n");
    return 0;
}