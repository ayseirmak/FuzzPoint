#include <assert.h>
#include <stdio.h>
#include <stdint.h>

// Custom defined functions and tensor data
void entry(const float tensor_input[1][8], float tensor_output[1][4]);

// Declaration of the model's weight and bias tensors
static const float tensor_q_net_0_weight[64][8] = {
    // (Weights input continued)
};

static const float tensor_q_net_0_bias[64] = {
    // (Bias input continued)
};

static const float tensor_q_net_2_weight[64][64] = {
    // (Weights input continued)
};

static const float tensor_q_net_2_bias[64] = {
    // (Bias continued)
};

static const float tensor_q_net_4_weight[4][64] = {
    // (Weights input continued)
};

static const float tensor_q_net_4_bias[4] = {
    // (Bias input continued)
};

// Definition of the function `entry` with its entire internal logic and helper functions
void entry(const float tensor_input[1][8], float tensor_output[1][4]) {
    // Variables representing internal computations and intermediate results
    float tensor_7[1][8];
    float tensor_8[1][64];
    float tensor_9[1][64];
    float tensor_10[1][64];
    float tensor_11[1][64];

    // Flatten
    for (uint32_t i = 0; i < 8; i++) {
        tensor_7[0][i] = tensor_input[0][i];
    }

    // Gemm 1
    for (uint32_t r = 0; r < 1; r++) {
        for (uint32_t c = 0; c < 64; c++) {
            float ABrc = 0;
            for (uint32_t i = 0; i < 8; i++) {
                ABrc += tensor_7[r][i] * tensor_q_net_0_weight[c][i];
            }
            tensor_8[r][c] = ABrc + tensor_q_net_0_bias[c];
        }
    }

    // Relu 2
    for (uint32_t i = 0; i < 64; i++) {
        tensor_9[0][i] = tensor_8[0][i] > 0 ? tensor_8[0][i] : 0;
    }

    // Gemm 3
    for (uint32_t r = 0; r < 1; r++) {
        for (uint32_t c = 0; c < 64; c++) {
            float ABrc = 0;
            for (uint32_t i = 0; i < 64; i++) {
                ABrc += tensor_9[r][i] * tensor_q_net_2_weight[c][i];
            }
            tensor_10[r][c] = ABrc + tensor_q_net_2_bias[c];
        }
    }

    // Relu 4
    for (uint32_t i = 0; i < 64; i++) {
        tensor_11[0][i] = tensor_10[0][i] > 0 ? tensor_10[0][i] : 0;
    }

    // Gemm 5
    for (uint32_t r = 0; r < 1; r++) {
        for (uint32_t c = 0; c < 4; c++) {
            float ABrc = 0;
            for (uint32_t i = 0; i < 64; i++) {
                ABrc += tensor_11[r][i] * tensor_q_net_4_weight[c][i];
            }
            tensor_output[r][c] = ABrc + tensor_q_net_4_bias[c];
        }
    }
}

int main() {
    float tensor_input[1][8] = {
        {-0.7f, 0.05f, -0.01f, 0.03f, 0.05f, 0.001f, 1.0f, 1.0f}
    };
    float tensor_output[1][4];

    entry(tensor_input, tensor_output);

    assert(!((tensor_output[0][3] <= tensor_output[0][2])));

    printf("Computation successful!\n");

    return 0;
}