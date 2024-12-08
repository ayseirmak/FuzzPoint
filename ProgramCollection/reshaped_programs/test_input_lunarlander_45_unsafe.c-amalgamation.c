#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <assert.h>

#define MAX(X,Y) ( (X) > (Y) ? (X) : (Y) )
#define MIN(X,Y) ( (X) < (Y) ? (X) : (Y) )
#define CLIP(X,L) ( MAX(MIN(X,L), -L) )

// Constants and weights from the original code
static const float tensor_q_net_0_weight[64][8] = {...};  // Truncated for brevity
static const float tensor_q_net_0_bias[64] = {...};
static const float tensor_q_net_2_weight[64][64] = {...};
static const float tensor_q_net_2_bias[64] = {...};
static const float tensor_q_net_4_weight[4][64] = {...};
static const float tensor_q_net_4_bias[4] = {...};

typedef union {
    float tensor_7[1][8];
    float tensor_9[1][64];
    float tensor_11[1][64];
} tensor_union_0;

typedef union {
    float tensor_8[1][64];
    float tensor_10[1][64];
} tensor_union_1;

static tensor_union_0 tu0;
static tensor_union_1 tu1;

// Helper function to generate deterministic float value based on index
float get_fixed_float(int index) {
    static const float fixed_values[8] = {-0.9f, 0.05f, 0.95f, -0.3f, -0.4f, -0.01f, 1.0f, 0.02f};
    return fixed_values[index];
}

static inline void node_Flatten_0(const float tensor_input[1][8], float tensor_7[1][8]) {
    memcpy(tensor_7, tensor_input, 8 * sizeof(float));
}

static inline void node_Gemm_1(const float tensor_7[1][8], const float tensor_q_net_0_weight[64][8], const float tensor_q_net_0_bias[64], float tensor_8[1][64]) {
    const int M = 1;
    const int K = 8;
    const int N = 64;
    for (int r = 0; r < M; r++)
        for (int c = 0; c < N; c++) {
            float ABrc = 0;
            for (int i = 0; i < K; i++) {
                float B = tensor_q_net_0_weight[c][i];
                ABrc += tensor_7[r][i] * B;
            }
            tensor_8[r][c] = ABrc + tensor_q_net_0_bias[c];
        }
}

static inline void node_Relu_2(const float tensor_8[1][64], float tensor_9[1][64]) {
    for (int i = 0; i < 64; i++)
        tensor_9[0][i] = tensor_8[0][i] > 0 ? tensor_8[0][i] : 0;
}

static inline void node_Gemm_3(const float tensor_9[1][64], const float tensor_q_net_2_weight[64][64], const float tensor_q_net_2_bias[64], float tensor_10[1][64]) {
    const int M = 1;
    const int K = 64;
    const int N = 64;
    for (int r = 0; r < M; r++)
        for (int c = 0; c < N; c++) {
            float ABrc = 0;
            for (int i = 0; i < K; i++) {
                float B = tensor_q_net_2_weight[c][i];
                ABrc += tensor_9[r][i] * B;
            }
            tensor_10[r][c] = ABrc + tensor_q_net_2_bias[c];
        }
}

static inline void node_Relu_4(const float tensor_10[1][64], float tensor_11[1][64]) {
    for (int i = 0; i < 64; i++)
        tensor_11[0][i] = tensor_10[0][i] > 0 ? tensor_10[0][i] : 0;
}

static inline void node_Gemm_5(const float tensor_11[1][64], const float tensor_q_net_4_weight[4][64], const float tensor_q_net_4_bias[4], float tensor_output[1][4]) {
    const int M = 1;
    const int K = 64;
    const int N = 4;
    for (int r = 0; r < M; r++)
        for (int c = 0; c < N; c++) {
            float ABrc = 0;
            for (int i = 0; i < K; i++) {
                float B = tensor_q_net_4_weight[c][i];
                ABrc += tensor_11[r][i] * B;
            }
            tensor_output[r][c] = ABrc + tensor_q_net_4_bias[c];
        }
}

void entry(const float tensor_input[1][8], float tensor_output[1][4]) {
    node_Flatten_0(tensor_input, tu0.tensor_7);
    node_Gemm_1(tu0.tensor_7, tensor_q_net_0_weight, tensor_q_net_0_bias, tu1.tensor_8);
    node_Relu_2(tu1.tensor_8, tu0.tensor_9);
    node_Gemm_3(tu0.tensor_9, tensor_q_net_2_weight, tensor_q_net_2_bias, tu1.tensor_10);
    node_Relu_4(tu1.tensor_10, tu0.tensor_11);
    node_Gemm_5(tu0.tensor_11, tensor_q_net_4_weight, tensor_q_net_4_bias, tensor_output);
}

int main() {
    float tensor_input[1][8];
    float tensor_output[1][4];

    // Deterministic inputs
    for (int i = 0; i < 8; i++) {
        tensor_input[0][i] = get_fixed_float(i);
    }

    entry(tensor_input, tensor_output);

    // Assert equivalent output condition, replaced for standard C
    assert(!(tensor_output[0][3] <= tensor_output[0][0]));

    printf("Verification passed. Output values:\n");
    for(int i = 0; i < 4; i++) {
        printf("tensor_output[0][%d] = %f\n", i, tensor_output[0][i]);
    }

    return 0;
}