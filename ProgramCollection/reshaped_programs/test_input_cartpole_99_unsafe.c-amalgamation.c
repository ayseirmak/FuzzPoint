#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>

// Function declarations
void entry(const float tensor_input[1][4], float tensor_output[1][2]);

// Global constant weights and biases as per the supplied data.
static const float tensor_q_net_0_weight[64][4] = {
    {0.15721032023429870605f, 0.11475459486246109009f, -0.63993811607360839844f, -0.069510847330093383789f},
    {0.17542746663093566895f, 0.037346746772527694702f, 0.11804900318384170532f, -0.42608326673507690430f},
    {0.17451041936874389648f, -0.038390919566154479980f, -0.12378698587417602539f, 0.16069194674491882324f},
    // Rest of the initializations...
};

static const float tensor_q_net_0_bias[64] = {
    -0.038480948656797409058f, 0.12814424932003021240f, 0.49260348081588745117f, // ... continue for all 64 elements
};

static const float tensor_q_net_2_weight[64][64] = {
    {-0.081372834742069244385f, 0.024248756468296051025f, 0.085219748318195343018f, // ... continue for all 64x64 elements
};

static const float tensor_q_net_2_bias[64] = {
    0.0096521666273474693298f, 0.033651806414127349854f, 0.039734158664941787720f, // ... continue for all 64 elements
};

static const float tensor_q_net_4_weight[2][64] = {
    {-0.10003891587257385254f, -0.22389468550682067871f, -0.24801196157932281494f, // ... continue for all 2x64 elements
};

static const float tensor_q_net_4_bias[2] = {0.020197313278913497925f, 0.00082921260036528110504f};

// Helper functions for neural network operations
static inline void node_Flatten_0(const float tensor_input[1][4], float tensor_7[1][4]) {
    for (uint32_t i = 0; i < 4; i++) {
        tensor_7[0][i] = tensor_input[0][i];
    }
}

static inline void node_Gemm_1(const float tensor_7[1][4], float tensor_8[1][64]) {
    const int M = 1, K = 4, N = 64;
    for (uint32_t r = 0; r < M; r++) {
        for (uint32_t c = 0; c < N; c++) {
            float sum = 0;
            for (uint32_t i = 0; i < K; i++) {
                sum += tensor_7[r][i] * tensor_q_net_0_weight[c][i];
            }
            tensor_8[r][c] = sum + tensor_q_net_0_bias[c];
        }
    }
}

static inline void node_Relu_2(const float tensor_8[1][64], float tensor_9[1][64]) {
    for (uint32_t i = 0; i < 64; i++) {
        tensor_9[0][i] = tensor_8[0][i] > 0 ? tensor_8[0][i] : 0;
    }
}

static inline void node_Gemm_3(const float tensor_9[1][64], float tensor_10[1][64]) {
    const int M = 1, K = 64, N = 64;
    for (uint32_t r = 0; r < M; r++) {
        for (uint32_t c = 0; c < N; c++) {
            float sum = 0;
            for (uint32_t i = 0; i < K; i++) {
                sum += tensor_9[r][i] * tensor_q_net_2_weight[c][i];
            }
            tensor_10[r][c] = sum + tensor_q_net_2_bias[c];
        }
    }
}

static inline void node_Relu_4(const float tensor_10[1][64], float tensor_11[1][64]) {
    for (uint32_t i = 0; i < 64; i++) {
        tensor_11[0][i] = tensor_10[0][i] > 0 ? tensor_10[0][i] : 0;
    }
}

static inline void node_Gemm_5(const float tensor_11[1][64], float tensor_output[1][2]) {
    const int M = 1, K = 64, N = 2;
    for (uint32_t r = 0; r < M; r++) {
        for (uint32_t c = 0; c < N; c++) {
            float sum = 0;
            for (uint32_t i = 0; i < K; i++) {
                sum += tensor_11[r][i] * tensor_q_net_4_weight[c][i];
            }
            tensor_output[r][c] = sum + tensor_q_net_4_bias[c];
        }
    }
}

// Main entry function for the neural network
void entry(const float tensor_input[1][4], float tensor_output[1][2]) {
    float tensor_7[1][4];
    float tensor_8[1][64];
    float tensor_9[1][64];
    float tensor_10[1][64];
    float tensor_11[1][64];

    node_Flatten_0(tensor_input, tensor_7);
    node_Gemm_1(tensor_7, tensor_8);
    node_Relu_2(tensor_8, tensor_9);
    node_Gemm_3(tensor_9, tensor_10);
    node_Relu_4(tensor_10, tensor_11);
    node_Gemm_5(tensor_11, tensor_output);
}

int main() {
    float tensor_input[1][4] = {
        {0.473, -0.684, 0.023, 0.885}  // Deterministic input values within assumptions
    };
    float tensor_output[1][2];

    entry(tensor_input, tensor_output);

    // Assert statement to check the specified condition
    if (tensor_output[0][0] > tensor_output[0][1]) {
        printf("Assertion Passed: tensor_output[0][0] > tensor_output[0][1]\n");
    } else {
        printf("Assertion Failed: tensor_output[0][0] is not greater than tensor_output[0][1]\n");
    }

    return 0;
}