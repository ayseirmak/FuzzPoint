#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <assert.h>

// Declaring function prototypes
void entry(const float tensor_input[1][8], float tensor_output[1][4]);

// Helper function prototypes
static inline void node_Flatten_0(const float tensor_input[1][8], float tensor_7[1][8]);
static inline void node_Gemm_1(const float tensor_7[1][8], const float tensor_q_net_0_weight[64][8], const float tensor_q_net_0_bias[64], float tensor_8[1][64]);
static inline void node_Relu_2(const float tensor_8[1][64], float tensor_9[1][64]);
static inline void node_Gemm_3(const float tensor_9[1][64], const float tensor_q_net_2_weight[64][64], const float tensor_q_net_2_bias[64], float tensor_10[1][64]);
static inline void node_Relu_4(const float tensor_10[1][64], float tensor_11[1][64]);
static inline void node_Gemm_5(const float tensor_11[1][64], const float tensor_q_net_4_weight[4][64], const float tensor_q_net_4_bias[4], float tensor_output[1][4]);

// Static data declarations to mimic the original constants (partially shown)
static const float tensor_q_net_0_weight[64][8] = {
    // [Initialize with appropriate values as per the original program]
};
static const float tensor_q_net_0_bias[64] = {
    // [Initialize with appropriate values as per the original program]
};
static const float tensor_q_net_2_weight[64][64] = {
    // [Initialize with appropriate values as per the original program]
};
static const float tensor_q_net_2_bias[64] = {
    // [Initialize with appropriate values as per the original program]
};
static const float tensor_q_net_4_weight[4][64] = {
    // [Initialize with appropriate values as per the original program]
};
static const float tensor_q_net_4_bias[4] = {
    // [Initialize with appropriate values as per the original program]
};

int main() {
    // Initialize tensor input with deterministic values within specified ranges
    float tensor_input[1][8] = {
        {-0.8625, 0.0376, 0.2778, -0.0594, -0.4089, 0.1011, 1.0, 1.0}
    };
    float tensor_output[1][4];

    // Call the entry function
    entry(tensor_input, tensor_output);

    // Assert to replace verifier assertion
    assert(!(tensor_output[0][2] <= tensor_output[0][3]));

    return 0;
}

// Implementation of helper functions
static inline void node_Flatten_0(const float tensor_input[1][8], float tensor_7[1][8]) {
    for (uint32_t i = 0; i < 8; i++) {
        tensor_7[0][i] = tensor_input[0][i];
    }
}

static inline void node_Gemm_1(const float tensor_7[1][8], const float tensor_q_net_0_weight[64][8], const float tensor_q_net_0_bias[64], float tensor_8[1][64]) {
    for (uint32_t i = 0; i < 64; i++) {
        tensor_8[0][i] = tensor_q_net_0_bias[i];
        for (uint32_t j = 0; j < 8; j++) {
            tensor_8[0][i] += tensor_7[0][j] * tensor_q_net_0_weight[i][j];
        }
    }
}

static inline void node_Relu_2(const float tensor_8[1][64], float tensor_9[1][64]) {
    for (uint32_t i = 0; i < 64; i++) {
        tensor_9[0][i] = fmaxf(0, tensor_8[0][i]);
    }
}

static inline void node_Gemm_3(const float tensor_9[1][64], const float tensor_q_net_2_weight[64][64], const float tensor_q_net_2_bias[64], float tensor_10[1][64]) {
    for (uint32_t i = 0; i < 64; i++) {
        tensor_10[0][i] = tensor_q_net_2_bias[i];
        for (uint32_t j = 0; j < 64; j++) {
            tensor_10[0][i] += tensor_9[0][j] * tensor_q_net_2_weight[i][j];
        }
    }
}

static inline void node_Relu_4(const float tensor_10[1][64], float tensor_11[1][64]) {
    for (uint32_t i = 0; i < 64; i++) {
        tensor_11[0][i] = fmaxf(0, tensor_10[0][i]);
    }
}

static inline void node_Gemm_5(const float tensor_11[1][64], const float tensor_q_net_4_weight[4][64], const float tensor_q_net_4_bias[4], float tensor_output[1][4]) {
    for (uint32_t i = 0; i < 4; i++) {
        tensor_output[0][i] = tensor_q_net_4_bias[i];
        for (uint32_t j = 0; j < 64; j++) {
            tensor_output[0][i] += tensor_11[0][j] * tensor_q_net_4_weight[i][j];
        }
    }
}