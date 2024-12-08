#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <float.h>
#include <math.h>
#include <stdint.h>
#include <string.h>

// Function declarations
void entry(const float tensor_input[1][14], float tensor_output[1][14]);

// Utility macros
#define MAX(X,Y) ( X > Y ? X : Y)
#define MIN(X,Y) ( X < Y ? X : Y)
#define CLIP(X,L) ( MAX(MIN(X,L), -L) )

// Predefined constants (weights and biases)
static const float tensor_linear_list_0_weight[32][14] = {/*...*/};
static const float tensor_linear_list_0_bias[32] = {/*...*/};
static const float tensor_linear_list_1_weight[32][32] = {/*...*/};
static const float tensor_linear_list_1_bias[32] = {/*...*/};
static const float tensor_linear_list_2_weight[14][32] = {/*...*/};
static const float tensor_linear_list_2_bias[14] = {/*...*/};

// Initialize fixed deterministic input
float initializedTensorInput[1][14] = {
    {-1.0f, 1.0f, 0.0f, 0.5f, 4.0f, -4.0f, 3.0f, -3.0f, 2.0f, -2.0f, 1.5f, -1.5f, 0.25f, 3.0f}
};

int main() {
    float tensor_output[1][14] = {0};

    // Ensure the inputs are within the specified range
    assert((initializedTensorInput[0][0] >= -1.7492930226200185f) && (initializedTensorInput[0][0] <= 1.7312612073369356f));
    assert((initializedTensorInput[0][1] >= -1.7306896924315087f) && (initializedTensorInput[0][1] <= 1.7194907929960244f));
    // ... (add more assertions as needed for each input index)

    entry(initializedTensorInput, tensor_output);

    // This assertion reflects the original verifier assert function call
    assert(!((tensor_output[0][12] <= -2.2838113986655717) && (tensor_output[0][0] >= -0.0)));

    printf("Assertion passed, program completed successfully.\n");
    return 0;
}

// Union for intermediate tensor values
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

// Neural network computation functions (actual computation code remains unchanged)
static inline void node_Gemm_0(const float tensor_input[1][14], const float tensor_linear_list_0_weight[32][14], const float tensor_linear_list_0_bias[32], float tensor_7[1][32]) {/*...*/}
static inline void node_Relu_1(const float tensor_7[1][32], float tensor_8[1][32]) {/*...*/}
static inline void node_Gemm_2(const float tensor_8[1][32], const float tensor_linear_list_1_weight[32][32], const float tensor_linear_list_1_bias[32], float tensor_9[1][32]) {/*...*/}
static inline void node_Relu_3(const float tensor_9[1][32], float tensor_10[1][32]) {/*...*/}
static inline void node_Gemm_4(const float tensor_10[1][32], const float tensor_linear_list_2_weight[14][32], const float tensor_linear_list_2_bias[14], float tensor_output[1][14]) {/*...*/}

// Entry Point
void entry(const float tensor_input[1][14], float tensor_output[1][14]) {
    node_Gemm_0(tensor_input, tensor_linear_list_0_weight, tensor_linear_list_0_bias, tu0.tensor_7);
    node_Relu_1(tu0.tensor_7, tu1.tensor_8);
    node_Gemm_2(tu1.tensor_8, tensor_linear_list_1_weight, tensor_linear_list_1_bias, tu0.tensor_9);
    node_Relu_3(tu0.tensor_9, tu1.tensor_10);
    node_Gemm_4(tu1.tensor_10, tensor_linear_list_2_weight, tensor_linear_list_2_bias, tensor_output);
}