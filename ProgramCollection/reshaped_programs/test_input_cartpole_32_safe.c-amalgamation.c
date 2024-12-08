#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdint.h>

// Model Weights and Biases

static const float tensor_q_net_0_weight[64][4] = {
    // Initialize with given values (... full list truncated for brevity)
};

static const float tensor_q_net_0_bias[64] = {
    // Initialize with given values (... full list truncated for brevity)
};

static const float tensor_q_net_2_weight[64][64] = {
    // Initialize with given values (... full list truncated for brevity)
};

static const float tensor_q_net_2_bias[64] = {
    // Initialize with given values (... full list truncated for brevity)
};

static const float tensor_q_net_4_weight[2][64] = {
    // Initialize with given values (... full list truncated for brevity)
};

static const float tensor_q_net_4_bias[2] = {
    // Initialize with given values (... full list truncated for brevity)
};

void node_Flatten_0(const float tensor_input[1][4], float tensor_7[1][4]) {
    float *input = (float*)tensor_input;
    float *output = (float*)tensor_7;
    for (uint32_t i = 0; i < 4; i++)
        output[i] = input[i];
}

void node_Gemm_1(const float tensor_7[1][4], const float tensor_q_net_0_weight[64][4], const float tensor_q_net_0_bias[64], float tensor_8[1][64]) {
    const int M = 1, K = 4, N = 64;
    float (*A)[4] = (float(*)[4])tensor_7;
    float (*Y)[64] = (float(*)[64])tensor_8;

    for (uint32_t r = 0; r < M; r++)
        for (uint32_t c = 0; c < N; c++) {
            float ABrc = 0;
            for (uint32_t i = 0; i < K; i++) {
                float B = tensor_q_net_0_weight[c][i];
                ABrc += A[r][i] * B;
            }
            Y[r][c] = ABrc + tensor_q_net_0_bias[c];
        }
}

void node_Relu_2(const float tensor_8[1][64], float tensor_9[1][64]) {
    for (uint32_t i = 0; i < 64; i++)
        tensor_9[0][i] = tensor_8[0][i] > 0 ? tensor_8[0][i] : 0;
}

void node_Gemm_3(const float tensor_9[1][64], const float tensor_q_net_2_weight[64][64], const float tensor_q_net_2_bias[64], float tensor_10[1][64]) {
    const int M = 1, K = 64, N = 64;
    float (*A)[64] = (float(*)[64])tensor_9;
    float (*Y)[64] = (float(*)[64])tensor_10;

    for (uint32_t r = 0; r < M; r++)
        for (uint32_t c = 0; c < N; c++) {
            float ABrc = 0;
            for (uint32_t i = 0; i < K; i++) {
                float B = tensor_q_net_2_weight[c][i];
                ABrc += A[r][i] * B;
            }
            Y[r][c] = ABrc + tensor_q_net_2_bias[c];
        }
}

void node_Relu_4(const float tensor_10[1][64], float tensor_11[1][64]) {
    for (uint32_t i = 0; i < 64; i++)
        tensor_11[0][i] = tensor_10[0][i] > 0 ? tensor_10[0][i] : 0;
}

void node_Gemm_5(const float tensor_11[1][64], const float tensor_q_net_4_weight[2][64], const float tensor_q_net_4_bias[2], float tensor_output[1][2]) {
    const int M = 1, K = 64, N = 2;
    float (*A)[64] = (float(*)[64])tensor_11;
    float (*Y)[2] = (float(*)[2])tensor_output;

    for (uint32_t r = 0; r < M; r++)
        for (uint32_t c = 0; c < N; c++) {
            float ABrc = 0;
            for (uint32_t i = 0; i < K; i++) {
                float B = tensor_q_net_4_weight[c][i];
                ABrc += A[r][i] * B;
            }
            Y[r][c] = ABrc + tensor_q_net_4_bias[c];
        }
}

void entry(const float tensor_input[1][4], float tensor_output[1][2]) {
    float tensor_7[1][4];
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
    float tensor_input[1][4] = {
        {0.035, 0.196, -0.054, -0.332}
    };
    float tensor_output[1][2];

    entry(tensor_input, tensor_output);

    assert(!(tensor_output[0][0] <= tensor_output[0][1]));
    printf("Assertion Passed: Output[0] > Output[1]\n");
    
    return 0;
}