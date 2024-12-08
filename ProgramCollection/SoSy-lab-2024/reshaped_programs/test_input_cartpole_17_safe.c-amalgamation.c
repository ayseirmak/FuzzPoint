#include <assert.h>
#include <stdio.h>
#include <float.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

// Define the custom MAX, MIN, and CLIP macros
#define MAX(X, Y) ((X > Y) ? X : Y)
#define MIN(X, Y) ((X < Y) ? X : Y)
#define CLIP(X, L) (MAX(MIN(X, L), -L))

// Predefined variables and parameters
static const float tensor_q_net_0_weight[64][4] = {/*... populated with predefined values ...*/};
static const float tensor_q_net_0_bias[64] = {/*... populated with predefined values ...*/};
static const float tensor_q_net_2_weight[64][64] = {/*... populated with predefined values ...*/};
static const float tensor_q_net_2_bias[64] = {/*... populated with predefined values ...*/};
static const float tensor_q_net_4_weight[2][64] = {/*... populated with predefined values ...*/};
static const float tensor_q_net_4_bias[2] = {/*... populated with predefined values ...*/};

// Unions to hold intermediate tensor states
union tensor_union_0 {
    float tensor_7[1][4];
    float tensor_9[1][64];
    float tensor_11[1][64];
};

union tensor_union_1 {
    float tensor_8[1][64];
    float tensor_10[1][64];
};

// Declare the custom unions as static
static union tensor_union_0 tu0;
static union tensor_union_1 tu1;


// Function Definitions

static inline void node_Flatten_0(const float tensor_input[1][4], float tensor_7[1][4]) {
    // Flatten tensor_input into tensor_7
    float *input = (float *)tensor_input;
    float *output = (float *)tensor_7;
    for (uint32_t i = 0; i < 4; i++) {
        output[i] = input[i];
    }
}

static inline void node_Gemm_1(const float tensor_7[1][4], const float tensor_q_net_0_weight[64][4], const float tensor_q_net_0_bias[64], float tensor_8[1][64]) {
    // Implement a Gemm operation to compute tensor_8 using the flattened input
    const int M = 1, K = 4, N = 64;
    const float alpha = 1.0f, beta = 1.0f;
    float (*A)[4] = (float(*)[4])tensor_7;
    float (*Y)[64] = (float(*)[64])tensor_8;
    float (*C)[64] = (float(*)[64])tensor_q_net_0_bias;

    for (uint32_t r = 0; r < M; r++) {
        for (uint32_t c = 0; c < N; c++) {
            float ABrc = 0;
            for (uint32_t i = 0; i < K; i++) {
                float B = tensor_q_net_0_weight[c][i];
                ABrc += A[r][i] * B;
            }
            // Apply alpha, beta correction
            float tmp = ABrc * alpha;
            tmp += C[0][c] * beta;
            Y[r][c] = tmp;
        }
    }
}

static inline void node_Relu_2(const float tensor_8[1][64], float tensor_9[1][64]) {
    // Apply ReLU activation function
    float *X = (float *)tensor_8;
    float *Y = (float *)tensor_9;
    for (uint32_t i = 0; i < 64; i++) {
        Y[i] = X[i] > 0 ? X[i] : 0;
    }
}

static inline void node_Gemm_3(const float tensor_9[1][64], const float tensor_q_net_2_weight[64][64], const float tensor_q_net_2_bias[64], float tensor_10[1][64]) {
    // Apply another Gemm operation
    const int M = 1, K = 64, N = 64;
    const float alpha = 1.0f, beta = 1.0f;
    float (*A)[64] = (float(*)[64])tensor_9;
    float (*Y)[64] = (float(*)[64])tensor_10;
    float (*C)[64] = (float(*)[64])tensor_q_net_2_bias;

    for (uint32_t r = 0; r < M; r++) {
        for (uint32_t c = 0; c < N; c++) {
            float ABrc = 0;
            for (uint32_t i = 0; i < K; i++) {
                float B = tensor_q_net_2_weight[c][i];
                ABrc += A[r][i] * B;
            }
            // Apply alpha, beta correction
            float tmp = ABrc * alpha;
            tmp += C[0][c] * beta;
            Y[r][c] = tmp;
        }
    }
}

static inline void node_Relu_4(const float tensor_10[1][64], float tensor_11[1][64]) {
    // Apply ReLU activation function
    float *X = (float *)tensor_10;
    float *Y = (float *)tensor_11;
    for (uint32_t i = 0; i < 64; i++) {
        Y[i] = X[i] > 0 ? X[i] : 0;
    }
}

static inline void node_Gemm_5(const float tensor_11[1][64], const float tensor_q_net_4_weight[2][64], const float tensor_q_net_4_bias[2], float tensor_output[1][2]) {
    // Perform final Gemm operation to produce output
    const int M = 1, K = 64, N = 2;
    const float alpha = 1.0f, beta = 1.0f;
    float (*A)[64] = (float(*)[64])tensor_11;
    float (*Y)[2] = (float(*)[2])tensor_output;
    float (*C)[2] = (float(*)[2])tensor_q_net_4_bias;

    for (uint32_t r = 0; r < M; r++) {
        for (uint32_t c = 0; c < N; c++) {
            float ABrc = 0;
            for (uint32_t i = 0; i < K; i++) {
                float B = tensor_q_net_4_weight[c][i];
                ABrc += A[r][i] * B;
            }
            // Apply alpha, beta correction
            float tmp = ABrc * alpha;
            tmp += C[0][c] * beta;
            Y[r][c] = tmp;
        }
    }
}

// Main entry function
void entry(const float tensor_input[1][4], float tensor_output[1][2]) {
    node_Flatten_0(tensor_input, tu0.tensor_7);
    node_Gemm_1(tu0.tensor_7, tensor_q_net_0_weight, tensor_q_net_0_bias, tu1.tensor_8);
    node_Relu_2(tu1.tensor_8, tu0.tensor_9);
    node_Gemm_3(tu0.tensor_9, tensor_q_net_2_weight, tensor_q_net_2_bias, tu1.tensor_10);
    node_Relu_4(tu1.tensor_10, tu0.tensor_11);
    node_Gemm_5(tu0.tensor_11, tensor_q_net_4_weight, tensor_q_net_4_bias, tensor_output);
}

// Modifying the main function to adhere to the project standards and provide a fixed input
int main() {
    // Declare and initialize input and output tensors
    float tensor_input[1][4] = {{0.05f, 0.39f, -0.08f, -0.65f}};
    float tensor_output[1][2];

    // Call the entry function
    entry(tensor_input, tensor_output);

    // Output the results
    printf("tensor_output[0][0]: %f, tensor_output[0][1]: %f\n", tensor_output[0][0], tensor_output[0][1]);

    // Assert that the first output is greater than the second
    assert(tensor_output[0][0] > tensor_output[0][1]);

    return 0;
}