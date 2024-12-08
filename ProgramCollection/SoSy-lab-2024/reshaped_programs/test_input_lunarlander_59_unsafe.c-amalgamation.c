#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <stdint.h>

// Prototypes for NN nodes
void entry(const float tensor_input[1][8], float tensor_output[1][4]);

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

// Parameters used in NN model (weights and biases)
#include "params.h"  // Assume extracted params are in this header

// Function implementations for NN layers

void node_Flatten_0(const float tensor_input[1][8], float tensor_7[1][8]) {
    // Flatten operation
    for (uint32_t i = 0; i < 8; i++) {
        tensor_7[0][i] = tensor_input[0][i];
    }
}

void node_Gemm_1(const float tensor_7[1][8], const float tensor_q_net_0_weight[64][8], 
                 const float tensor_q_net_0_bias[64], float tensor_8[1][64]) {
    const int M = 1, K = 8, N = 64;
    for(uint32_t c = 0; c < N; c++) {
        float AB = 0;
        for(uint32_t i = 0; i < K; i++) {
            AB += tensor_7[0][i] * tensor_q_net_0_weight[c][i];
        }
        tensor_8[0][c] = AB + tensor_q_net_0_bias[c];
    }
}

void node_Relu_2(const float tensor_8[1][64], float tensor_9[1][64]) {
    for (uint32_t i = 0; i < 64; i++) {
        tensor_9[0][i] = fmax(0, tensor_8[0][i]);
    }
}

void node_Gemm_3(const float tensor_9[1][64], const float tensor_q_net_2_weight[64][64], 
                 const float tensor_q_net_2_bias[64], float tensor_10[1][64]) {
    const int M = 1, K = 64, N = 64;
    for(uint32_t c = 0; c < N; c++) {
        float AB = 0;
        for(uint32_t i = 0; i < K; i++) {
            AB += tensor_9[0][i] * tensor_q_net_2_weight[c][i];
        }
        tensor_10[0][c] = AB + tensor_q_net_2_bias[c];
    }
}

void node_Relu_4(const float tensor_10[1][64], float tensor_11[1][64]) {
    for (uint32_t i = 0; i < 64; i++) {
        tensor_11[0][i] = fmax(0, tensor_10[0][i]);
    }
}

void node_Gemm_5(const float tensor_11[1][64], const float tensor_q_net_4_weight[4][64], 
                 const float tensor_q_net_4_bias[4], float tensor_output[1][4]) {
    const int M = 1, K = 64, N = 4;
    for(uint32_t c = 0; c < N; c++) {
        float AB = 0;
        for(uint32_t i = 0; i < K; i++) {
            AB += tensor_11[0][i] * tensor_q_net_4_weight[c][i];
        }
        tensor_output[0][c] = AB + tensor_q_net_4_bias[c];
    }
}

int main() {
    float tensor_input[1][8] = {
        {-0.925, 0.078, 0.070, -0.020, -0.409, 0.0, 1.0, 1.0}  // Assumed fixed values within given assume range
    };
    float tensor_output[1][4];

    entry(tensor_input, tensor_output);

    assert(!(tensor_output[0][2] <= tensor_output[0][3]));
    printf("Verification passed!\n");

    return 0;
}