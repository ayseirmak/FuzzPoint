#include <stdio.h>
#include <math.h>
#include <assert.h>

void entry(const float tensor_input[1][8], float tensor_output[1][4]);

int main() {
    // Initialize input tensor with deterministic values
    float tensor_input[1][8] = {
        {-0.6f, 0.1f, -0.05f, 0.05f, 0.1f, 0.15f, 1.0f, 1.0f}
    };
    float tensor_output[1][4];

    entry(tensor_input, tensor_output);

    // Check the assertion condition
    assert(!(tensor_output[0][3] <= tensor_output[0][2]));

    // Print tensor_output for verification
    for (int i = 0; i < 4; i++) {
        printf("tensor_output[0][%d] = %f\n", i, tensor_output[0][i]);
    }

    return 0;
}

#include <float.h>
#include <stdint.h>
#include <string.h>

#define MAX(X,Y) ((X) > (Y) ? (X) : (Y))
#define MIN(X,Y) ((X) < (Y) ? (X) : (Y))

static const float tensor_q_net_0_weight[64][8] = {
    // (Matrix initialization here...)
};

static const float tensor_q_net_0_bias[64] = {
    // (Vector initialization here...)
};

static const float tensor_q_net_2_weight[64][64] = {
    // (Matrix initialization here...)
};

static const float tensor_q_net_2_bias[64] = {
    // (Vector initialization here...)
};

static const float tensor_q_net_4_weight[4][64] = {
    // (Matrix initialization here...)
};

static const float tensor_q_net_4_bias[4] = {
    // (Vector initialization here...)
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

static inline void node_Flatten_0(const float tensor_input[1][8], float tensor_7[1][8]) {
    float *input = (float*) tensor_input;
    float *output = (float*) tensor_7;
    for (uint32_t i = 0; i < 8; i++)
        output[i] = input[i];
}

static inline void node_Gemm_1(const float tensor_7[1][8], const float tensor_q_net_0_weight[64][8], const float tensor_q_net_0_bias[64], float tensor_8[1][64]) {
    // Matrix-vector multiplication with bias
    for (int i = 0; i < 64; i++) {
        tensor_8[0][i] = tensor_q_net_0_bias[i];
        for (int j = 0; j < 8; j++) {
            tensor_8[0][i] += tensor_7[0][j] * tensor_q_net_0_weight[i][j];
        }
    }
}

static inline void node_Relu_2(const float tensor_8[1][64], float tensor_9[1][64]) {
    for (int i = 0; i < 64; i++) {
        tensor_9[0][i] = MAX(0, tensor_8[0][i]);
    }
}

static inline void node_Gemm_3(const float tensor_9[1][64], const float tensor_q_net_2_weight[64][64], const float tensor_q_net_2_bias[64], float tensor_10[1][64]) {
    // Matrix-vector multiplication with bias
    for (int i = 0; i < 64; i++) {
        tensor_10[0][i] = tensor_q_net_2_bias[i];
        for (int j = 0; j < 64; j++) {
            tensor_10[0][i] += tensor_9[0][j] * tensor_q_net_2_weight[i][j];
        }
    }
}

static inline void node_Relu_4(const float tensor_10[1][64], float tensor_11[1][64]) {
    for (int i = 0; i < 64; i++) {
        tensor_11[0][i] = MAX(0, tensor_10[0][i]);
    }
}

static inline void node_Gemm_5(const float tensor_11[1][64], const float tensor_q_net_4_weight[4][64], const float tensor_q_net_4_bias[4], float tensor_output[1][4]) {
    // Matrix-vector multiplication with bias
    for (int i = 0; i < 4; i++) {
        tensor_output[0][i] = tensor_q_net_4_bias[i];
        for (int j = 0; j < 64; j++) {
            tensor_output[0][i] += tensor_11[0][j] * tensor_q_net_4_weight[i][j];
        }
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