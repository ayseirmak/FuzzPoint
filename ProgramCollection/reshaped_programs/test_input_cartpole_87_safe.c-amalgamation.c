#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <math.h>
#include <assert.h>

// Original model weights and biases
static const float tensor_q_net_0_weight[64][4] = {/* ... Initialize with the same values ... */};
static const float tensor_q_net_0_bias[64] = {/* ... Initialize with the same values ... */};
static const float tensor_q_net_2_weight[64][64] = {/* ... Initialize with the same values ... */};
static const float tensor_q_net_2_bias[64] = {/* ... Initialize with the same values ... */};
static const float tensor_q_net_4_weight[2][64] = {/* ... Initialize with the same values ... */};
static const float tensor_q_net_4_bias[2] = {/* ... Initialize with the same values ... */};

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
    /* Flatten */
    float *input = (float*)tensor_input;
    float *output = (float*)tensor_7;
    for (uint32_t i = 0; i < 4; i++)
        output[i] = input[i];
}

static inline void node_Gemm_1(const float tensor_7[1][4], const float tensor_q_net_0_weight[64][4], const float tensor_q_net_0_bias[64], float tensor_8[1][64])
{
    /* Gemm */
    const int M = 1;
    const int K = 4;
    const int N = 64;
    float alpha = 1.0f;
    float beta = 1.0f;
    for (uint32_t r = 0; r < M; r++)
        for (uint32_t c = 0; c < N; c++) {
            float ABrc = 0;
            for (uint32_t i = 0; i < K; i++) {
                float B = tensor_q_net_0_weight[c][i];
                ABrc += tensor_7[r][i] * B;
            }
            float tmp = ABrc * alpha + tensor_q_net_0_bias[c] * beta;
            tensor_8[r][c] = tmp;
        }
}

static inline void node_Relu_2(const float tensor_8[1][64], float tensor_9[1][64])
{
    /* Relu */
    float *X = (float*)tensor_8;
    float *Y = (float*)tensor_9;
    for (uint32_t i = 0; i < 64; i++)
        Y[i] = X[i] > 0 ? X[i] : 0;
}

static inline void node_Gemm_3(const float tensor_9[1][64], const float tensor_q_net_2_weight[64][64], const float tensor_q_net_2_bias[64], float tensor_10[1][64])
{
    /* Gemm */
    const int M = 1;
    const int K = 64;
    const int N = 64;
    float alpha = 1.0f;
    float beta = 1.0f;
    for (uint32_t r = 0; r < M; r++)
        for (uint32_t c = 0; c < N; c++) {
            float ABrc = 0;
            for (uint32_t i = 0; i < K; i++) {
                float B = tensor_q_net_2_weight[c][i];
                ABrc += tensor_9[r][i] * B;
            }
            float tmp = ABrc * alpha + tensor_q_net_2_bias[c] * beta;
            tensor_10[r][c] = tmp;
        }
}

static inline void node_Relu_4(const float tensor_10[1][64], float tensor_11[1][64])
{
    /* Relu */
    float *X = (float*)tensor_10;
    float *Y = (float*)tensor_11;
    for (uint32_t i = 0; i < 64; i++)
        Y[i] = X[i] > 0 ? X[i] : 0;
}

static inline void node_Gemm_5(const float tensor_11[1][64], const float tensor_q_net_4_weight[2][64], const float tensor_q_net_4_bias[2], float tensor_output[1][2])
{
    /* Gemm */
    const int M = 1;
    const int K = 64;
    const int N = 2;
    float alpha = 1.0f;
    float beta = 1.0f;
    for (uint32_t r = 0; r < M; r++)
        for (uint32_t c = 0; c < N; c++) {
            float ABrc = 0;
            for (uint32_t i = 0; i < K; i++) {
                float B = tensor_q_net_4_weight[c][i];
                ABrc += tensor_11[r][i] * B;
            }
            float tmp = ABrc * alpha + tensor_q_net_4_bias[c] * beta;
            tensor_output[r][c] = tmp;
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
    float tensor_input[1][4] = {
        {-0.25938286f, -0.44444072f, -0.02360042f, 0.27775290f}
    };
    float tensor_output[1][2];

    entry(tensor_input, tensor_output);

    // Validate results using assertions
    assert(!(tensor_output[0][1] <= tensor_output[0][0]));

    printf("Assertions passed. Output: [%f, %f]\n", tensor_output[0][0], tensor_output[0][1]);
    return 0;
}