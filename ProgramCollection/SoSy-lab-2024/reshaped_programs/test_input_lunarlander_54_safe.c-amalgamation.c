#include <stdio.h>
#include <math.h>
#include <stdint.h>
#include <assert.h>

static const float tensor_q_net_0_weight[64][8] = {
    // Matrix values
};

static const float tensor_q_net_0_bias[64] = {
    // Bias values
};

static const float tensor_q_net_2_weight[64][64] = {
    // Matrix values
};

static const float tensor_q_net_2_bias[64] = {
    // Bias values
};

static const float tensor_q_net_4_weight[4][64] = {
    // Matrix values
};

static const float tensor_q_net_4_bias[4] = {
    // Bias values
};

void entry(const float tensor_input[1][8], float tensor_output[1][4]) {
    float tensor_7[1][8];
    float tensor_8[1][64];
    float tensor_9[1][64];
    float tensor_10[1][64];
    float tensor_11[1][64];

    // Flatten operation
    for (uint32_t i = 0; i < 8; i++)
        tensor_7[0][i] = tensor_input[0][i];

    // Gemm operation 1
    for (uint32_t c = 0; c < 64; c++) {
        float sum = 0.0f;
        for (uint32_t i = 0; i < 8; i++) {
            sum += tensor_7[0][i] * tensor_q_net_0_weight[c][i];
        }
        tensor_8[0][c] = sum + tensor_q_net_0_bias[c];
    }

    // ReLU operation
    for (uint32_t i = 0; i < 64; i++)
        tensor_9[0][i] = fmax(0, tensor_8[0][i]);

    // Gemm operation 2
    for (uint32_t c = 0; c < 64; c++) {
        float sum = 0.0f;
        for (uint32_t i = 0; i < 64; i++) {
            sum += tensor_9[0][i] * tensor_q_net_2_weight[c][i];
        }
        tensor_10[0][c] = sum + tensor_q_net_2_bias[c];
    }

    // ReLU operation
    for (uint32_t i = 0; i < 64; i++)
        tensor_11[0][i] = fmax(0, tensor_10[0][i]);

    // Gemm operation 3
    for (uint32_t c = 0; c < 4; c++) {
        float sum = 0.0f;
        for (uint32_t i = 0; i < 64; i++) {
            sum += tensor_11[0][i] * tensor_q_net_4_weight[c][i];
        }
        tensor_output[0][c] = sum + tensor_q_net_4_bias[c];
    }
}

int main() {
    float tensor_input[1][8] = {
        {-0.7, 0.05, 0.015, 0.06, -0.09, 0.1, 1.0, 1.0}
    };

    float tensor_output[1][4];

    entry(tensor_input, tensor_output);

    assert(!(tensor_output[0][3] <= tensor_output[0][2]));

    for (int i = 0; i < 4; i++) {
        printf("Output[%d]: %f\n", i, tensor_output[0][i]);
    }

    return 0;
}