#include <stdio.h>
#include <assert.h>
#include <float.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#define MAX(X,Y) ((X) > (Y) ? (X) : (Y))
#define MIN(X,Y) ((X) < (Y) ? (X) : (Y))
#define CLIP(X,L) (MAX(MIN((X),(L)), -(L)))

// Definitions for constants used in the neural network operations (truncated for brevity)
static const float tensor_linear_list_0_weight[32][14] = { /* ... */ };
static const float tensor_linear_list_0_bias[32] = { /* ... */ };
static const float tensor_linear_list_1_weight[32][32] = { /* ... */ };
static const float tensor_linear_list_1_bias[32] = { /* ... */ };
static const float tensor_linear_list_2_weight[14][32] = { /* ... */ };
static const float tensor_linear_list_2_bias[14] = { /* ... */ };

union tensor_union_0 {
    float tensor_7[1][32];
    float tensor_9[1][32];
};
static union tensor_union_0 tu0;

union tensor_union_1 {
    float tensor_8[1][32];
    float tensor_10[1][32];
};
static union tensor_union_1 tu1;

static inline void node_Gemm_0(const float tensor_input[1][14], const float tensor_linear_list_0_weight[32][14], const float tensor_linear_list_0_bias[32], float tensor_7[1][32]) {
    const int M = 1;
    const int K = 14;
    const int N = 32;
    float (*A)[14] = (float(*)[14])tensor_input;
    float (*Y)[32] = (float(*)[32])tensor_7;
    float alpha = 1.0;
    float beta = 1.0;
    float (*C)[32] = (float(*)[32])tensor_linear_list_0_bias;
    for (uint32_t r = 0; r < M; r++)
        for (uint32_t c = 0; c < N; c++) {
            float ABrc = 0;
            for (uint32_t i = 0; i < K; i++) {
                float B = tensor_linear_list_0_weight[c][i];
                ABrc += A[r][i] * B;
            }
            float tmp = ABrc * alpha;
            tmp += C[0][c] * beta;
            Y[r][c] = tmp;
        }
}

static inline void node_Relu_1(const float tensor_7[1][32], float tensor_8[1][32]) {
    float *X = (float*)tensor_7;
    float *Y = (float*)tensor_8;
    for (uint32_t i = 0; i < 32; i++)
        Y[i] = X[i] > 0 ? X[i] : 0;
}

static inline void node_Gemm_2(const float tensor_8[1][32], const float tensor_linear_list_1_weight[32][32], const float tensor_linear_list_1_bias[32], float tensor_9[1][32]) {
    const int M = 1;
    const int K = 32;
    const int N = 32;
    float (*A)[32] = (float(*)[32])tensor_8;
    float (*Y)[32] = (float(*)[32])tensor_9;
    float alpha = 1.0;
    float beta = 1.0;
    float (*C)[32] = (float(*)[32])tensor_linear_list_1_bias;
    for (uint32_t r = 0; r < M; r++)
        for (uint32_t c = 0; c < N; c++) {
            float ABrc = 0;
            for (uint32_t i = 0; i < K; i++) {
                float B = tensor_linear_list_1_weight[c][i];
                ABrc += A[r][i] * B;
            }
            float tmp = ABrc * alpha;
            tmp += C[0][c] * beta;
            Y[r][c] = tmp;
        }
}

static inline void node_Relu_3(const float tensor_9[1][32], float tensor_10[1][32]) {
    float *X = (float*)tensor_9;
    float *Y = (float*)tensor_10;
    for (uint32_t i = 0; i < 32; i++)
        Y[i] = X[i] > 0 ? X[i] : 0;
}

static inline void node_Gemm_4(const float tensor_10[1][32], const float tensor_linear_list_2_weight[14][32], const float tensor_linear_list_2_bias[14], float tensor_output[1][14]) {
    const int M = 1;
    const int K = 32;
    const int N = 14;
    float (*A)[32] = (float(*)[32])tensor_10;
    float (*Y)[14] = (float(*)[14])tensor_output;
    float alpha = 1.0;
    float beta = 1.0;
    float (*C)[14] = (float(*)[14])tensor_linear_list_2_bias;
    for (uint32_t r = 0; r < M; r++)
        for (uint32_t c = 0; c < N; c++) {
            float ABrc = 0;
            for (uint32_t i = 0; i < K; i++) {
                float B = tensor_linear_list_2_weight[c][i];
                ABrc += A[r][i] * B;
            }
            float tmp = ABrc * alpha;
            tmp += C[0][c] * beta;
            Y[r][c] = tmp;
        }
}

void entry(const float tensor_input[1][14], float tensor_output[1][14]) {
    node_Gemm_0(tensor_input, tensor_linear_list_0_weight, tensor_linear_list_0_bias, tu0.tensor_7);
    node_Relu_1(tu0.tensor_7, tu1.tensor_8);
    node_Gemm_2(tu1.tensor_8, tensor_linear_list_1_weight, tensor_linear_list_1_bias, tu0.tensor_9);
    node_Relu_3(tu0.tensor_9, tu1.tensor_10);
    node_Gemm_4(tu1.tensor_10, tensor_linear_list_2_weight, tensor_linear_list_2_bias, tensor_output);
}

int main() {
    float tensor_input[1][14] = {
        {0.0f, 0.3f, -4.2f, 1.2f, 0.5f, -3.8f, 2.0f, -2.5f, 3.1f, -3.9f, 1.1f, -0.2f, 0.9f, 1.7f}
    };
    float tensor_output[1][14];

    // Ensure the bounds would have been respected
    assert(tensor_input[0][0] >= -1.7492930226200185f && tensor_input[0][0] <= 1.7312612073369356f);
  
    entry(tensor_input, tensor_output);

    // Replace verifier assert with standard assert
    assert(!((tensor_output[0][12] <= -2.2838113986655717) && (tensor_output[0][0] >= -0.0)));

    printf("Program executed successfully.\n");

    return 0;
}