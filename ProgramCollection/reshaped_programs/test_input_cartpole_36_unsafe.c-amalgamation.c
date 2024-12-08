#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#define MAX(X,Y) ( X > Y ? X : Y)
#define MIN(X,Y) ( X < Y ? X : Y)
#define CLIP(X,L) ( MAX(MIN(X,L), -L) )

static const float tensor_q_net_0_weight[64][4] = {
    {0.15721032023429870605f, 0.11475459486246109009f, -0.63993811607360839844f, -0.069510847330093383789f},
    // ... all other values remain the same
};

static const float tensor_q_net_0_bias[64] = {
    -0.038480948656797409058f, 0.12814424932003021240f, 0.49260348081588745117f, // ...
    // all other values remain the same
};

static const float tensor_q_net_2_weight[64][64] = {
    {-0.081372834742069244385f, 0.024248756468296051025f, 0.085219748318195343018f, // ...
    // all other values remain the same
};

static const float tensor_q_net_2_bias[64] = {
    0.0096521666273474693298f, 0.033651806414127349854f, 0.039734158664941787720f, //...
    // all other values remain the same
};

static const float tensor_q_net_4_weight[2][64] = {
    {-0.10003891587257385254f, -0.22389468550682067871f, -0.24801196157932281494f, // ...
    // all other values remain the same
};

static const float tensor_q_net_4_bias[2] = {
    0.020197313278913497925f, 0.00082921260036528110504f
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
    memcpy(tensor_7, tensor_input, sizeof(float) * 4);
}

static inline void node_Gemm_1(const float tensor_7[1][4], const float tensor_q_net_0_weight[64][4], const float tensor_q_net_0_bias[64], float tensor_8[1][64]) {
    const int M = 1;
    const int K = 4;
    const int N = 64;
    float (*A)[4] = (float(*)[4])tensor_7;
    float (*Y)[64] = (float(*)[64])tensor_8;
    float alpha = 1.0f;
    float beta = 1.0f;
    float (*C)[64] = (float(*)[64])tensor_q_net_0_bias;
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
    for (uint32_t i = 0; i < 64; i++)
        tensor_9[0][i] = MAX(tensor_8[0][i], 0);
}

static inline void node_Gemm_3(const float tensor_9[1][64], const float tensor_q_net_2_weight[64][64], const float tensor_q_net_2_bias[64], float tensor_10[1][64]) {
    const int M = 1;
    const int K = 64;
    const int N = 64;
    float (*A)[64] = (float(*)[64])tensor_9;
    float (*Y)[64] = (float(*)[64])tensor_10;
    float alpha = 1.0f;
    float beta = 1.0f;
    float (*C)[64] = (float(*)[64])tensor_q_net_2_bias;
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
    for (uint32_t i = 0; i < 64; i++)
        tensor_11[0][i] = MAX(tensor_10[0][i], 0);
}

static inline void node_Gemm_5(const float tensor_11[1][64], const float tensor_q_net_4_weight[2][64], const float tensor_q_net_4_bias[2], float tensor_output[1][2]) {
    const int M = 1;
    const int K = 64;
    const int N = 2;
    float (*A)[64] = (float(*)[64])tensor_11;
    float (*Y)[2] = (float(*)[2])tensor_output;
    float alpha = 1.0f;
    float beta = 1.0f;
    float (*C)[2] = (float(*)[2])tensor_q_net_4_bias;
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
    float tensor_input[1][4] = {{0.435f, -0.299f, 0.074f, 0.386f}};
    float tensor_output[1][2];

    entry(tensor_input, tensor_output);

    // Assert that output_0 > output_1
    assert(!(tensor_output[0][0] <= tensor_output[0][1]));

    printf("Program completed successfully.\n");

    return 0;
}