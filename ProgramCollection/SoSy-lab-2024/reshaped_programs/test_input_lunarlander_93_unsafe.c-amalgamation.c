#include <stdio.h>
#include <float.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <assert.h>

// Define constants based on the code provided
static const float tensor_q_net_0_weight[64][8] = {
    // matrix data for the given problem
};

static const float tensor_q_net_0_bias[64] = {
    // bias vector for the given problem
};

static const float tensor_q_net_2_weight[64][64] = {
    // second neural network weights
};

static const float tensor_q_net_2_bias[64] = {
    // second neural network bias
};

static const float tensor_q_net_4_weight[4][64] = {
    // third neural network weights
};

static const float tensor_q_net_4_bias[4] = {
    // third neural network bias
};

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

// Flatten operation
static inline void node_Flatten_0(const float tensor_input[1][8], float tensor_7[1][8]) {
    for (uint32_t i = 0; i < 8; i++) {
        tensor_7[0][i] = tensor_input[0][i];
    }
}

// Gemm operation
static inline void node_Gemm(const float *input, const float *weights, const float *bias, float *output, int M, int N, int K) {
    for (int r = 0; r < M; r++) {
        for (int c = 0; c < N; c++) {
            float sum = 0;
            for (int k = 0; k < K; k++) {
                sum += input[r * K + k] * weights[c * K + k];
            }
            output[r * N + c] = sum + bias[c];
        }
    }
}

// ReLU operation
static inline void node_Relu(float *input, float *output, int size) {
    for (int i = 0; i < size; i++) {
        output[i] = fmaxf(input[i], 0);
    }
}

void entry(const float tensor_input[1][8], float tensor_output[1][4]) {
    node_Flatten_0(tensor_input, tu0.tensor_7);
    node_Gemm(&tu0.tensor_7[0][0], &tensor_q_net_0_weight[0][0], &tensor_q_net_0_bias[0], &tu1.tensor_8[0][0], 1, 64, 8);
    node_Relu(&tu1.tensor_8[0][0], &tu0.tensor_9[0][0], 64);
    node_Gemm(&tu0.tensor_9[0][0], &tensor_q_net_2_weight[0][0], &tensor_q_net_2_bias[0], &tu1.tensor_10[0][0], 1, 64, 64);
    node_Relu(&tu1.tensor_10[0][0], &tu0.tensor_11[0][0], 64);
    node_Gemm(&tu0.tensor_11[0][0], &tensor_q_net_4_weight[0][0], &tensor_q_net_4_bias[0], &tensor_output[0][0], 1, 4, 64);
}

int main() {
    float tensor_input[1][8] = {
        {-0.7864, 0.0460, 0.0226, -0.0447, 0.0656, -0.0555, 1.0, 1.0}
    };
    float tensor_output[1][4];

    entry(tensor_input, tensor_output);

    assert(!(tensor_output[0][2] <= tensor_output[0][3]));

    printf("Assertions passed.\n");

    return 0;
}