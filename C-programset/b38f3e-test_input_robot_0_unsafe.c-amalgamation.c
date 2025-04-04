#include <stdio.h>
#include <math.h>
#include <stdint.h>

#define ASSERT(cond) do { if (!(cond)) printf("Assertion failed: %s\n", #cond); } while(0)

static const float tensor_linear_list_0_weight[64][5] = { /* weights */ };
static const float tensor_linear_list_0_bias[64] = { /* biases */ };
static const float tensor_linear_list_1_weight[64][64] = { /* weights */ };
static const float tensor_linear_list_1_bias[64] = { /* biases */ };
static const float tensor_linear_list_2_weight[64][64] = { /* weights */ };
static const float tensor_linear_list_2_bias[64] = { /* biases */ };
static const float tensor_linear_list_3_weight[5][64] = { /* weights */ };
static const float tensor_linear_list_3_bias[5] = { /* biases */ };

union tensor_union_0 {
    float tensor_9[1][64];
    float tensor_11[1][64];
    float tensor_13[1][64];
};
static union tensor_union_0 tu0;

union tensor_union_1 {
    float tensor_10[1][64];
    float tensor_12[1][64];
    float tensor_14[1][64];
};
static union tensor_union_1 tu1;

static inline void node_Gemm_0(const float tensor_input[1][5], float tensor_9[1][64]) {
    const int M = 1;
    const int K = 5;
    const int N = 64;
    float (*A)[5] = (float(*)[5])tensor_input;
    float (*Y)[64] = (float(*)[64])tensor_9;

    for (uint32_t r = 0; r < M; r++) {
        for (uint32_t c = 0; c < N; c++) {
            float ABrc = 0;
            for (uint32_t i = 0; i < K; i++) {
                float B = tensor_linear_list_0_weight[c][i];
                ABrc += A[r][i] * B;
            }
            Y[r][c] = ABrc + tensor_linear_list_0_bias[c];
        }
    }
}

static inline void node_Relu_1(const float tensor_9[1][64], float tensor_10[1][64]) {
    for (uint32_t i = 0; i < 64; i++) {
        tensor_10[0][i] = fmax(0, tensor_9[0][i]);
    }
}

static inline void node_Gemm_2(const float tensor_10[1][64], float tensor_11[1][64]) {
    const int M = 1;
    const int K = 64;
    const int N = 64;

    float (*A)[64] = (float(*)[64])tensor_10;
    float (*Y)[64] = (float(*)[64])tensor_11;

    for (uint32_t r = 0; r < M; r++) {
        for (uint32_t c = 0; c < N; c++) {
            float ABrc = 0;
            for (uint32_t i = 0; i < K; i++) {
                float B = tensor_linear_list_1_weight[c][i];
                ABrc += A[r][i] * B;
            }
            Y[r][c] = ABrc + tensor_linear_list_1_bias[c];
        }
    }
}

static inline void node_Relu_3(const float tensor_11[1][64], float tensor_12[1][64]) {
    for (uint32_t i = 0; i < 64; i++) {
        tensor_12[0][i] = fmax(0, tensor_11[0][i]);
    }
}

static inline void node_Gemm_4(const float tensor_12[1][64], float tensor_13[1][64]) {
    const int M = 1;
    const int K = 64;
    const int N = 64;
    float (*A)[64] = (float(*)[64])tensor_12;
    float (*Y)[64] = (float(*)[64])tensor_13;

    for (uint32_t r = 0; r < M; r++) {
        for (uint32_t c = 0; c < N; c++) {
            float ABrc = 0;
            for (uint32_t i = 0; i < K; i++) {
                float B = tensor_linear_list_2_weight[c][i];
                ABrc += A[r][i] * B;
            }
            Y[r][c] = ABrc + tensor_linear_list_2_bias[c];
        }
    }
}

static inline void node_Relu_5(const float tensor_13[1][64], float tensor_14[1][64]) {
    for (uint32_t i = 0; i < 64; i++) {
        tensor_14[0][i] = fmax(0, tensor_13[0][i]);
    }
}

static inline void node_Gemm_6(const float tensor_14[1][64], float tensor_output[1][5]) {
    const int M = 1;
    const int K = 64;
    const int N = 5;
    float (*A)[64] = (float(*)[64])tensor_14;
    float (*Y)[5] = (float(*)[5])tensor_output;

    for (uint32_t r = 0; r < M; r++) {
        for (uint32_t c = 0; c < N; c++) {
            float ABrc = 0;
            for (uint32_t i = 0; i < K; i++) {
                float B = tensor_linear_list_3_weight[c][i];
                ABrc += A[r][i] * B;
            }
            Y[r][c] = ABrc + tensor_linear_list_3_bias[c];
        }
    }
}

void entry(const float tensor_input[1][5], float tensor_output[1][5]) {
    node_Gemm_0(tensor_input, tu0.tensor_9);
    node_Relu_1(tu0.tensor_9, tu1.tensor_10);
    node_Gemm_2(tu1.tensor_10, tu0.tensor_11);
    node_Relu_3(tu0.tensor_11, tu1.tensor_12);
    node_Gemm_4(tu1.tensor_12, tu0.tensor_13);
    node_Relu_5(tu0.tensor_13, tu1.tensor_14);
    node_Gemm_6(tu1.tensor_14, tensor_output);
}

int main() {
    float tensor_input[1][5] = {{-1.5f, -1.5f, 0.7853981634f, 1.25f, 1.25f}};
    float tensor_output[1][5];
    
    entry(tensor_input, tensor_output);

    ASSERT(!(tensor_output[0][1] <= 0.14063126799167602f &&
           tensor_output[0][1] >= -0.14063126799167602f &&
           tensor_output[0][2] <= 0.14063126799167602f &&
           tensor_output[0][2] >= -0.14063126799167602f &&
           tensor_output[0][0] >= 0.06360789758578266f));
    
    return 0;
}