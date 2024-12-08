#include <stdio.h>
#include <stdint.h>

// Function prototypes
void entry(const float tensor_input[1][8], float tensor_output[1][4]);

// Data structures for storing intermediate results
union tensor_union_0 {
    float tensor_7[1][8];
    float tensor_9[1][64];
    float tensor_11[1][64];
};
static union tensor_union_0 tu0;

union tensor_union_1 {
    float tensor_8[1][64];
    float tensor_10[1][64];
};
static union tensor_union_1 tu1;

// Input data for the function
float tensor_input[1][8] = {
    {-0.890527f, 0.055856f, 0.055186f, -0.015944f, -0.408876f, 0.0f, 1.0f, 1.0f}
};
float tensor_output[1][4];

// Flatten node
static inline void node_Flatten_0(const float tensor_input[1][8], float tensor_7[1][8]) {
    /* Flatten */
    float *input = (float*)tensor_input;
    float *output = (float*)tensor_7;
    for (uint32_t i = 0; i < 8; i++) {
        output[i] = input[i];
    }
}

// Gemm node
static inline void node_Gemm_1(const float tensor_7[1][8], const float tensor_q_net_0_weight[64][8], const float tensor_q_net_0_bias[64], float tensor_8[1][64]) {
    const int M = 1;
    const int K = 8;
    const int N = 64;

    for (uint32_t r = 0; r < M; r++) {
        for (uint32_t c = 0; c < N; c++) {
            float ABrc = 0;
            for (uint32_t i = 0; i < K; i++) {
                float B = tensor_q_net_0_weight[c][i];
                ABrc += tensor_7[r][i] * B;
            }
            float tmp = ABrc + tensor_q_net_0_bias[c];
            tensor_8[r][c] = tmp;
        }
    }
}

// ReLU node
static inline void node_Relu_2(const float tensor_8[1][64], float tensor_9[1][64]) {
    for (uint32_t i = 0; i < 64; i++) {
        tensor_9[0][i] = tensor_8[0][i] > 0 ? tensor_8[0][i] : 0;
    }
}

// Another Gemm node for weights and biases
static inline void node_Gemm_3(const float tensor_9[1][64], const float tensor_q_net_2_weight[64][64], const float tensor_q_net_2_bias[64], float tensor_10[1][64]) {
    const int M = 1;
    const int K = 64;
    const int N = 64;

    for (uint32_t r = 0; r < M; r++) {
        for (uint32_t c = 0; c < N; c++) {
            float ABrc = 0;
            for (uint32_t i = 0; i < K; i++) {
                float B = tensor_q_net_2_weight[c][i];
                ABrc += tensor_9[r][i] * B;
            }
            float tmp = ABrc + tensor_q_net_2_bias[c];
            tensor_10[r][c] = tmp;
        }
    }
}

// ReLU node
static inline void node_Relu_4(const float tensor_10[1][64], float tensor_11[1][64]) {
    for (uint32_t i = 0; i < 64; i++) {
        tensor_11[0][i] = tensor_10[0][i] > 0 ? tensor_10[0][i] : 0;
    }
}

// Final Gemm node
static inline void node_Gemm_5(const float tensor_11[1][64], const float tensor_q_net_4_weight[4][64], const float tensor_q_net_4_bias[4], float tensor_output[1][4]) {
    const int M = 1;
    const int K = 64;
    const int N = 4;

    for (uint32_t r = 0; r < M; r++) {
        for (uint32_t c = 0; c < N; c++) {
            float ABrc = 0;
            for (uint32_t i = 0; i < K; i++) {
                float B = tensor_q_net_4_weight[c][i];
                ABrc += tensor_11[r][i] * B;
            }
            float tmp = ABrc + tensor_q_net_4_bias[c];
            tensor_output[r][c] = tmp;
        }
    }
}

// Entry function
void entry(const float tensor_input[1][8], float tensor_output[1][4]) {
    node_Flatten_0(tensor_input, tu0.tensor_7);
    node_Gemm_1(tu0.tensor_7, tensor_q_net_0_weight, tensor_q_net_0_bias, tu1.tensor_8);
    node_Relu_2(tu1.tensor_8, tu0.tensor_9);
    node_Gemm_3(tu0.tensor_9, tensor_q_net_2_weight, tensor_q_net_2_bias, tu1.tensor_10);
    node_Relu_4(tu1.tensor_10, tu0.tensor_11);
    node_Gemm_5(tu0.tensor_11, tensor_q_net_4_weight, tensor_q_net_4_bias, tensor_output);
}

// Main function
int main() {
    // Execute the neural network model on the deterministic input
    entry(tensor_input, tensor_output);

    // Output results for verification, ensuring deterministic outputs
    for (int i = 0; i < 4; i++) {
        printf("Output tensor value at [%d]: %f\n", i, tensor_output[0][i]);
    }

    // Assertion to check the logic of the model
    if (!(tensor_output[0][2] > tensor_output[0][3])) {
        printf("Assertion failed: tensor_output[0][2] is not greater than tensor_output[0][3].\n");
    }

    return 0;
}