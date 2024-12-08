#include <stdio.h>
#include <math.h>
#include <stdint.h>
#include <stdbool.h>
#include <assert.h>

// Function Declarations
void entry(const float tensor_input[1][8], float tensor_output[1][4]);

// Global tensor weights and biases (shortened here for brevity; please fill with the complete data from the original program)
static const float tensor_q_net_0_weight[64][8] = {/* ... fill with original data ... */};
static const float tensor_q_net_0_bias[64] = {/* ... fill with original data ... */};
static const float tensor_q_net_2_weight[64][64] = {/* ... fill with original data ... */};
static const float tensor_q_net_2_bias[64] = {/* ... fill with original data ... */};
static const float tensor_q_net_4_weight[4][64] = {/* ... fill with original data ... */};
static const float tensor_q_net_4_bias[4] = {/* ... fill with original data ... */};

// Function Definitions
static inline void node_Flatten_0(const float tensor_input[1][8], float tensor_7[1][8]) {
    for (uint32_t i = 0; i < 8; i++)
        tensor_7[0][i] = tensor_input[0][i];
}

static inline void node_Gemm_1(const float tensor_7[1][8], const float tensor_q_net_0_weight[64][8], const float tensor_q_net_0_bias[64], float tensor_8[1][64]) {
    for (uint32_t c = 0; c < 64; c++) {
        float result = tensor_q_net_0_bias[c];
        for (uint32_t i = 0; i < 8; i++) {
            result += tensor_7[0][i] * tensor_q_net_0_weight[c][i];
        }
        tensor_8[0][c] = result;
    }
}

static inline void node_Relu_2(const float tensor_8[1][64], float tensor_9[1][64]) {
    for (uint32_t i = 0; i < 64; i++)
        tensor_9[0][i] = fmax(tensor_8[0][i], 0);
}

static inline void node_Gemm_3(const float tensor_9[1][64], const float tensor_q_net_2_weight[64][64], const float tensor_q_net_2_bias[64], float tensor_10[1][64]) {
    for (uint32_t c = 0; c < 64; c++) {
        float result = tensor_q_net_2_bias[c];
        for (uint32_t i = 0; i < 64; i++) {
            result += tensor_9[0][i] * tensor_q_net_2_weight[c][i];
        }
        tensor_10[0][c] = result;
    }
}

static inline void node_Relu_4(const float tensor_10[1][64], float tensor_11[1][64]) {
    for (uint32_t i = 0; i < 64; i++)
        tensor_11[0][i] = fmax(tensor_10[0][i], 0);
}

static inline void node_Gemm_5(const float tensor_11[1][64], const float tensor_q_net_4_weight[4][64], const float tensor_q_net_4_bias[4], float tensor_output[1][4]) {
    for (uint32_t c = 0; c < 4; c++) {
        float result = tensor_q_net_4_bias[c];
        for (uint32_t i = 0; i < 64; i++) {
            result += tensor_11[0][i] * tensor_q_net_4_weight[c][i];
        }
        tensor_output[0][c] = result;
    }
}

void entry(const float tensor_input[1][8], float tensor_output[1][4]) {
    float tensor_7[1][8];
    float tensor_8[1][64];
    float tensor_9[1][64];
    float tensor_10[1][64];
    float tensor_11[1][64];

    node_Flatten_0(tensor_input, tensor_7);
    node_Gemm_1(tensor_7, tensor_q_net_0_weight, tensor_q_net_0_bias, tensor_8);
    node_Relu_2(tensor_8, tensor_9);
    node_Gemm_3(tensor_9, tensor_q_net_2_weight, tensor_q_net_2_bias, tensor_10);
    node_Relu_4(tensor_10, tensor_11);
    node_Gemm_5(tensor_11, tensor_q_net_4_weight, tensor_q_net_4_bias, tensor_output);
}

int main() {
    float tensor_input[1][8] = {
        {-0.72f, 0.03f, 0.03f, -0.05f, 0.03f, -0.08f, 1.0f, 1.0f}
    };
    float tensor_output[1][4];
    entry(tensor_input, tensor_output);

    printf("Output values:\n");
    for (int i = 0; i < 4; i++) {
        printf("%f ", tensor_output[0][i]);
    }
    printf("\n");

    assert(!(tensor_output[0][2] <= tensor_output[0][3]));

    return 0;
}