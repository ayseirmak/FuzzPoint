#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <assert.h>
#include <stdint.h>

// Define fixed inputs replacing non-deterministic functions
#define FIXED_INPUT_0 1.0f
#define FIXED_INPUT_1 -1.0f
#define FIXED_INPUT_2 2.0f

// Model weights and biases
static const float tensor_linear_list_0_weight[32][3] = {
    // ... (same as original)
};

static const float tensor_linear_list_0_bias[32] = {
    // ... (same as original)
};

static const float tensor_linear_list_1_weight[32][32] = {
    // ... (same as original)
};

static const float tensor_linear_list_1_bias[32] = {
    // ... (same as original)
};

static const float tensor_linear_list_2_weight[3][32] = {
    // ... (same as original)
};

static const float tensor_linear_list_2_bias[3] = {
    // ... (same as original)
};

union tensor_union_0 {
    float tensor_7[1][32];
    float tensor_9[1][32];
};

static union tensor_union_0 tu0;

union tensor_union_1 {
    float tensor_8[1][32];
    float tensor_10[1][32];
};

static union tensor_union_1 tu1;

// Function Prototypes
void entry(const float tensor_input[1][3], float tensor_output[1][3]);

static inline void node_Gemm_0(const float tensor_input[1][3], const float tensor_linear_list_0_weight[32][3], const float tensor_linear_list_0_bias[32], float tensor_7[1][32]);
static inline void node_Relu_1(const float tensor_7[1][32], float tensor_8[1][32]);
static inline void node_Gemm_2(const float tensor_8[1][32], const float tensor_linear_list_1_weight[32][32], const float tensor_linear_list_1_bias[32], float tensor_9[1][32]);
static inline void node_Relu_3(const float tensor_9[1][32], float tensor_10[1][32]);
static inline void node_Gemm_4(const float tensor_10[1][32], const float tensor_linear_list_2_weight[3][32], const float tensor_linear_list_2_bias[3], float tensor_output[1][3]);

int main() {
    float tensor_input[1][3] = {
        {FIXED_INPUT_0, FIXED_INPUT_1, FIXED_INPUT_2}
    };
    float tensor_output[1][3];

    entry(tensor_input, tensor_output);

    // Assert condition equivalent to __VERIFIER_assert()
    assert(!((tensor_output[0][1] <= 0.37980702501135716) &&
             (tensor_output[0][1] >= -0.37980702501135716) &&
             (tensor_output[0][2] <= 0.37980702501135716) &&
             (tensor_output[0][2] >= -0.37980702501135716) &&
             (tensor_output[0][0] >= 0.2555093881187115)));

    // Output the tensor_output for debugging
    printf("tensor_output: [%f, %f, %f]\n", tensor_output[0][0], tensor_output[0][1], tensor_output[0][2]);

    return 0;
}

static inline void node_Gemm_0(const float tensor_input[1][3], const float tensor_linear_list_0_weight[32][3], const float tensor_linear_list_0_bias[32], float tensor_7[1][32]) {
    const int M = 1;
    const int K = 3;
    const int N = 32;
    float (*A)[3] = (float (*)[3])tensor_input;
    float (*Y)[32] = (float (*)[32])tensor_7;
    float alpha = 1.0f;
    float beta = 1.0f;
    float (*C)[32] = (float (*)[32])tensor_linear_list_0_bias;
    for (uint32_t r = 0; r < M; r++)
        for (uint32_t c = 0; c < N; c++) {
            float ABrc = 0;
            for (uint32_t i = 0; i < K; i++) {
                float B = tensor_linear_list_0_weight[c][i];
                ABrc += A[r][i] * B;
            }
            float tmp = ABrc * alpha;
            tmp += C[0][c] * beta;
            Y[r][c] = tmp;
        }
}

static inline void node_Relu_1(const float tensor_7[1][32], float tensor_8[1][32]) {
    float *X = (float *)tensor_7;
    float *Y = (float *)tensor_8;
    for (uint32_t i = 0; i < 32; i++)
        Y[i] = X[i] > 0 ? X[i] : 0;
}

static inline void node_Gemm_2(const float tensor_8[1][32], const float tensor_linear_list_1_weight[32][32], const float tensor_linear_list_1_bias[32], float tensor_9[1][32]) {
    const int M = 1;
    const int K = 32;
    const int N = 32;
    float (*A)[32] = (float (*)[32])tensor_8;
    float (*Y)[32] = (float (*)[32])tensor_9;
    float alpha = 1.0f;
    float beta = 1.0f;
    float (*C)[32] = (float (*)[32])tensor_linear_list_1_bias;
    for (uint32_t r = 0; r < M; r++)
        for (uint32_t c = 0; c < N; c++) {
            float ABrc = 0;
            for (uint32_t i = 0; i < K; i++) {
                float B = tensor_linear_list_1_weight[c][i];
                ABrc += A[r][i] * B;
            }
            float tmp = ABrc * alpha;
            tmp += C[0][c] * beta;
            Y[r][c] = tmp;
        }
}

static inline void node_Relu_3(const float tensor_9[1][32], float tensor_10[1][32]) {
    float *X = (float *)tensor_9;
    float *Y = (float *)tensor_10;
    for (uint32_t i = 0; i < 32; i++)
        Y[i] = X[i] > 0 ? X[i] : 0;
}

static inline void node_Gemm_4(const float tensor_10[1][32], const float tensor_linear_list_2_weight[3][32], const float tensor_linear_list_2_bias[3], float tensor_output[1][3]) {
    const int M = 1;
    const int K = 32;
    const int N = 3;
    float (*A)[32] = (float (*)[32])tensor_10;
    float (*Y)[3] = (float (*)[3])tensor_output;
    float alpha = 1.0f;
    float beta = 1.0f;
    float (*C)[3] = (float (*)[3])tensor_linear_list_2_bias;
    for (uint32_t r = 0; r < M; r++)
        for (uint32_t c = 0; c < N; c++) {
            float ABrc = 0;
            for (uint32_t i = 0; i < K; i++) {
                float B = tensor_linear_list_2_weight[c][i];
                ABrc += A[r][i] * B;
            }
            float tmp = ABrc * alpha;
            tmp += C[0][c] * beta;
            Y[r][c] = tmp;
        }
}

void entry(const float tensor_input[1][3], float tensor_output[1][3]) {
    node_Gemm_0(tensor_input, tensor_linear_list_0_weight, tensor_linear_list_0_bias, tu0.tensor_7);
    node_Relu_1(tu0.tensor_7, tu1.tensor_8);
    node_Gemm_2(tu1.tensor_8, tensor_linear_list_1_weight, tensor_linear_list_1_bias, tu0.tensor_9);
    node_Relu_3(tu0.tensor_9, tu1.tensor_10);
    node_Gemm_4(tu1.tensor_10, tensor_linear_list_2_weight, tensor_linear_list_2_bias, tensor_output);
}