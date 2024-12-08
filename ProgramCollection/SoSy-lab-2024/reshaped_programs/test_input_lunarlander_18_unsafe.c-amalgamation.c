#include <stdio.h>
#include <float.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <assert.h>  // Include assert for verifying assertions

// Define macros
#define MAX(X,Y) ((X) > (Y) ? (X) : (Y))
#define MIN(X,Y) ((X) < (Y) ? (X) : (Y))
#define CLIP(X,L) (MAX(MIN(X,L), -L))

// Predefined weights and biases
static const float tensor_q_net_0_weight[64][8] = { /* Initialize with existing values */ };
static const float tensor_q_net_0_bias[64] = { /* Initialize with existing values */ };
static const float tensor_q_net_2_weight[64][64] = { /* Initialize with existing values */ };
static const float tensor_q_net_2_bias[64] = { /* Initialize with existing values */ };
static const float tensor_q_net_4_weight[4][64] = { /* Initialize with existing values */ };
static const float tensor_q_net_4_bias[4] = { /* Initialize with existing values */ };

// Global tensor structure
union tensor_union {
    float tensor_7[1][8];
    float tensor_9[1][64];
    float tensor_11[1][64];
    float tensor_8[1][64];
    float tensor_10[1][64];
} tu;

// Function for flatten operation
void node_Flatten_0(const float tensor_input[1][8], float tensor_7[1][8]) {
    float *input = (float *)tensor_input;
    float *output = (float *)tensor_7;
    for (uint32_t i = 0; i < 8; i++)
        output[i] = input[i];
}

// Function for Gemm operation (Matrix multiplication and bias addition)
void node_Gemm(const float *input, const float *weight, const float *bias, float *output, int M, int K, int N) {
    for (uint32_t r = 0; r < M; r++) {
        for (uint32_t c = 0; c < N; c++) {
            float sum = 0;
            for (uint32_t i = 0; i < K; i++) {
                sum += input[r * K + i] * weight[c * K + i];
            }
            output[r * N + c] = sum + bias[c];
        }
    }
}

// Function for ReLU activation
void node_Relu(const float *input, float *output, int size) {
    for (uint32_t i = 0; i < size; i++) {
        output[i] = input[i] > 0 ? input[i] : 0;
    }
}

// Entry function representing the neural network forward pass
void entry(const float tensor_input[1][8], float tensor_output[1][4]) {
    node_Flatten_0(tensor_input, tu.tensor_7);

    node_Gemm((float *)tu.tensor_7, (float *)tensor_q_net_0_weight, tensor_q_net_0_bias, (float *)tu.tensor_8, 1, 8, 64);
    node_Relu((float *)tu.tensor_8, (float *)tu.tensor_9, 64);

    node_Gemm((float *)tu.tensor_9, (float *)tensor_q_net_2_weight, tensor_q_net_2_bias, (float *)tu.tensor_10, 1, 64, 64);
    node_Relu((float *)tu.tensor_10, (float *)tu.tensor_11, 64);

    node_Gemm((float *)tu.tensor_11, (float *)tensor_q_net_4_weight, tensor_q_net_4_bias, (float *)tensor_output, 1, 64, 4);
}

int main() {
    float tensor_input[1][8] = {
        {0.0f, 0.2f, 0.7f, 0.15f, -0.01f, -0.15f, 0.05f, -0.02f} // Fixed deterministic input values
    };
    float tensor_output[1][4];
    
    entry(tensor_input, tensor_output);
    
    // Assertion to check neural network condition
    assert(!(tensor_output[0][3] <= tensor_output[0][0]));
    printf("Assertion passed, the output condition is satisfied.\n");

    return 0;
}