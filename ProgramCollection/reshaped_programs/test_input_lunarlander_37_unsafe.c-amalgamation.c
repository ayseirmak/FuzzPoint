#include <assert.h>
#include <stdio.h>
#include <float.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>

// Constants used within the neural network model
#define MAX(X,Y) ( X > Y ? X : Y)
#define MIN(X,Y) ( X < Y ? X : Y)
#define CLIP(X,L) ( MAX(MIN(X,L), -L) )

// Function declarations
void entry(const float tensor_input[1][8], float tensor_output[1][4]);

// Global arrays used in the neural network
static const float tensor_q_net_0_weight[64][8] = { ... };
static const float tensor_q_net_0_bias[64] = { ... };
static const float tensor_q_net_2_weight[64][64] = { ... };
static const float tensor_q_net_2_bias[64] = { ... };
static const float tensor_q_net_4_weight[4][64] = { ... };
static const float tensor_q_net_4_bias[4] = { ... };

// Union to hold intermediate tensor results
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

// Neural network model functions
static inline void node_Flatten_0(const float tensor_input[1][8], float tensor_7[1][8]) {
    // Flatten the input tensor
    memcpy(tensor_7, tensor_input, sizeof(float) * 8);
}

static inline void node_Gemm_1(const float tensor_7[1][8], const float tensor_q_net_0_weight[64][8], const float tensor_q_net_0_bias[64], float tensor_8[1][64]) {
    // Matrix multiplication and bias addition
    for (uint32_t c = 0; c < 64; c++) {
        float sum = tensor_q_net_0_bias[c];
        for (uint32_t i = 0; i < 8; i++) {
            sum += tensor_7[0][i] * tensor_q_net_0_weight[c][i];
        }
        tensor_8[0][c] = sum;
    }
}

static inline void node_Relu_2(const float tensor_8[1][64], float tensor_9[1][64]) {
    // ReLU activation function
    for (uint32_t i = 0; i < 64; i++) {
        tensor_9[0][i] = fmax(0, tensor_8[0][i]);
    }
}

static inline void node_Gemm_3(const float tensor_9[1][64], const float tensor_q_net_2_weight[64][64], const float tensor_q_net_2_bias[64], float tensor_10[1][64]) {
    // Matrix multiplication and bias addition
    for (uint32_t c = 0; c < 64; c++) {
        float sum = tensor_q_net_2_bias[c];
        for (uint32_t i = 0; i < 64; i++) {
            sum += tensor_9[0][i] * tensor_q_net_2_weight[c][i];
        }
        tensor_10[0][c] = sum;
    }
}

static inline void node_Relu_4(const float tensor_10[1][64], float tensor_11[1][64]) {
    // ReLU activation function
    for (uint32_t i = 0; i < 64; i++) {
        tensor_11[0][i] = fmax(0, tensor_10[0][i]);
    }
}

static inline void node_Gemm_5(const float tensor_11[1][64], const float tensor_q_net_4_weight[4][64], const float tensor_q_net_4_bias[4], float tensor_output[1][4]) {
    // Matrix multiplication and bias addition
    for (uint32_t c = 0; c < 4; c++) {
        float sum = tensor_q_net_4_bias[c];
        for (uint32_t i = 0; i < 64; i++) {
            sum += tensor_11[0][i] * tensor_q_net_4_weight[c][i];
        }
        tensor_output[0][c] = sum;
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
        {-0.88f, 0.05f, 0.05f, -0.05f, -0.11f, -0.18f, 1.00f, 1.00f}
    };
    float tensor_output[1][4];

    entry(tensor_input, tensor_output);

    assert(!(tensor_output[0][2] <= tensor_output[0][3]));

    return 0;
}