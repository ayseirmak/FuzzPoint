#include <stdio.h>
#include <math.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

// Function declarations
void entry(const float tensor_input[1][8], float tensor_output[1][4]);

#define MAX(X,Y) ((X) > (Y) ? (X) : (Y))
#define MIN(X,Y) ((X) < (Y) ? (X) : (Y))
#define CLIP(X,L) (MAX(MIN(X,L), -L))

// Static weights and bias arrays
static const float tensor_q_net_0_weight[64][8] = { /* ... omitted for brevity ... */ };
static const float tensor_q_net_0_bias[64] = { /* ... omitted for brevity ... */ };
static const float tensor_q_net_2_weight[64][64] = { /* ... omitted for brevity ... */ };
static const float tensor_q_net_2_bias[64] = { /* ... omitted for brevity ... */ };
static const float tensor_q_net_4_weight[4][64] = { /* ... omitted for brevity ... */ };
static const float tensor_q_net_4_bias[4] = { /* ... omitted for brevity ... */ };

// Main function
int main() {
    float tensor_input[1][8];
    float tensor_output[1][4];

    // Explicitly initializing tensor_input with deterministic values
    tensor_input[0][0] = -0.55f;
    tensor_input[0][1] = 0.12f;
    tensor_input[0][2] = 0.03f;
    tensor_input[0][3] = -0.02f;
    tensor_input[0][4] = 0.08f;
    tensor_input[0][5] = -0.15f;
    tensor_input[0][6] = 0.0f;
    tensor_input[0][7] = 1.0f;

    // Call the entry function
    entry(tensor_input, tensor_output);

    // Assert condition
    if (!(tensor_output[0][2] <= tensor_output[0][3])) {
        printf("Assertion Passed! tensor_output[0][2] is NOT less than or equal to tensor_output[0][3].\n");
    } else {
        printf("Assertion Failed! tensor_output[0][2] is less than or equal to tensor_output[0][3].\n");
    }

    return 0;
}

// Flatten layer
static inline void node_Flatten_0(const float tensor_input[1][8], float tensor_7[1][8]) {
    float *input = (float*)tensor_input;
    float *output = (float*)tensor_7;
    for (uint32_t i = 0; i < 8; i++) {
        output[i] = input[i];
    }
}

// Gemm layer with specified dimension sizes
static inline void node_Gemm_1(const float tensor_7[1][8], const float tensor_q_net_0_weight[64][8], const float tensor_q_net_0_bias[64], float tensor_8[1][64]) {
    const int M = 1;
    const int K = 8;
    const int N = 64;
    float alpha = 1.0f;
    float beta = 1.0f;
    for (uint32_t r = 0; r < M; r++) {
        for (uint32_t c = 0; c < N; c++) {
            float ABrc = 0;
            for (uint32_t i = 0; i < K; i++) {
                float B = tensor_q_net_0_weight[c][i];
                ABrc += tensor_7[r][i] * B;
            }
            float tmp = ABrc * alpha;
            tmp += tensor_q_net_0_bias[c] * beta;
            tensor_8[r][c] = tmp;
        }
    }
}

// Relu node
static inline void node_Relu_2(const float tensor_8[1][64], float tensor_9[1][64]) {
    float *X = (float*)tensor_8;
    float *Y = (float*)tensor_9;
    for (uint32_t i = 0; i < 64; i++) {
        Y[i] = X[i] > 0 ? X[i] : 0;
    }
}

// Second Gemm layer
static inline void node_Gemm_3(const float tensor_9[1][64], const float tensor_q_net_2_weight[64][64], const float tensor_q_net_2_bias[64], float tensor_10[1][64]) {
    const int M = 1;
    const int K = 64;
    const int N = 64;
    float alpha = 1.0f;
    float beta = 1.0f;
    for (uint32_t r = 0; r < M; r++) {
        for (uint32_t c = 0; c < N; c++) {
            float ABrc = 0;
            for (uint32_t i = 0; i < K; i++) {
                float B = tensor_q_net_2_weight[c][i];
                ABrc += tensor_9[r][i] * B;
            }
            float tmp = ABrc * alpha;
            tmp += tensor_q_net_2_bias[c] * beta;
            tensor_10[r][c] = tmp;
        }
    }
}

// Second Relu node
static inline void node_Relu_4(const float tensor_10[1][64], float tensor_11[1][64]) {
    float *X = (float*)tensor_10;
    float *Y = (float*)tensor_11;
    for (uint32_t i = 0; i < 64; i++) {
        Y[i] = X[i] > 0 ? X[i] : 0;
    }
}

// Third Gemm layer (output layer)
static inline void node_Gemm_5(const float tensor_11[1][64], const float tensor_q_net_4_weight[4][64], const float tensor_q_net_4_bias[4], float tensor_output[1][4]) {
    const int M = 1;
    const int K = 64;
    const int N = 4;
    float alpha = 1.0f;
    float beta = 1.0f;
    for (uint32_t r = 0; r < M; r++) {
        for (uint32_t c = 0; c < N; c++) {
            float ABrc = 0;
            for (uint32_t i = 0; i < K; i++) {
                float B = tensor_q_net_4_weight[c][i];
                ABrc += tensor_11[r][i] * B;
            }
            float tmp = ABrc * alpha;
            tmp += tensor_q_net_4_bias[c] * beta;
            tensor_output[r][c] = tmp;
        }
    }
}

// Entry function definition
void entry(const float tensor_input[1][8], float tensor_output[1][4]) {
    union {
        float tensor_split_0[1][8];
        float tensor_split_1[1][64];
        float tensor_split_2[1][64];
    } temp_union_0;

    union {
        float tensor_split_3[1][64];
        float tensor_split_4[1][64];
    } temp_union_1;

    node_Flatten_0(tensor_input, temp_union_0.tensor_split_0);
    node_Gemm_1(temp_union_0.tensor_split_0, tensor_q_net_0_weight, tensor_q_net_0_bias, temp_union_1.tensor_split_3);
    node_Relu_2(temp_union_1.tensor_split_3, temp_union_0.tensor_split_1);
    node_Gemm_3(temp_union_0.tensor_split_1, tensor_q_net_2_weight, tensor_q_net_2_bias, temp_union_1.tensor_split_4);
    node_Relu_4(temp_union_1.tensor_split_4, temp_union_0.tensor_split_2);
    node_Gemm_5(temp_union_0.tensor_split_2, tensor_q_net_4_weight, tensor_q_net_4_bias, tensor_output);
}