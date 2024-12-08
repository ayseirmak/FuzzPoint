#include <stdio.h>
#include <math.h>
#include <float.h>
#include <stdint.h>

#define MAX(X, Y) ((X) > (Y) ? (X) : (Y))
#define MIN(X, Y) ((X) < (Y) ? (X) : (Y))
#define CLIP(X, L) (MAX(MIN(X, L), -L))

static const float tensor_q_net_0_weight[64][4] = {
    {0.15721032023429870605f, 0.11475459486246109009f, -0.63993811607360839844f, -0.069510847330093383789f},
    {0.17542746663093566895f, 0.037346746772527694702f, 0.11804900318384170532f, -0.42608326673507690430f},
    // ...
    {-0.068230502307415008545f, -0.091502830386161804199f, -0.13395772874355316162f, 0.058226503431797027588f},
    {0.11002951115369796753f, 0.090075746178627014160f, -0.027827408164739608765f, 0.0060894568450748920441f}
};
static const float tensor_q_net_0_bias[64] = {
    -0.038480948656797409058f, 0.12814424932003021240f, 0.49260348081588745117f, -0.30465084314346313477f,
    // ...
    0.081185646355152130127f
};
// Assume other weight and bias arrays are similarly defined.

static inline void node_Flatten_0(const float tensor_input[1][4], float tensor_7[1][4]) {
    float *input = (float *)tensor_input;
    float *output = (float *)tensor_7;
    for (uint32_t i = 0; i < 4; i++)
        output[i] = input[i];
}

static inline void node_Gemm_1(const float tensor_7[1][4], const float tensor_q_net_0_weight[64][4],
                               const float tensor_q_net_0_bias[64], float tensor_8[1][64]) {
    const int M = 1, K = 4, N = 64;
    float (*A)[4] = (float (*)[4])tensor_7;
    float (*Y)[64] = (float (*)[64])tensor_8;
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

static inline void node_Relu_2(const float tensor_8[1][64], float tensor_9[1][64]) {
    for (uint32_t i = 0; i < 64; i++)
        tensor_9[0][i] = tensor_8[0][i] > 0 ? tensor_8[0][i] : 0;
}

static inline void node_Gemm_3(const float tensor_9[1][64], const float tensor_q_net_2_weight[64][64],
                               const float tensor_q_net_2_bias[64], float tensor_10[1][64]) {
    const int M = 1, K = 64, N = 64;
    float (*A)[64] = (float (*)[64])tensor_9;
    float (*Y)[64] = (float (*)[64])tensor_10;
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

static inline void node_Relu_4(const float tensor_10[1][64], float tensor_11[1][64]) {
    for (uint32_t i = 0; i < 64; i++)
        tensor_11[0][i] = tensor_10[0][i] > 0 ? tensor_10[0][i] : 0;
}

static inline void node_Gemm_5(const float tensor_11[1][64], const float tensor_q_net_4_weight[2][64],
                               const float tensor_q_net_4_bias[2], float tensor_output[1][2]) {
    const int M = 1, K = 64, N = 2;
    float (*A)[64] = (float (*)[64])tensor_11;
    float (*Y)[2] = (float (*)[2])tensor_output;
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
    float tensor_7[1][4], tensor_8[1][64], tensor_9[1][64], tensor_10[1][64], tensor_11[1][64];
    node_Flatten_0(tensor_input, tensor_7);
    node_Gemm_1(tensor_7, tensor_q_net_0_weight, tensor_q_net_0_bias, tensor_8);
    node_Relu_2(tensor_8, tensor_9);
    node_Gemm_3(tensor_9, tensor_q_net_2_weight, tensor_q_net_2_bias, tensor_10);
    node_Relu_4(tensor_10, tensor_11);
    node_Gemm_5(tensor_11, tensor_q_net_4_weight, tensor_q_net_4_bias, tensor_output);
}

int main() {
    float tensor_input[1][4] = {{-0.25f, -0.05f, -0.05f, -0.34f}}; // Example deterministic input
    float tensor_output[1][2];
    entry(tensor_input, tensor_output);
    
    printf("Output: %f, %f\n", tensor_output[0][0], tensor_output[0][1]);
    
    return 0;
}