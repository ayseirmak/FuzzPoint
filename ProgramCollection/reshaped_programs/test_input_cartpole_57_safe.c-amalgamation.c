#include <stdio.h>   // For printf
#include <assert.h>  // For assert
#include <stdint.h>  // For fixed-width integers
#include <math.h>

// You provided constants like tensor_q_net_0_weight, tensor_q_net_0_bias, etc. 
// Assuming they are already defined as part of the includes above.

// Forward declaration of the entry function
void entry(const float tensor_input[1][4], float tensor_output[1][2]);

int main() {
    // Initialize the input tensor with deterministic values according to __VERIFIER_assume constraints 
    float tensor_input[1][4] = {
        {-0.2792921f, -0.053f, -0.025f, -0.334f}  // Example values within the given constraints
    };
    
    float tensor_output[1][2];

    // Call the entry function that performs operations on the input and outputs to tensor_output
    entry(tensor_input, tensor_output);

    // Assert to verify the condition as per the original code's logic
    // Initially: __VERIFIER_assert(!((tensor_output[0][1] <= tensor_output[0][0])));
    // Translated to use assert in C which halts the program in case of failure.
    // Check that tensor_output[0][1] should be greater than tensor_output[0][0]
    assert(tensor_output[0][1] > tensor_output[0][0]);

    printf("Output tensor: [%f, %f]\n", tensor_output[0][0], tensor_output[0][1]);
    return 0;
}

// Definitions of the node functions mentioned in the ONNX model
static inline void node_Flatten_0(const float tensor_input[1][4], float tensor_7[1][4]) {
    // This implementation logic remains similar as per your SPUC benchmark to preserve the functional behavior.
    float *input = (float*) tensor_input;
    float *output = (float*) tensor_7;
    for(uint32_t i = 0; i < 4; i++)
        output[i] = input[i];
}

static inline void node_Gemm_1(const float tensor_7[1][4], const float tensor_q_net_0_weight[64][4], const float tensor_q_net_0_bias[64], float tensor_8[1][64]) {
    const int M = 1, K = 4, N = 64;
    float alpha = 1.0f, beta = 1.0f;
    float (*A)[4] = (float (*)[4]) tensor_7;
    float (*Y)[64] = (float (*)[64]) tensor_8;
    float (*C)[64] = (float (*)[64]) tensor_q_net_0_bias;
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

static inline void node_Relu_2(const float tensor_8[1][64], float tensor_9[1][64]) {
    float *X = (float*) tensor_8;
    float *Y = (float*) tensor_9;
    for(uint32_t i = 0; i < 64; i++)
        Y[i] = X[i] > 0 ? X[i] : 0;
}

// Similar node_Gemm_2, node_Relu_3, node_Gemm_4...

void entry(const float tensor_input[1][4], float tensor_output[1][2]) {
    union {
        float tensor_7[1][4];
        float tensor_9[1][64];
        float tensor_11[1][64];
    } tu0;

    union {
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