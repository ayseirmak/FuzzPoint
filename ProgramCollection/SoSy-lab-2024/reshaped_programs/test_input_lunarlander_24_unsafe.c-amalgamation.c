#include <stdio.h>
#include <assert.h>
#include <stdint.h>

// Determine the size of these arrays based on your actual model
#define TENSOR_Q_NET_0_WEIGHT_SIZE 64
#define TENSOR_Q_NET_0_WEIGHT_SUBSIZE 8
#define TENSOR_Q_NET_2_WEIGHT_SIZE 64
#define TENSOR_Q_NET_2_BIAS_SIZE 64
#define TENSOR_Q_NET_4_WEIGHT_SIZE 4
#define TENSOR_Q_NET_4_BIAS_SIZE 4

// Pre-defined model weights and biases (truncated for brevity)
static const float tensor_q_net_0_weight[TENSOR_Q_NET_0_WEIGHT_SIZE][TENSOR_Q_NET_0_WEIGHT_SUBSIZE] = { /* ... */ };
static const float tensor_q_net_0_bias[TENSOR_Q_NET_0_WEIGHT_SIZE] = { /* ... */ };
static const float tensor_q_net_2_weight[TENSOR_Q_NET_2_WEIGHT_SIZE][TENSOR_Q_NET_2_WEIGHT_SIZE] = { /* ... */ };
static const float tensor_q_net_2_bias[TENSOR_Q_NET_2_BIAS_SIZE] = { /* ... */ };
static const float tensor_q_net_4_weight[TENSOR_Q_NET_4_WEIGHT_SIZE][TENSOR_Q_NET_2_WEIGHT_SIZE] = { /* ... */ };
static const float tensor_q_net_4_bias[TENSOR_Q_NET_4_BIAS_SIZE] = { /* ... */ };

typedef union tensor_union_0_t {
    float tensor_7[1][8];
    float tensor_9[1][64];
    float tensor_11[1][64];
} tensor_union_0_t;

typedef union tensor_union_1_t {
    float tensor_8[1][64];
    float tensor_10[1][64];
} tensor_union_1_t;

void node_Flatten_0(const float tensor_input[1][8], float tensor_7[1][8]) {
    for (uint32_t i = 0; i < 8; i++)
        tensor_7[0][i] = tensor_input[0][i];
}

void node_Gemm_1(const float tensor_7[1][8], const float tensor_q_net_0_weight[64][8], const float tensor_q_net_0_bias[64], float tensor_8[1][64]) {
    for (uint32_t r = 0; r < 1; r++)
        for (uint32_t c = 0; c < 64; c++) {
            float ABrc = 0;
            for (uint32_t i = 0; i < 8; i++) 
                ABrc += tensor_7[r][i] * tensor_q_net_0_weight[c][i];
            tensor_8[r][c] = ABrc + tensor_q_net_0_bias[c];
        }
}

void node_Relu_2(const float tensor_8[1][64], float tensor_9[1][64]) {
    for (uint32_t i = 0; i < 64; i++)
        tensor_9[0][i] = tensor_8[0][i] > 0 ? tensor_8[0][i] : 0;
}

void node_Gemm_3(const float tensor_9[1][64], const float tensor_q_net_2_weight[64][64], const float tensor_q_net_2_bias[64], float tensor_10[1][64]) {
    for (uint32_t r = 0; r < 1; r++)
        for (uint32_t c = 0; c < 64; c++) {
            float ABrc = 0;
            for (uint32_t i = 0; i < 64; i++)
                ABrc += tensor_9[r][i] * tensor_q_net_2_weight[c][i];
            tensor_10[r][c] = ABrc + tensor_q_net_2_bias[c];
        }
}

void node_Relu_4(const float tensor_10[1][64], float tensor_11[1][64]) {
    for (uint32_t i = 0; i < 64; i++)
        tensor_11[0][i] = tensor_10[0][i] > 0 ? tensor_10[0][i] : 0;
}

void node_Gemm_5(const float tensor_11[1][64], const float tensor_q_net_4_weight[4][64], const float tensor_q_net_4_bias[4], float tensor_output[1][4]) {
    for (uint32_t r = 0; r < 1; r++)
        for (uint32_t c = 0; c < 4; c++) {
            float ABrc = 0;
            for (uint32_t i = 0; i < 64; i++)
                ABrc += tensor_11[r][i] * tensor_q_net_4_weight[c][i];
            tensor_output[r][c] = ABrc + tensor_q_net_4_bias[c];
        }
}

void entry(const float tensor_input[1][8], float tensor_output[1][4]) {
    tensor_union_0_t tu0;
    tensor_union_1_t tu1;

    node_Flatten_0(tensor_input, tu0.tensor_7);
    node_Gemm_1(tu0.tensor_7, tensor_q_net_0_weight, tensor_q_net_0_bias, tu1.tensor_8);
    node_Relu_2(tu1.tensor_8, tu0.tensor_9);
    node_Gemm_3(tu0.tensor_9, tensor_q_net_2_weight, tensor_q_net_2_bias, tu1.tensor_10);
    node_Relu_4(tu1.tensor_10, tu0.tensor_11);
    node_Gemm_5(tu0.tensor_11, tensor_q_net_4_weight, tensor_q_net_4_bias, tensor_output);
}

int main() {
    float tensor_input[1][8] = {
        {-0.78644f, 0.04545f, 0.02332f, -0.05123f, -0.02623f, -0.06504f, 1.000f, 1.000f}
    };
    
    float tensor_output[1][4] = {0};

    entry(tensor_input, tensor_output);

    assert(!(tensor_output[0][2] <= tensor_output[0][3]));

    for (int i = 0; i < 4; i++) {
        printf("tensor_output[0][%d] = %f\n", i, tensor_output[0][i]);
    }

    return 0;
}