#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdint.h>

// Functions declaration and static data
void entry(const float tensor_input[1][4], float tensor_output[1][2]);

// Helper functions for tensor operations (implementations omitted for brevity)
static void node_Flatten_0(const float tensor_input[1][4], float tensor_7[1][4]);
static void node_Gemm_1(const float tensor_7[1][4], const float tensor_q_net_0_weight[64][4], const float tensor_q_net_0_bias[64], float tensor_8[1][64]);
static void node_Relu_2(const float tensor_8[1][64], float tensor_9[1][64]);
static void node_Gemm_3(const float tensor_9[1][64], const float tensor_q_net_2_weight[64][64], const float tensor_q_net_2_bias[64], float tensor_10[1][64]);
static void node_Relu_4(const float tensor_10[1][64], float tensor_11[1][64]);
static void node_Gemm_5(const float tensor_11[1][64], const float tensor_q_net_4_weight[2][64], const float tensor_q_net_4_bias[2], float tensor_output[1][2]);

int main() {
    float tensor_input[1][4];
    float tensor_output[1][2];
    
    tensor_input[0][0] = -0.245f; // Deterministic values within specified ranges
    tensor_input[0][1] = 0.14f;
    tensor_input[0][2] = -0.05f;
    tensor_input[0][3] = -0.62f;
    
    entry(tensor_input, tensor_output);
    
    printf("Output Tensor: [%.5f, %.5f]\n", tensor_output[0][0], tensor_output[0][1]);
    
    assert(!(tensor_output[0][0] <= tensor_output[0][1]));
    
    return 0;
}

// Including the complete implementation of entry function and other helper functions
void entry(const float tensor_input[1][4], float tensor_output[1][2]) {
    static union {
        float tensor_7[1][4];
        float tensor_9[1][64];
        float tensor_11[1][64];
    } tu0;

    static union {
        float tensor_8[1][64];
        float tensor_10[1][64];
    } tu1;

    node_Flatten_0(tensor_input, tu0.tensor_7);
    node_Gemm_1(tu0.tensor_7, tensor_q_net_0_weight, tensor_q_net_0_bias, tu1.tensor_8);
    node_Relu_2(tu1.tensor_8, tu0.tensor_9);
    node_Gemm_3(tu0.tensor_9, tensor_q_net_2_weight, tensor_q_net_2_bias, tu1.tensor_10);
    node_Relu_4(tu1.tensor_10, tu0.tensor_11);
    node_Gemm_5(tu0.tensor_11, tensor_q_net_4_weight, tensor_q_net_4_bias, tensor_output);
}

// Assume the static arrays like tensor_q_net_0_weight, tensor_q_net_0_bias, etc are already defined elsewhere.