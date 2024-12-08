#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

// Function declarations for the neural network layers
void entry(const float tensor_input[1][8], float tensor_output[1][4]);

int main() {
    float tensor_input[1][8];
    float tensor_output[1][4];

    // Deterministic fixed input values within the assumed range
    tensor_input[0][0] = -0.75f;
    tensor_input[0][1] = 0.07f;
    tensor_input[0][2] = 0.02f;
    tensor_input[0][3] = -0.03f;
    tensor_input[0][4] = -0.115f;
    tensor_input[0][5] = -0.056f;
    tensor_input[0][6] = 0.0f;
    tensor_input[0][7] = 1.0f;

    // Process through the neural network
    entry(tensor_input, tensor_output);

    // Validate the output according to the original assertion condition
    assert(!(tensor_output[0][2] <= tensor_output[0][3]));

    // Output result for verification
    printf("tensor_output: [%f, %f, %f, %f]\n", tensor_output[0][0], tensor_output[0][1], tensor_output[0][2], tensor_output[0][3]);

    return 0;
}

// Neural network function definitions

static inline void node_Flatten_0(const float input[1][8], float output[1][8]) {
    for (uint32_t i = 0; i < 8; i++) 
        output[0][i] = input[0][i];
}

static inline void node_Gemm_1(const float input[1][8], const float weight[64][8], const float bias[64], float output[1][64]) {
    memset(output, 0, sizeof(float) * 64);
    for (int c = 0; c < 64; c++) {
        for (int i = 0; i < 8; i++) {
            output[0][c] += input[0][i] * weight[c][i];
        }
        output[0][c] += bias[c];
    }
}

static inline void node_Relu_2(const float input[1][64], float output[1][64]) {
    for (int i = 0; i < 64; i++) 
        output[0][i] = fmaxf(0, input[0][i]);
}

static inline void node_Gemm_3(const float input[1][64], const float weight[64][64], const float bias[64], float output[1][64]) {
    memset(output, 0, sizeof(float) * 64);
    for (int c = 0; c < 64; c++) {
        for (int i = 0; i < 64; i++) {
            output[0][c] += input[0][i] * weight[c][i];
        }
        output[0][c] += bias[c];
    }
}

static inline void node_Relu_4(const float input[1][64], float output[1][64]) {
    for (int i = 0; i < 64; i++) 
        output[0][i] = fmaxf(0, input[0][i]);
}

static inline void node_Gemm_5(const float input[1][64], const float weight[4][64], const float bias[4], float output[1][4]) {
    memset(output, 0, sizeof(float) * 4);
    for (int c = 0; c < 4; c++) {
        for (int i = 0; i < 64; i++) {
            output[0][c] += input[0][i] * weight[c][i];
        }
        output[0][c] += bias[c];
    }
}

void entry(const float tensor_input[1][8], float tensor_output[1][4]) {
    float layer1_out[1][64];
    float layer2_out[1][64];
    float layer3_out[1][64];
    
    node_Flatten_0(tensor_input, tensor_input);
    node_Gemm_1(tensor_input, tensor_q_net_0_weight, tensor_q_net_0_bias, layer1_out);
    node_Relu_2(layer1_out, layer2_out);
    node_Gemm_3(layer2_out, tensor_q_net_2_weight, tensor_q_net_2_bias, layer3_out);
    node_Relu_4(layer3_out, layer3_out);  // Reuse layer3_out for inplace
    node_Gemm_5(layer3_out, tensor_q_net_4_weight, tensor_q_net_4_bias, tensor_output);
}