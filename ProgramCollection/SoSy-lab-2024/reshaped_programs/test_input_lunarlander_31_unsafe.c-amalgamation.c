#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <math.h>

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

static const float tensor_q_net_0_weight[64][8] = {
    // ... (initialize with given tensor_q_net_0_weight values)
};

static const float tensor_q_net_0_bias[64] = {
    // ... (initialize with given tensor_q_net_0_bias values)
};

static const float tensor_q_net_2_weight[64][64] = {
    // ... (initialize with given tensor_q_net_2_weight values)
};

static const float tensor_q_net_2_bias[64] = {
    // ... (initialize with given tensor_q_net_2_bias values)
};

static const float tensor_q_net_4_weight[4][64] = {
    // ... (initialize with given tensor_q_net_4_weight values)
};

static const float tensor_q_net_4_bias[4] = {
    // ... (initialize with given tensor_q_net_4_bias values)
};

static void node_Flatten_0(const float tensor_input[1][8], float tensor_7[1][8]) {
    for(uint32_t i = 0; i < 8; i++) {
        tensor_7[0][i] = tensor_input[0][i];
    }
}

static void node_Gemm_1(const float tensor_7[1][8], const float tensor_q_net_0_weight[64][8], const float tensor_q_net_0_bias[64], float tensor_8[1][64]) {
    for(uint32_t c = 0; c < 64; c++) {
        float sum = 0;
        for(uint32_t i = 0; i < 8; i++) {
            sum += tensor_7[0][i] * tensor_q_net_0_weight[c][i];
        }
        tensor_8[0][c] = sum + tensor_q_net_0_bias[c];
    }
}

static void node_Relu_2(const float tensor_8[1][64], float tensor_9[1][64]) {
    for(uint32_t i = 0; i < 64; i++) {
        tensor_9[0][i] = fmaxf(0, tensor_8[0][i]);
    }
}

static void node_Gemm_3(const float tensor_9[1][64], const float tensor_q_net_2_weight[64][64], const float tensor_q_net_2_bias[64], float tensor_10[1][64]) {
    for(uint32_t c = 0; c < 64; c++) {
        float sum = 0;
        for(uint32_t i = 0; i < 64; i++) {
            sum += tensor_9[0][i] * tensor_q_net_2_weight[c][i];
        }
        tensor_10[0][c] = sum + tensor_q_net_2_bias[c];
    }
}

static void node_Relu_4(const float tensor_10[1][64], float tensor_11[1][64]) {
    for(uint32_t i = 0; i < 64; i++) {
        tensor_11[0][i] = fmaxf(0, tensor_10[0][i]);
    }
}

static void node_Gemm_5(const float tensor_11[1][64], const float tensor_q_net_4_weight[4][64], const float tensor_q_net_4_bias[4], float tensor_output[1][4]) {
    for(uint32_t c = 0; c < 4; c++) {
        float sum = 0;
        for(uint32_t i = 0; i < 64; i++) {
            sum += tensor_11[0][i] * tensor_q_net_4_weight[c][i];
        }
        tensor_output[0][c] = sum + tensor_q_net_4_bias[c];
    }
}

void entry(const float tensor_input[1][8], float tensor_output[1][4]) {
    node_Flatten_0(tensor_input, tu0.tensor_7);
    node_Gemm_1(tu0.tensor_7, tensor_q_net_0_weight, tensor_q_net_0_bias, tu1.tensor_8);
    node_Relu_2(tu1.tensor_8, tu0.tensor_9);
    node_Gemm_3(tu0.tensor_9, tensor_q_net_2_weight, tensor_q_net_2_bias, tu1.tensor_10);
    node_Relu_4(tu1.tensor_10, tu0.tensor_11);
    node_Gemm_5(tu0.tensor_11, tensor_q_net_4_weight, tensor_q_net_4_bias, tensor_output);
}

int main() {
    float tensor_input[1][8] = {{-0.8426, 0.0777, 0.0273, -0.0342, 0.0418, -0.0116, 1.0, 1.0}};
    float tensor_output[1][4];

    entry(tensor_input, tensor_output);

    for(int i = 0; i < 4; i++) {
        printf("Output %d: %f\n", i, tensor_output[0][i]);
    }

    bool assertion = tensor_output[0][2] > tensor_output[0][3];
    if (!assertion) {
        printf("Assertion failed: tensor_output[0][2] should be greater than tensor_output[0][3]\n");
    } else {
        printf("Assertion passed.\n");
    }

    return 0;
}