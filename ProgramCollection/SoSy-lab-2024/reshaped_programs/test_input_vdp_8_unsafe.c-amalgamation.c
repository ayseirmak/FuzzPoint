#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>

#define MAX(X,Y) ((X) > (Y) ? (X) : (Y))
#define MIN(X,Y) ((X) < (Y) ? (X) : (Y))
#define CLIP(X,L) (MAX(MIN(X,L), -(L)))

static const float tensor_linear_list_0_weight[32][3] = { /* Initialized values */ };
static const float tensor_linear_list_0_bias[32] = { /* Initialized values */ };
static const float tensor_linear_list_1_weight[32][32] = { /* Initialized values */ };
static const float tensor_linear_list_1_bias[32] = { /* Initialized values */ };
static const float tensor_linear_list_2_weight[3][32] = { /* Initialized values */ };
static const float tensor_linear_list_2_bias[3] = { /* Initialized values */ };

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

// Function declarations
void entry(const float tensor_input[1][3], float tensor_output[1][3]);
void node_Gemm_0(const float tensor_input[1][3], const float tensor_linear_list_0_weight[32][3], const float tensor_linear_list_0_bias[32], float tensor_7[1][32]);
void node_Relu_1(const float tensor_7[1][32], float tensor_8[1][32]);
void node_Gemm_2(const float tensor_8[1][32], const float tensor_linear_list_1_weight[32][32], const float tensor_linear_list_1_bias[32], float tensor_9[1][32]);
void node_Relu_3(const float tensor_9[1][32], float tensor_10[1][32]);
void node_Gemm_4(const float tensor_10[1][32], const float tensor_linear_list_2_weight[3][32], const float tensor_linear_list_2_bias[3], float tensor_output[1][3]);

int main() {
    float tensor_input[1][3];
    float tensor_output[1][3];

    // Deterministic values for tensor_input
    tensor_input[0][0] = 1.0f;
    tensor_input[0][1] = -1.5f;
    tensor_input[0][2] = 2.5f;

    // Ensuring the input meets the original assumption
    if (!(tensor_input[0][0] >= -2.5f && tensor_input[0][0] <= 2.5f &&
          tensor_input[0][1] >= -2.5f && tensor_input[0][1] <= 2.5f &&
          tensor_input[0][2] >= 0.0f && tensor_input[0][2] <= 5.0f)) {
        printf("Error: Input assumptions violated.\n");
        return 1;
    }

    entry(tensor_input, tensor_output);

    // Assert condition
    assert(!((tensor_output[0][1] <= 0.48872420142346396) 
          && (tensor_output[0][1] >= -0.48872420142346396) 
          && (tensor_output[0][2] <= 0.48872420142346396) 
          && (tensor_output[0][2] >= -0.48872420142346396) 
          && (tensor_output[0][0] >= 0.17218106899686667)));

    return 0;
}

// Implement the node functions as in the original code
void node_Gemm_0(const float tensor_input[1][3], const float tensor_linear_list_0_weight[32][3], const float tensor_linear_list_0_bias[32], float tensor_7[1][32]) {
    // Gemm operation implementation
}

void node_Relu_1(const float tensor_7[1][32], float tensor_8[1][32]) {
    // Relu operation implementation
}

void node_Gemm_2(const float tensor_8[1][32], const float tensor_linear_list_1_weight[32][32], const float tensor_linear_list_1_bias[32], float tensor_9[1][32]) {
    // Gemm operation implementation
}

void node_Relu_3(const float tensor_9[1][32], float tensor_10[1][32]) {
    // Relu operation implementation
}

void node_Gemm_4(const float tensor_10[1][32], const float tensor_linear_list_2_weight[3][32], const float tensor_linear_list_2_bias[3], float tensor_output[1][3]) {
    // Gemm operation implementation
}

void entry(const float tensor_input[1][3], float tensor_output[1][3]) {
    node_Gemm_0(tensor_input, tensor_linear_list_0_weight, tensor_linear_list_0_bias, tu0.tensor_7);
    node_Relu_1(tu0.tensor_7, tu1.tensor_8);
    node_Gemm_2(tu1.tensor_8, tensor_linear_list_1_weight, tensor_linear_list_1_bias, tu0.tensor_9);
    node_Relu_3(tu0.tensor_9, tu1.tensor_10);
    node_Gemm_4(tu1.tensor_10, tensor_linear_list_2_weight, tensor_linear_list_2_bias, tensor_output);
}