#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdint.h>

// Default fixed input values
static const float default_tensor_input[1][4] = {
    {-0.270f, 0.337f, -0.038f, -0.920f}
};

// Function declarations
void entry(const float tensor_input[1][4], float tensor_output[1][2]);
static inline void node_Flatten_0(const float tensor_input[1][4], float tensor_7[1][4]);
static inline void node_Gemm_1(const float tensor_7[1][4], const float tensor_q_net_0_weight[64][4], const float tensor_q_net_0_bias[64], float tensor_8[1][64]);
static inline void node_Relu_2(const float tensor_8[1][64], float tensor_9[1][64]);
static inline void node_Gemm_3(const float tensor_9[1][64], const float tensor_q_net_2_weight[64][64], const float tensor_q_net_2_bias[64], float tensor_10[1][64]);
static inline void node_Relu_4(const float tensor_10[1][64], float tensor_11[1][64]);
static inline void node_Gemm_5(const float tensor_11[1][64], const float tensor_q_net_4_weight[2][64], const float tensor_q_net_4_bias[2], float tensor_output[1][2]);

int main() {
    float tensor_output[1][2];
	
    // Use the fixed input values
    entry(default_tensor_input, tensor_output);

    // Assertion or output
    printf("tensor_output[0][0]: %f\n", tensor_output[0][0]);
    printf("tensor_output[0][1]: %f\n", tensor_output[0][1]);
    return 0;
}

#include <float.h>

#define MAX(X,Y) (X > Y ? X : Y)
#define MIN(X,Y) (X < Y ? X : Y)
#define CLIP(X,L) (MAX(MIN(X,L), -L))

// Model weights and biases
static const float tensor_q_net_0_weight[64][4] = {
    {0.15721032f, 0.114754595f, -0.639938116f, -0.0695108473f},
    {0.175427467f, 0.0373467468f, 0.118049003f, -0.426083267f},
	// ... remaining weights ...
};

static const float tensor_q_net_0_bias[64] = {
    -0.0384809487f, 0.128144249f, 0.492603481f, -0.304650843f,
	// ... remaining biases ...
};

static const float tensor_q_net_2_weight[64][64] = {
    {-0.081372835f, 0.0242487565f, 0.0852197483f, -0.0209310744f, 
	// ... remaining weights ...
};

static const float tensor_q_net_2_bias[64] = {
    0.00965216663f, 0.0336518064f, 0.0397341587f, 0.204491571f,
	// ... remaining biases ...
};

static const float tensor_q_net_4_weight[2][64] = {
    {-0.100038916f, -0.223894686f, -0.248011962f, 0.114980973f,
	// ... remaining weights ...
};

static const float tensor_q_net_4_bias[2] = {0.0201973133f, 0.0008292126f};

union tensor_union_0 {
    float tensor_7[1][4];
    float tensor_9[1][64];
    float tensor_11[1][64];
};

union tensor_union_1 {
    float tensor_8[1][64];
    float tensor_10[1][64];
};

static union tensor_union_0 tu0;
static union tensor_union_1 tu1;

static inline void node_Flatten_0(const float tensor_input[1][4], float tensor_7[1][4]) {
    // Flatten
    for (uint32_t i = 0; i < 4; i++)
        tensor_7[0][i] = tensor_input[0][i];
}

static inline void node_Gemm_1(const float tensor_7[1][4], const float tensor_q_net_0_weight[64][4], const float tensor_q_net_0_bias[64], float tensor_8[1][64]) {
    const int M = 1;
    const int K = 4;
    const int N = 64;
    for (uint32_t r = 0; r < M; r++)
        for (uint32_t c = 0; c < N; c++) {
            float ABrc = 0;
            for (uint32_t i = 0; i < K; i++) {
                ABrc += tensor_7[r][i] * tensor_q_net_0_weight[c][i];
            }
            tensor_8[r][c] = ABrc + tensor_q_net_0_bias[c];
        }
}

static inline void node_Relu_2(const float tensor_8[1][64], float tensor_9[1][64]) {
    for (uint32_t i = 0; i < 64; i++)
        tensor_9[0][i] = (tensor_8[0][i] > 0) ? tensor_8[0][i] : 0;
}

static inline void node_Gemm_3(const float tensor_9[1][64], const float tensor_q_net_2_weight[64][64], const float tensor_q_net_2_bias[64], float tensor_10[1][64]) {
    const int M = 1;
    const int K = 64;
    const int N = 64;
    for (uint32_t r = 0; r < M; r++)
        for (uint32_t c = 0; c < N; c++) {
            float ABrc = 0;
            for (uint32_t i = 0; i < K; i++) {
                ABrc += tensor_9[r][i] * tensor_q_net_2_weight[c][i];
            }
            tensor_10[r][c] = ABrc + tensor_q_net_2_bias[c];
        }
}

static inline void node_Relu_4(const float tensor_10[1][64], float tensor_11[1][64]) {
    for (uint32_t i = 0; i < 64; i++)
        tensor_11[0][i] = (tensor_10[0][i] > 0) ? tensor_10[0][i] : 0;
}

static inline void node_Gemm_5(const float tensor_11[1][64], const float tensor_q_net_4_weight[2][64], const float tensor_q_net_4_bias[2], float tensor_output[1][2]) {
    const int M = 1;
    const int K = 64;
    const int N = 2;
    for (uint32_t r = 0; r < M; r++)
        for (uint32_t c = 0; c < N; c++) {
            float ABrc = 0;
            for (uint32_t i = 0; i < K; i++) {
                ABrc += tensor_11[r][i] * tensor_q_net_4_weight[c][i];
            }
            tensor_output[r][c] = ABrc + tensor_q_net_4_bias[c];
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