#include <stdio.h>
#include <math.h>
#include <stdint.h>
#include <assert.h>

// Useful macros
#define MAX(X, Y) ((X) > (Y) ? (X) : (Y))
#define MIN(X, Y) ((X) < (Y) ? (X) : (Y))
#define CLIP(X, L) (MAX(MIN((X), (L)), -(L)))

// Predefined weights and biases (fixed values)
static const float tensor_linear_list_0_weight[32][3] = /*... (input specific fixed values) ... */;
static const float tensor_linear_list_0_bias[32] = /*... (input specific fixed values) ... */;
static const float tensor_linear_list_1_weight[32][32] = /*... (input specific fixed values) ... */;
static const float tensor_linear_list_1_bias[32] = /*... (input specific fixed values) ... */;
static const float tensor_linear_list_2_weight[3][32] = /*... (input specific fixed values) ... */;
static const float tensor_linear_list_2_bias[3] = /*... (input specific fixed values) ... */;

union tensor_union_0 {
    float tensor_7[1][32];
    float tensor_9[1][32];
};

union tensor_union_1 {
    float tensor_8[1][32];
    float tensor_10[1][32];
};

// Declare unions statically
static union tensor_union_0 tu0;
static union tensor_union_1 tu1;

// Function to simulate GEMM 
static inline void node_Gemm_0(const float tensor_input[1][3], float tensor_7[1][32]) {
    const int M = 1;
    const int K = 3;
    const int N = 32;
    float alpha = 1.0;
    float beta = 1.0;

    // Perform the GEMM operation
    for (uint32_t r = 0; r < M; r++) {
        for (uint32_t c = 0; c < N; c++) {
            float ABrc = 0;
            for (uint32_t i = 0; i < K; i++) {
                float B = tensor_linear_list_0_weight[c][i];
                ABrc += tensor_input[r][i] * B;
            }
            float tmp = ABrc * alpha;
            tmp += tensor_linear_list_0_bias[c] * beta;
            tensor_7[r][c] = tmp;
        }
    }
}

// Function to perform ReLU activation
static inline void node_Relu_1(const float tensor_7[1][32], float tensor_8[1][32]) {
    for (uint32_t i = 0; i < 32; i++)
        tensor_8[0][i] = tensor_7[0][i] > 0 ? tensor_7[0][i] : 0;
}

// Entry function that uses the above routines to process the input and update output
void entry(const float tensor_input[1][3], float tensor_output[1][3]) {
    node_Gemm_0(tensor_input, tu0.tensor_7);
    node_Relu_1(tu0.tensor_7, tu1.tensor_8);
    node_Gemm_2(tu1.tensor_8, tensor_linear_list_1_weight, tensor_linear_list_1_bias, tu0.tensor_9);
    node_Relu_3(tu0.tensor_9, tu1.tensor_10);
    node_Gemm_4(tu1.tensor_10, tensor_linear_list_2_weight, tensor_linear_list_2_bias, tensor_output);
}

int main() {
    // Fixed input values, ensuring determinism
    float tensor_input[1][3] = { {1.0f, 1.0f, 1.0f} };
    float tensor_output[1][3];

    // Call the entry function
    entry(tensor_input, tensor_output);

    // Ensure the output meets an assert condition (should be derived from real logic)
    assert(!((tensor_output[0][1] <= 0.534) && (tensor_output[0][1] >= -0.534) && (tensor_output[0][2] <= 0.534) && (tensor_output[0][2] >= -0.534) && (tensor_output[0][0] >= 0.246)));

    return 0;
}