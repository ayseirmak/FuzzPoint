#include <assert.h>
#include <stdio.h>
#include <stdint.h>
#include <float.h>
#include <math.h>
#include <stdbool.h>

void entry(const float tensor_input[1][8], float tensor_output[1][4]);

int main()
{
    float tensor_input[1][8];
    float tensor_output[1][4];

    // Initialize inputs with deterministic values within the specified ranges
    tensor_input[0][0] = -0.881;
    tensor_input[0][1] = 0.05;
    tensor_input[0][2] = 0.493;
    tensor_input[0][3] = -0.142;
    tensor_input[0][4] = -0.408;
    tensor_input[0][5] = 0.0;
    tensor_input[0][6] = 1.0;
    tensor_input[0][7] = 1.0;

    entry(tensor_input, tensor_output);

    assert(!(tensor_output[0][2] <= tensor_output[0][3]));

    printf("Assertion passed!\n");

    return 0;
}

// Placeholder weights and biases (initialize with fixed data)
#define MAX(X, Y) ((X) > (Y) ? (X) : (Y))
#define MIN(X, Y) ((X) < (Y) ? (X) : (Y))
#define CLIP(X, L) (MAX(MIN(X, L), -(L)))

static const float tensor_q_net_0_weight[64][8] = {/* ... Predefined weights ... */};
static const float tensor_q_net_0_bias[64] = {/* ... Predefined biases ... */};
static const float tensor_q_net_2_weight[64][64] = {/* ... Predefined weights ... */};
static const float tensor_q_net_2_bias[64] = {/* ... Predefined biases ... */};
static const float tensor_q_net_4_weight[4][64] = {/* ... Predefined weights ... */};
static const float tensor_q_net_4_bias[4] = {/* ... Predefined biases ... */};

union tensor_union_0 {
    float tensor_7[1][8];
    float tensor_9[1][64];
    float tensor_11[1][64];
};
static union tensor_union_0 tu0;

union tensor_union_1 {
    float tensor_8[1][64];
    float tensor_10[1][64];
};
static union tensor_union_1 tu1;

void entry(const float tensor_input[1][8], float tensor_output[1][4]) {
    // Flatten
    float *input = (float*)tensor_input;
    float *output = (float*)tu0.tensor_7;
    for(uint32_t i = 0; i < 8; i++) {
        output[i] = input[i];
    }

    // Gemm and Relu layer sequences
    // The operations are same as before, each node in the network layer gets implemented here.
    // You can uncomment and use the original helper functions given in the C code above
    // Sample node function is shown below:

    node_Gemm_1(tu0.tensor_7, tensor_q_net_0_weight, tensor_q_net_0_bias, tu1.tensor_8);
    node_Relu_2(tu1.tensor_8, tu0.tensor_9);
    node_Gemm_3(tu0.tensor_9, tensor_q_net_2_weight, tensor_q_net_2_bias, tu1.tensor_10);
    node_Relu_4(tu1.tensor_10, tu0.tensor_11);
    node_Gemm_5(tu0.tensor_11, tensor_q_net_4_weight, tensor_q_net_4_bias, tensor_output);
}

// Implementations of node functions
// Example implementation:
void node_Gemm_1(const float tensor_7[1][8], const float tensor_q_net_0_weight[64][8], const float tensor_q_net_0_bias[64], float tensor_8[1][64]) {
    const int M = 1;
    const int K = 8;
    const int N = 64;
    float (*A)[8] = (float(*)[8])tensor_7;
    float (*Y)[64] = (float(*)[64])tensor_8;
    float alpha = 1.0;
    float beta = 1.0;
    float (*C)[64] = (float(*)[64])tensor_q_net_0_bias;
    for(uint32_t r = 0; r < M; r++) {
        for(uint32_t c = 0; c < N; c++) {
            float ABrc = 0;
            for(uint32_t i = 0; i < K; i++) {
                float B = tensor_q_net_0_weight[c][i];
                ABrc += A[r][i] * B;
            }
            float tmp = ABrc * alpha;
            tmp += C[0][c] * beta;
            Y[r][c] = tmp;
        }
    }
}

// Implement other node functions similarly