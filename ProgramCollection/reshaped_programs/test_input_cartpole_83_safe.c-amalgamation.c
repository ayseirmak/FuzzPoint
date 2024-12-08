#include <stdio.h>
#include <assert.h>
#include <float.h>

// Function declarations for entry and the internal nodes
void entry(const float tensor_input[1][4], float tensor_output[1][2]);

// Pre-defined constants used in the program
static const float tensor_q_net_0_weight[64][4] = {/*... initialized as in the provided code ...*/};
static const float tensor_q_net_0_bias[64] = {/*... initialized as in the provided code ...*/};
static const float tensor_q_net_2_weight[64][64] = {/*... initialized as in the provided code ...*/};
static const float tensor_q_net_2_bias[64] = {/*... initialized as in the provided code ...*/};
static const float tensor_q_net_4_weight[2][64] = {/*... initialized as in the provided code ...*/};
static const float tensor_q_net_4_bias[2] = {0.020197313278913497925f, 0.00082921260036528110504f};

// Function implementing Flatten operation
static inline void node_Flatten_0(const float tensor_input[1][4], float tensor_7[1][4]) {
    for (uint32_t i = 0; i < 4; i++) {
        tensor_7[0][i] = tensor_input[0][i];
    }
}

// Function implementing Gemm operation
static inline void node_Gemm_1(const float tensor_7[1][4], const float tensor_q_net_0_weight[64][4], const float tensor_q_net_0_bias[64], float tensor_8[1][64]) {
    const int M = 1;
    const int K = 4;
    const int N = 64;
    
    for (uint32_t r = 0; r < M; r++){
        for (uint32_t c = 0; c < N; c++) {
            float sum = tensor_q_net_0_bias[c];
            for (uint32_t i = 0; i < K; i++) {
                sum += tensor_7[r][i] * tensor_q_net_0_weight[c][i];
            }
            tensor_8[r][c] = sum;
        }
    }
}

// Add implementations for node_Relu_2, node_Gemm_3, node_Relu_4 and node_Gemm_5 
// similar to above by adapting from the provided code

// Main entry point function implementing the defined neural network
void entry(const float tensor_input[1][4], float tensor_output[1][2]) {
    float tensor_7[1][4], tensor_8[1][64], tensor_9[1][64], tensor_10[1][64], tensor_11[1][64];
    node_Flatten_0(tensor_input, tensor_7);
    node_Gemm_1(tensor_7, tensor_q_net_0_weight, tensor_q_net_0_bias, tensor_8);
    // Call further neural network operations here

}

// The main function of the program
int main() {
    float tensor_input[1][4] = {
        {-0.25569498f, -0.05151152f, -0.06144235f, -0.36756095f}  // Fixed deterministic values
    };
    float tensor_output[1][2];

    entry(tensor_input, tensor_output);
    
    // Use assert to replace the verifier assert
    assert(!(tensor_output[0][0] <= tensor_output[0][1]));

    printf("Program executed successfully.\n");
    return 0;
}