#include <stdio.h>
#include <float.h>
#include <math.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

// Define constants
#define MAX(X,Y) ( X > Y ? X : Y)
#define MIN(X,Y) ( X < Y ? X : Y)
#define CLIP(X,L) ( MAX(MIN(X,L), -L) )

// Predefined weights and biases for the neural network (truncating for brevity)
static const float tensor_q_net_0_weight[64][8] = {/*...*/};
static const float tensor_q_net_0_bias[64] = {/*...*/};
static const float tensor_q_net_2_weight[64][64] = {/*...*/};
static const float tensor_q_net_2_bias[64] = {/*...*/};
static const float tensor_q_net_4_weight[4][64] = {/*...*/};
static const float tensor_q_net_4_bias[4] = {/*...*/};

// Function implementations for each node
static void node_Flatten_0(const float tensor_input[1][8], float tensor_7[1][8]) {
    /* Flatten */
    memcpy(tensor_7, tensor_input, sizeof(float) * 8);
}

static void node_Gemm_1(const float tensor_7[1][8], const float tensor_q_net_0_weight[64][8], const float tensor_q_net_0_bias[64], float tensor_8[1][64]) {
    const int M = 1, K = 8, N = 64;
    for (int r = 0; r < M; r++) {
        for (int c = 0; c < N; c++) {
            float sum = tensor_q_net_0_bias[c];
            for (int i = 0; i < K; i++) {
                sum += tensor_7[r][i] * tensor_q_net_0_weight[c][i];
            }
            tensor_8[r][c] = sum > 0 ? sum : 0;
        }
    }
}

static void node_Gemm_3(const float tensor_9[1][64], const float tensor_q_net_2_weight[64][64], const float tensor_q_net_2_bias[64], float tensor_10[1][64]) {
    const int M = 1, K = 64, N = 64;
    for (int r = 0; r < M; r++) {
        for (int c = 0; c < N; c++) {
            float sum = tensor_q_net_2_bias[c];
            for (int i = 0; i < K; i++) {
                sum += tensor_9[r][i] * tensor_q_net_2_weight[c][i];
            }
            tensor_10[r][c] = sum > 0 ? sum : 0;
        }
    }
}

static void node_Gemm_5(const float tensor_11[1][64], const float tensor_q_net_4_weight[4][64], const float tensor_q_net_4_bias[4], float tensor_output[1][4]) {
    const int M = 1, K = 64, N = 4;
    for (int r = 0; r < M; r++) {
        for (int c = 0; c < N; c++) {
            float sum = tensor_q_net_4_bias[c];
            for (int i = 0; i < K; i++) {
                sum += tensor_11[r][i] * tensor_q_net_4_weight[c][i];
            }
            tensor_output[r][c] = sum;
        }
    }
}

// Entry point for the model
void entry(const float tensor_input[1][8], float tensor_output[1][4]) {
    // Intermediate tensors
    float tensor_7[1][8];
    float tensor_8[1][64];
    float tensor_9[1][64];
    float tensor_10[1][64];
    float tensor_11[1][64];

    node_Flatten_0(tensor_input, tensor_7);
    node_Gemm_1(tensor_7, tensor_q_net_0_weight, tensor_q_net_0_bias, tensor_8);
    memcpy(tensor_9, tensor_8, sizeof(tensor_8)); // Relu integrated in node_Gemm_1
    node_Gemm_3(tensor_9, tensor_q_net_2_weight, tensor_q_net_2_bias, tensor_10);
    memcpy(tensor_11, tensor_10, sizeof(tensor_10)); // Relu integrated in node_Gemm_3
    node_Gemm_5(tensor_11, tensor_q_net_4_weight, tensor_q_net_4_bias, tensor_output);
}

int main() {
    // Initialize input and output tensors
    float tensor_input[1][8] = {
        {-0.85f, 0.04f, 0.04f, -0.02f, -0.38f, -0.19f, 1.0f, 1.0f}
    };
    float tensor_output[1][4];

    // Execute the model
    entry(tensor_input, tensor_output);

    // Assert the expected outputs based on fixed input values
    assert(!(tensor_output[0][2] <= tensor_output[0][3]));

    // Print results to verify (for debug purposes)
    for (int i = 0; i < 4; i++) {
        printf("Output[%d]: %f\n", i, tensor_output[0][i]);
    }

    return 0;
}