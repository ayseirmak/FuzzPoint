#include <assert.h>
#include <stdio.h>
#include <math.h>
#include <stdint.h>

void entry(const float tensor_input[1][8], float tensor_output[1][4]);

int main()
{
    float tensor_input[1][8];
    float tensor_output[1][4];

    // Assuming the fixed predetermined values based on the assumed ranges
    tensor_input[0][0] = -0.7f;
    tensor_input[0][1] = 0.1f;
    tensor_input[0][2] = 0.01f;
    tensor_input[0][3] = 0.01f;
    tensor_input[0][4] = 0.1f;
    tensor_input[0][5] = -0.01f;
    tensor_input[0][6] = 1.0f;
    tensor_input[0][7] = 1.0f;

    entry(tensor_input, tensor_output);

    // Using standard assert to emulate the verification
    assert(!(tensor_output[0][2] <= tensor_output[0][3]));

    printf("Assertion passed, tensor_output[0][2]: %f, tensor_output[0][3]: %f\n", tensor_output[0][2], tensor_output[0][3]);
    return 0;
}

// ONNX model related definitions

#define MAX(X,Y) ((X) > (Y) ? (X) : (Y))
#define MIN(X,Y) ((X) < (Y) ? (X) : (Y))

static const float tensor_q_net_0_weight[64][8] = {
    // Weight values (64x8) initialization here...
};

static const float tensor_q_net_0_bias[64] = {
    // Bias values initialization here...
};

static const float tensor_q_net_2_weight[64][64] = {
    // Weight values (64x64) initialization here...
};

static const float tensor_q_net_2_bias[64] = {
    // Bias values initialization here...
};

static const float tensor_q_net_4_weight[4][64] = {
    // Weight values (4x64) initialization here...
};

static const float tensor_q_net_4_bias[4] = {
    // Bias values initialization here...
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

// Functions to perform neural network operations
static inline void node_Flatten_0(const float tensor_input[1][8], float tensor_7[1][8]) {
    for (uint32_t i = 0; i < 8; i++)
        tensor_7[0][i] = tensor_input[0][i];
}

static inline void node_Gemm_1(const float tensor_7[1][8], const float tensor_q_net_0_weight[64][8], const float tensor_q_net_0_bias[64], float tensor_8[1][64]) {
    for (uint32_t c = 0; c < 64; c++) {
        float sum = 0.0f;
        for (uint32_t i = 0; i < 8; i++) {
            sum += tensor_7[0][i] * tensor_q_net_0_weight[c][i];
        }
        tensor_8[0][c] = sum + tensor_q_net_0_bias[c];
    }
}

static inline void node_Relu_2(const float tensor_8[1][64], float tensor_9[1][64]) {
    for (uint32_t i = 0; i < 64; i++)
        tensor_9[0][i] = MAX(tensor_8[0][i], 0);
}

static inline void node_Gemm_3(const float tensor_9[1][64], const float tensor_q_net_2_weight[64][64], const float tensor_q_net_2_bias[64], float tensor_10[1][64]) {
    for (uint32_t c = 0; c < 64; c++) {
        float sum = 0.0f;
        for (uint32_t i = 0; i < 64; i++) {
            sum += tensor_9[0][i] * tensor_q_net_2_weight[c][i];
        }
        tensor_10[0][c] = sum + tensor_q_net_2_bias[c];
    }
}

static inline void node_Relu_4(const float tensor_10[1][64], float tensor_11[1][64]) {
    for (uint32_t i = 0; i < 64; i++)
        tensor_11[0][i] = MAX(tensor_10[0][i], 0);
}

static inline void node_Gemm_5(const float tensor_11[1][64], const float tensor_q_net_4_weight[4][64], const float tensor_q_net_4_bias[4], float tensor_output[1][4]) {
    for (uint32_t c = 0; c < 4; c++) {
        float sum = 0.0f;
        for (uint32_t i = 0; i < 64; i++) {
            sum += tensor_11[0][i] * tensor_q_net_4_weight[c][i];
        }
        tensor_output[0][c] = sum + tensor_q_net_4_bias[c];
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