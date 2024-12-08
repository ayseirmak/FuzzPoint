#include <stdio.h>
#include <assert.h>
#include <float.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

// Essential defines for use in the program
#define MIN(X, Y) ((X) < (Y) ? (X) : (Y))
#define MAX(X, Y) ((X) > (Y) ? (X) : (Y))
#define CLIP(X, L) (MAX(MIN(X, L), -L))

// Prototype for the entry function
void entry(const float tensor_input[1][8], float tensor_output[1][4]);

// Variables for the fully connected layer's weights and biases.
// These should be initialized with talented weight matrices and biases
static const float tensor_q_net_0_weight[64][8] = { /* Initialization here */ };
static const float tensor_q_net_0_bias[64] = { /* Initialization here */ };
static const float tensor_q_net_2_weight[64][64] = { /* Initialization here */ };
static const float tensor_q_net_2_bias[64] = { /* Initialization here */ };
static const float tensor_q_net_4_weight[4][64] = { /* Initialization here */ };
static const float tensor_q_net_4_bias[4] = { /* Initialization here */ };

// Memory unions for tensors used during computation
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

// Function definitions for each node in the ONNX network
static inline void node_Flatten_0(const float tensor_input[1][8], float tensor_7[1][8]) {
    // Flatten operation
    float *input = (float *)tensor_input;
    float *output = (float *)tensor_7;
    for (uint32_t i = 0; i < 8; i++)
        output[i] = input[i];
}

static inline void node_Gemm_1(const float tensor_7[1][8], const float tensor_q_net_0_weight[64][8], const float tensor_q_net_0_bias[64], float tensor_8[1][64]) {
    // Gemm operation
    const int M = 1;
    const int K = 8;
    const int N = 64;
    float (*A)[8] = (float (*)[8])tensor_7;
    float (*Y)[64] = (float (*)[64])tensor_8;
    float alpha = 1.0;
    float beta = 1.0;
    float (*C)[64] = (float (*)[64])tensor_q_net_0_bias;
    for (uint32_t r = 0; r < M; r++) {
        for (uint32_t c = 0; c < N; c++) {
            float ABrc = 0;
            for (uint32_t i = 0; i < K; i++) {
                float B = tensor_q_net_0_weight[c][i];
                ABrc += A[r][i] * B;
            }
            Y[r][c] = (ABrc * alpha) + (C[0][c] * beta);
        }
    }
}

static inline void node_Relu_2(const float tensor_8[1][64], float tensor_9[1][64]) {
    // Relu operation
    float *X = (float *)tensor_8;
    float *Y = (float *)tensor_9;
    for (uint32_t i = 0; i < 64; i++)
        Y[i] = X[i] > 0 ? X[i] : 0;
}

static inline void node_Gemm_3(const float tensor_9[1][64], const float tensor_q_net_2_weight[64][64], const float tensor_q_net_2_bias[64], float tensor_10[1][64]) {
    // Gemm operation
    const int M = 1;
    const int K = 64;
    const int N = 64;
    float (*A)[64] = (float (*)[64])tensor_9;
    float (*Y)[64] = (float (*)[64])tensor_10;
    float alpha = 1.0;
    float beta = 1.0;
    float (*C)[64] = (float (*)[64])tensor_q_net_2_bias;
    for (uint32_t r = 0; r < M; r++) {
        for (uint32_t c = 0; c < N; c++) {
            float ABrc = 0;
            for (uint32_t i = 0; i < K; i++) {
                float B = tensor_q_net_2_weight[c][i];
                ABrc += A[r][i] * B;
            }
            Y[r][c] = (ABrc * alpha) + (C[0][c] * beta);
        }
    }
}

static inline void node_Relu_4(const float tensor_10[1][64], float tensor_11[1][64]) {
    // Relu operation
    float *X = (float *)tensor_10;
    float *Y = (float *)tensor_11;
    for (uint32_t i = 0; i < 64; i++)
        Y[i] = X[i] > 0 ? X[i] : 0;
}

static inline void node_Gemm_5(const float tensor_11[1][64], const float tensor_q_net_4_weight[4][64], const float tensor_q_net_4_bias[4], float tensor_output[1][4]) {
    // Gemm operation
    const int M = 1;
    const int K = 64;
    const int N = 4;
    float (*A)[64] = (float (*)[64])tensor_11;
    float (*Y)[4] = (float (*)[4])tensor_output;
    float alpha = 1.0;
    float beta = 1.0;
    float (*C)[4] = (float (*)[4])tensor_q_net_4_bias;
    for (uint32_t r = 0; r < M; r++) {
        for (uint32_t c = 0; c < N; c++) {
            float ABrc = 0;
            for (uint32_t i = 0; i < K; i++) {
                float B = tensor_q_net_4_weight[c][i];
                ABrc += A[r][i] * B;
            }
            Y[r][c] = (ABrc * alpha) + (C[0][c] * beta);
        }
    }
}

// Main entry point that calls each node function in sequence
void entry(const float tensor_input[1][8], float tensor_output[1][4]) {
    node_Flatten_0(tensor_input, tu0.tensor_7);
    node_Gemm_1(tu0.tensor_7, tensor_q_net_0_weight, tensor_q_net_0_bias, tu1.tensor_8);
    node_Relu_2(tu1.tensor_8, tu0.tensor_9);
    node_Gemm_3(tu0.tensor_9, tensor_q_net_2_weight, tensor_q_net_2_bias, tu1.tensor_10);
    node_Relu_4(tu1.tensor_10, tu0.tensor_11);
    node_Gemm_5(tu0.tensor_11, tensor_q_net_4_weight, tensor_q_net_4_bias, tensor_output);
}

// Main function
int main() {
    // Fixed deterministic input
    float tensor_input[1][8] = {
        {-0.8, 0.01, -0.03, 0.05, 0.05, 0.02, 1.0, 1.0}
    };
    float tensor_output[1][4];
    
    // Run the entry function
    entry(tensor_input, tensor_output);
    
    // Add assertions to verify the output
    assert(!(tensor_output[0][3] <= tensor_output[0][2]));
    
    // Print output for debugging
    for (int i = 0; i < 4; i++) {
        printf("Output[%d]: %f\n", i, tensor_output[0][i]);
    }
    
    return 0;
}