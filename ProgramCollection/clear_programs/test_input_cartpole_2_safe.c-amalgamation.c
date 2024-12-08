#include <stdio.h>
#include <assert.h>
#include <float.h>
#include <stdbool.h>
#include <stdint.h>

// Macro definitions
#define MAX(X,Y) ((X) > (Y) ? (X) : (Y))
#define MIN(X,Y) ((X) < (Y) ? (X) : (Y))
#define CLIP(X,L) (MAX(MIN(X,L), -L))

// Tensor weights and biases
static const float tensor_q_net_0_weight[64][4] = {
    {0.15721032023429870605f, 0.11475459486246109009f, -0.63993811607360839844f, -0.06951084733009338379f},
    {0.17542746663093566895f, 0.03734674677252769470f, 0.11804900318384170532f, -0.42608326673507690430f},
    // Other weight values are skipped for brevity
};

static const float tensor_q_net_0_bias[64] = {
    -0.03848094865679740906f, 0.12814424932003021240f,
    // Other bias values are skipped for brevity
};

static const float tensor_q_net_2_weight[64][64] = {
    {-0.08137283474206924438f, 0.02424875646829605103f},
    // Other weight values are skipped for brevity
};

static const float tensor_q_net_2_bias[64] = {
    0.00965216662734746933f,
    // Other bias values are skipped for brevity
};

static const float tensor_q_net_4_weight[2][64] = {
    {-0.10003891587257385254f, -0.22389468550682067871f},
    // Other weight values are skipped for brevity
};

static const float tensor_q_net_4_bias[2] = {0.02019731327891349793f, 0.000829212600365281105f};

// Union to hold tensors
union tensor_union_0 {
    float tensor_7[1][4];
    float tensor_9[1][64];
    float tensor_11[1][64];
};

union tensor_union_1 {
    float tensor_8[1][64];
    float tensor_10[1][64];
};

// Tensor unions
static union tensor_union_0 tu0;
static union tensor_union_1 tu1;

// Functions to process nodes
static inline void node_Flatten_0(const float tensor_input[1][4], float tensor_7[1][4]) {
    float *input = (float *)tensor_input;
    float *output = (float *)tensor_7;
    for (uint32_t i = 0; i < 4; i++)
        output[i] = input[i];
}

static inline void node_Gemm_1(const float tensor_7[1][4], const float tensor_q_net_0_weight[64][4], const float tensor_q_net_0_bias[64], float tensor_8[1][64]) {
    const int M = 1;
    const int K = 4;
    const int N = 64;
    float (*A)[4] = (float(*)[4])tensor_7;
    float (*Y)[64] = (float(*)[64])tensor_8;
    float (*C)[64] = (float(*)[64])tensor_q_net_0_bias;
    for (uint32_t r = 0; r < M; r++)
        for (uint32_t c = 0; c < N; c++) {
            float ABrc = 0;
            for (uint32_t i = 0; i < K; i++) {
                float B = tensor_q_net_0_weight[c][i];
                ABrc += A[r][i] * B;
            }
            float tmp = ABrc;
            tmp += C[0][c];
            Y[r][c] = tmp;
        }
}

static inline void node_Relu_2(const float tensor_8[1][64], float tensor_9[1][64]) {
    float *X = (float *)tensor_8;
    float *Y = (float *)tensor_9;
    for (uint32_t i = 0; i < 64; i++)
        Y[i] = X[i] > 0 ? X[i] : 0;
}

static inline void node_Gemm_3(const float tensor_9[1][64], const float tensor_q_net_2_weight[64][64], const float tensor_q_net_2_bias[64], float tensor_10[1][64]) {
    const int M = 1;
    const int K = 64;
    const int N = 64;
    float (*A)[64] = (float(*)[64])tensor_9;
    float (*Y)[64] = (float(*)[64])tensor_10;
    float (*C)[64] = (float(*)[64])tensor_q_net_2_bias;
    for (uint32_t r = 0; r < M; r++)
        for (uint32_t c = 0; c < N; c++) {
            float ABrc = 0;
            for (uint32_t i = 0; i < K; i++) {
                float B = tensor_q_net_2_weight[c][i];
                ABrc += A[r][i] * B;
            }
            float tmp = ABrc;
            tmp += C[0][c];
            Y[r][c] = tmp;
        }
}

static inline void node_Relu_4(const float tensor_10[1][64], float tensor_11[1][64]) {
    float *X = (float *)tensor_10;
    float *Y = (float *)tensor_11;
    for (uint32_t i = 0; i < 64; i++)
        Y[i] = X[i] > 0 ? X[i] : 0;
}

static inline void node_Gemm_5(const float tensor_11[1][64], const float tensor_q_net_4_weight[2][64], const float tensor_q_net_4_bias[2], float tensor_output[1][2]) {
    const int M = 1;
    const int K = 64;
    const int N = 2;
    float (*A)[64] = (float(*)[64])tensor_11;
    float (*Y)[2] = (float(*)[2])tensor_output;
    float (*C)[2] = (float(*)[2])tensor_q_net_4_bias;
    for (uint32_t r = 0; r < M; r++)
        for (uint32_t c = 0; c < N; c++) {
            float ABrc = 0;
            for (uint32_t i = 0; i < K; i++) {
                float B = tensor_q_net_4_weight[c][i];
                ABrc += A[r][i] * B;
            }
            float tmp = ABrc;
            tmp += C[0][c];
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
        {0.070352, 0.784183, -0.107884, -1.258024 } // deterministic input
    };
    float tensor_output[1][2];

    entry(tensor_input, tensor_output);

    assert(!(tensor_output[0][0] <= tensor_output[0][1]));

    printf("Success: %f, %f\n", tensor_output[0][0], tensor_output[0][1]);

    return 0;
}