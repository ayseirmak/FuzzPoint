#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>
#include <stdint.h>

// Function prototypes
void entry(const float tensor_input[1][4], float tensor_output[1][2]);

// Weight and bias arrays declarations (abbreviated for brevity; they should contain the same values as in the original code)

static const float tensor_q_net_0_weight[64][4] = {/*...*/};
static const float tensor_q_net_0_bias[64] = {/*...*/};
static const float tensor_q_net_2_weight[64][64] = {/*...*/};
static const float tensor_q_net_2_bias[64] = {/*...*/};
static const float tensor_q_net_4_weight[2][64] = {/*...*/};
static const float tensor_q_net_4_bias[2] = {/*...*/};

// Union declarations for tensors
union tensor_union_0 {
    float tensor_7[1][4];
    float tensor_9[1][64];
    float tensor_11[1][64];
};

union tensor_union_1 {
    float tensor_8[1][64];
    float tensor_10[1][64];
};

// Functions
static inline void node_Flatten_0(const float tensor_input[1][4], float tensor_7[1][4]) {
    /* Flatten */
    float *input = (float *)tensor_input;
    float *output = (float *)tensor_7;
    for (uint32_t i = 0; i < 4; i++)
        output[i] = input[i];
}

static inline void node_Gemm_1(const float tensor_7[1][4], const float tensor_q_net_0_weight[64][4], const float tensor_q_net_0_bias[64], float tensor_8[1][64]) {
    /* Gemm */
    /* alpha   = 1.0000000000000000000
       beta    = 1.0000000000000000000
       transA  = 0
       transB  = 1
     */
    const int M = 1;
    const int K = 4;
    const int N = 64;
    float (*A)[4] = (float (*)[4])tensor_7;
    float (*Y)[64] = (float (*)[64])tensor_8;
    float alpha = 1.0000000000000000000;
    float beta = 1.0000000000000000000;
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

// Define other node functions similar to node_Gemm_1 as done in the original code

void entry(const float tensor_input[1][4], float tensor_output[1][2]) {
    union tensor_union_0 tu0;
    union tensor_union_1 tu1;

    node_Flatten_0(tensor_input, tu0.tensor_7);
    node_Gemm_1(tu0.tensor_7, tensor_q_net_0_weight, tensor_q_net_0_bias, tu1.tensor_8);
    node_Relu_2(tu1.tensor_8, tu0.tensor_9);
    node_Gemm_3(tu0.tensor_9, tensor_q_net_2_weight, tensor_q_net_2_bias, tu1.tensor_10);
    node_Relu_4(tu1.tensor_10, tu0.tensor_11);
    node_Gemm_5(tu0.tensor_11, tensor_q_net_4_weight, tensor_q_net_4_bias, tensor_output);
}

int main() {
    // Fixed input values within given constraints
    float tensor_input[1][4] = {{-0.25, 0.33, -0.02, -0.88}};
    float tensor_output[1][2];

    entry(tensor_input, tensor_output);

    // Use assertions instead of __VERIFIER_assert
    assert(!(tensor_output[0][0] <= tensor_output[0][1]));
    
    printf("Test passed with output: (%f, %f)\n", tensor_output[0][0], tensor_output[0][1]);

    return 0;
}