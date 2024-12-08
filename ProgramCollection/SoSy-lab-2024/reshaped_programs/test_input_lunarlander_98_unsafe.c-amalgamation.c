#include <stdio.h>
#include <math.h> 
#include <assert.h>
#include <stdint.h>

// Declare constants here
static const float tensor_q_net_0_weight[64][8] = {
    // Matrix values...
};

static const float tensor_q_net_0_bias[64] = {
    // Bias values...
};

static const float tensor_q_net_2_weight[64][64] = {
    // Matrix values...
};

static const float tensor_q_net_2_bias[64] = {
    // Bias values...
};

static const float tensor_q_net_4_weight[4][64] = {
    // Matrix values...
};

static const float tensor_q_net_4_bias[4] = {
    // Bias values...
};

// Define the necessary functions here
static inline void node_Flatten_0(const float tensor_input[1][8], float tensor_7[1][8]) {
    float *input = (float*)tensor_input;
    float *output = (float*)tensor_7;
    for (uint32_t i = 0; i < 8; i++)
        output[i] = input[i];
}

static inline void node_Gemm_1(const float tensor_7[1][8], const float tensor_q_net_0_weight[64][8], const float tensor_q_net_0_bias[64], float tensor_8[1][64]) {
    const int M = 1;
    const int K = 8;
    const int N = 64;
    float alpha = 1.0;
    float beta = 1.0;
    for (uint32_t r = 0; r < M; r++)
        for (uint32_t c = 0; c < N; c++) {
            float ABrc = 0;
            for (uint32_t i = 0; i < K; i++) {
                float B = tensor_q_net_0_weight[c][i];
                ABrc += tensor_7[r][i] * B;
            }
            float tmp = ABrc * alpha;
            tmp += tensor_q_net_0_bias[c] * beta;
            tensor_8[r][c] = tmp;
        }
}

static inline void node_Relu_2(const float tensor_8[1][64], float tensor_9[1][64]) {
    for (uint32_t i = 0; i < 64; i++)
        tensor_9[0][i] = tensor_8[0][i] > 0 ? tensor_8[0][i] : 0;
}

static inline void node_Gemm_3(const float tensor_9[1][64], const float tensor_q_net_2_weight[64][64], const float tensor_q_net_2_bias[64], float tensor_10[1][64]) {
    const int M = 1;
    const int K = 64;
    const int N = 64;
    float alpha = 1.0;
    float beta = 1.0;
    for (uint32_t r = 0; r < M; r++)
        for (uint32_t c = 0; c < N; c++) {
            float ABrc = 0;
            for (uint32_t i = 0; i < K; i++) {
                float B = tensor_q_net_2_weight[c][i];
                ABrc += tensor_9[r][i] * B;
            }
            float tmp = ABrc * alpha;
            tmp += tensor_q_net_2_bias[c] * beta;
            tensor_10[r][c] = tmp;
        }
}

static inline void node_Relu_4(const float tensor_10[1][64], float tensor_11[1][64]) {
    for (uint32_t i = 0; i < 64; i++)
        tensor_11[0][i] = tensor_10[0][i] > 0 ? tensor_10[0][i] : 0;
}

static inline void node_Gemm_5(const float tensor_11[1][64], const float tensor_q_net_4_weight[4][64], const float tensor_q_net_4_bias[4], float tensor_output[1][4]) {
    const int M = 1;
    const int K = 64;
    const int N = 4;
    float alpha = 1.0;
    float beta = 1.0;
    for (uint32_t r = 0; r < M; r++)
        for (uint32_t c = 0; c < N; c++) {
            float ABrc = 0;
            for (uint32_t i = 0; i < K; i++) {
                float B = tensor_q_net_4_weight[c][i];
                ABrc += tensor_11[r][i] * B;
            }
            float tmp = ABrc * alpha;
            tmp += tensor_q_net_4_bias[c] * beta;
            tensor_output[r][c] = tmp;
        }
}

void entry(const float tensor_input[1][8], float tensor_output[1][4]) {
    float tensor_7[1][8];
    float tensor_8[1][64], tensor_9[1][64];
    float tensor_10[1][64], tensor_11[1][64];

    node_Flatten_0(tensor_input, tensor_7);
    node_Gemm_1(tensor_7, tensor_q_net_0_weight, tensor_q_net_0_bias, tensor_8);
    node_Relu_2(tensor_8, tensor_9);
    node_Gemm_3(tensor_9, tensor_q_net_2_weight, tensor_q_net_2_bias, tensor_10);
    node_Relu_4(tensor_10, tensor_11);
    node_Gemm_5(tensor_11, tensor_q_net_4_weight, tensor_q_net_4_bias, tensor_output);
}

int main() {
    float tensor_input[1][8] = {
        {-0.77f, 0.025f, 0.028f, -0.06f, 0.077f, -0.071f, 0.999f, 0.999f}
    };
    float tensor_output[1][4];

    entry(tensor_input, tensor_output);

    assert(!(tensor_output[0][2] <= tensor_output[0][3]));
    printf("Output: %.2f, %.2f, %.2f, %.2f\n", tensor_output[0][0], tensor_output[0][1], tensor_output[0][2], tensor_output[0][3]);

    return 0;
}