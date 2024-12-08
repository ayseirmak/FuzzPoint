#include <stdio.h>
#include <float.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <assert.h>

#define MAX(X,Y) (X > Y ? X : Y)
#define MIN(X,Y) (X < Y ? X : Y)
#define CLIP(X,L) (MAX(MIN(X,L), -L))

static const float tensor_q_net_0_weight[64][4] = {
// [Initialize with the same weights as your original code]
};

static const float tensor_q_net_0_bias[64] = {
// [Initialize with the same biases as your original code]
};

static const float tensor_q_net_2_weight[64][64] = {
// [Initialize with the same weights as your original code]
};

static const float tensor_q_net_2_bias[64] = {
// [Initialize with the same biases as your original code]
};

static const float tensor_q_net_4_weight[2][64] = {
// [Initialize with the same weights as your original code]
};

static const float tensor_q_net_4_bias[2] = {
// [Initialize with the same biases as your original code]
};

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

static inline void node_Flatten_0(const float tensor_input[1][4], float tensor_7[1][4]) {
    float *input = (float*)tensor_input;
    float *output = (float*)tensor_7;
    for (uint32_t i = 0; i < 4; i++)
        output[i] = input[i];
}

static inline void node_Gemm_1(const float tensor_7[1][4], const float tensor_q_net_0_weight[64][4], const float tensor_q_net_0_bias[64], float tensor_8[1][64]) {
    const int M = 1;
    const int K = 4;
    const int N = 64;
    float (*A)[4] = (float (*)[4])tensor_7;
    float (*Y)[64] = (float (*)[64])tensor_8;
    float alpha = 1.0;
    float beta = 1.0;
    float (*C)[64] = (float (*)[64])tensor_q_net_0_bias;
    for (uint32_t r = 0; r < M; r++)
        for (uint32_t c = 0; c < N; c++) {
            float ABrc = 0;
            for (uint32_t i = 0; i < K; i++) {
                float B = tensor_q_net_0_weight[c][i];
                ABrc += A[r][i] * B;
            }
            float tmp = ABrc * alpha;
            tmp += C[0][c] * beta;
            Y[r][c] = tmp;
        }
}

static inline void node_Relu_2(const float tensor_8[1][64], float tensor_9[1][64]) {
    float *X = (float*)tensor_8;
    float *Y = (float*)tensor_9;
    for (uint32_t i = 0; i < 64; i++)
        Y[i] = X[i] > 0 ? X[i] : 0;
}

static inline void node_Gemm_3(const float tensor_9[1][64], const float tensor_q_net_2_weight[64][64], const float tensor_q_net_2_bias[64], float tensor_10[1][64]) {
    const int M = 1;
    const int K = 64;
    const int N = 64;
    float (*A)[64] = (float (*)[64])tensor_9;
    float (*Y)[64] = (float (*)[64])tensor_10;
    float alpha = 1.0;
    float beta = 1.0;
    float (*C)[64] = (float (*)[64])tensor_q_net_2_bias;
    for (uint32_t r = 0; r < M; r++)
        for (uint32_t c = 0; c < N; c++) {
            float ABrc = 0;
            for (uint32_t i = 0; i < K; i++) {
                float B = tensor_q_net_2_weight[c][i];
                ABrc += A[r][i] * B;
            }
            float tmp = ABrc * alpha;
            tmp += C[0][c] * beta;
            Y[r][c] = tmp;
        }
}

static inline void node_Relu_4(const float tensor_10[1][64], float tensor_11[1][64]) {
    float *X = (float*)tensor_10;
    float *Y = (float*)tensor_11;
    for (uint32_t i = 0; i < 64; i++)
        Y[i] = X[i] > 0 ? X[i] : 0;
}

static inline void node_Gemm_5(const float tensor_11[1][64], const float tensor_q_net_4_weight[2][64], const float tensor_q_net_4_bias[2], float tensor_output[1][2]) {
    const int M = 1;
    const int K = 64;
    const int N = 2;
    float (*A)[64] = (float (*)[64])tensor_11;
    float (*Y)[2] = (float (*)[2])tensor_output;
    float alpha = 1.0;
    float beta = 1.0;
    float (*C)[2] = (float (*)[2])tensor_q_net_4_bias;
    for (uint32_t r = 0; r < M; r++)
        for (uint32_t c = 0; c < N; c++) {
            float ABrc = 0;
            for (uint32_t i = 0; i < K; i++) {
                float B = tensor_q_net_4_weight[c][i];
                ABrc += A[r][i] * B;
            }
            float tmp = ABrc * alpha;
            tmp += C[0][c] * beta;
            Y[r][c] = tmp;
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
        {-0.2680, -0.2490, -0.0180, -0.0220}
    };
    float tensor_output[1][2];

    entry(tensor_input, tensor_output);

    assert(!(tensor_output[0][1] <= tensor_output[0][0]));

    printf("Program executed successfully.\n");
    return 0;
}