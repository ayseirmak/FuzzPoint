#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include <stdbool.h>

// Function prototypes
void entry(const float tensor_input[1][4], float tensor_output[1][2]);

// Tensor weight and bias arrays are defined here (as per your provided data)

// Given hypothetical weights and biases
static const float tensor_q_net_0_weight[64][4] = {/*...*/};  // fill with actual values
static const float tensor_q_net_0_bias[64] = {/*...*/};       // fill with actual values
static const float tensor_q_net_2_weight[64][64] = {/*...*/}; // fill with actual values
static const float tensor_q_net_2_bias[64] = {/*...*/};       // fill with actual values
static const float tensor_q_net_4_weight[2][64] = {/*...*/};  // fill with actual values
static const float tensor_q_net_4_bias[2] = {/*...*/};        // fill with actual values

union tensor_union_0 {
    float tensor_7[1][4];
    float tensor_9[1][64];
    float tensor_11[1][64];
};
static union tensor_union_0 tu0;

union tensor_union_1 {
    float tensor_8[1][64];
    float tensor_10[1][64];
};
static union tensor_union_1 tu1;

static inline void node_Flatten_0(const float tensor_input[1][4], float tensor_7[1][4])
{
    for (uint32_t i = 0; i < 4; i++)
        tensor_7[0][i] = tensor_input[0][i];
}

static inline void node_Gemm_1(const float tensor_7[1][4], const float tensor_q_net_0_weight[64][4], const float tensor_q_net_0_bias[64], float tensor_8[1][64])
{
    for (uint32_t c = 0; c < 64; c++) {
        float sum = 0.0f;
        for (uint32_t i = 0; i < 4; i++) {
            sum += tensor_7[0][i] * tensor_q_net_0_weight[c][i];
        }
        tensor_8[0][c] = sum + tensor_q_net_0_bias[c];
    }
}

static inline void node_Relu_2(const float tensor_8[1][64], float tensor_9[1][64])
{
    for (uint32_t i = 0; i < 64; i++)
        tensor_9[0][i] = (tensor_8[0][i] > 0) ? tensor_8[0][i] : 0;
}

static inline void node_Gemm_3(const float tensor_9[1][64], const float tensor_q_net_2_weight[64][64], const float tensor_q_net_2_bias[64], float tensor_10[1][64])
{
    for (uint32_t c = 0; c < 64; c++) {
        float sum = 0.0f;
        for (uint32_t i = 0; i < 64; i++) {
            sum += tensor_9[0][i] * tensor_q_net_2_weight[c][i];
        }
        tensor_10[0][c] = sum + tensor_q_net_2_bias[c];
    }
}

static inline void node_Relu_4(const float tensor_10[1][64], float tensor_11[1][64])
{
    for (uint32_t i = 0; i < 64; i++)
        tensor_11[0][i] = (tensor_10[0][i] > 0) ? tensor_10[0][i] : 0;
}

static inline void node_Gemm_5(const float tensor_11[1][64], const float tensor_q_net_4_weight[2][64], const float tensor_q_net_4_bias[2], float tensor_output[1][2])
{
    for (uint32_t c = 0; c < 2; c++) {
        float sum = 0.0f;
        for (uint32_t i = 0; i < 64; i++) {
            sum += tensor_11[0][i] * tensor_q_net_4_weight[c][i];
        }
        tensor_output[0][c] = sum + tensor_q_net_4_bias[c];
    }
}

void entry(const float tensor_input[1][4], float tensor_output[1][2]) {
    node_Flatten_0(tensor_input, tu0.tensor_7);
    node_Gemm_1(tu0.tensor_7, tensor_q_net_0_weight, tensor_q_net_0_bias, tu1.tensor_8);
    node_Relu_2(tu1.tensor_8, tu0.tensor_9);
    node_Gemm_3(tu0.tensor_9, tensor_q_net_2_weight, tensor_q_net_2_bias, tu1.tensor_10);
    node_Relu_4(tu1.tensor_10, tu0.tensor_11);
    node_Gemm_5(tu0.tensor_11, tensor_q_net_4_weight, tensor_q_net_4_bias, tensor_output);
}

int main() {
    float tensor_input[1][4] = {{-0.243f, -0.246f, -0.072f, -0.071f}};
    float tensor_output[1][2];

    entry(tensor_input, tensor_output);

    // Assertions for deterministic behavior
    assert(!(tensor_output[0][0] <= tensor_output[0][1]));

    printf("Output: [%f, %f]\n", tensor_output[0][0], tensor_output[0][1]);
    return 0;
}