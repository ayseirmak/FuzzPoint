#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <assert.h>

// Function prototypes
void entry(const float tensor_input[1][8], float tensor_output[1][4]);

// Tensor shape constants
#define TENSOR_INPUT_SHAPE 8
#define TENSOR_OUTPUT_SHAPE 4
#define TENSOR_HIDDEN_SHAPE 64

// Static data
float tensor_q_net_0_weight[TENSOR_HIDDEN_SHAPE][TENSOR_INPUT_SHAPE] = { /* Initial values omitted for brevity */ };
float tensor_q_net_0_bias[TENSOR_HIDDEN_SHAPE] = { /* Initial values omitted for brevity */ };
float tensor_q_net_2_weight[TENSOR_HIDDEN_SHAPE][TENSOR_HIDDEN_SHAPE] = { /* Initial values omitted for brevity */ };
float tensor_q_net_2_bias[TENSOR_HIDDEN_SHAPE] = { /* Initial values omitted for brevity */ };
float tensor_q_net_4_weight[TENSOR_OUTPUT_SHAPE][TENSOR_HIDDEN_SHAPE] = { /* Initial values omitted for brevity */ };
float tensor_q_net_4_bias[TENSOR_OUTPUT_SHAPE] = { /* Initial values omitted for brevity */ };

// Tensor unions
union tensor_union_0 {
    float tensor_7[1][TENSOR_INPUT_SHAPE];
    float tensor_9[1][TENSOR_HIDDEN_SHAPE];
    float tensor_11[1][TENSOR_HIDDEN_SHAPE];
};
union tensor_union_1 {
    float tensor_8[1][TENSOR_HIDDEN_SHAPE];
    float tensor_10[1][TENSOR_HIDDEN_SHAPE];
};
static union tensor_union_0 tu0;
static union tensor_union_1 tu1;

// Function definitions
static inline void node_Flatten_0(const float tensor_input[1][TENSOR_INPUT_SHAPE], float tensor_7[1][TENSOR_INPUT_SHAPE]) {
    memcpy(tensor_7, tensor_input, sizeof(float) * TENSOR_INPUT_SHAPE);
}

static inline void node_Gemm_1(const float tensor_7[1][TENSOR_INPUT_SHAPE], float tensor_8[1][TENSOR_HIDDEN_SHAPE]) {
    for (int r = 0; r < 1; r++) {
        for (int c = 0; c < TENSOR_HIDDEN_SHAPE; c++) {
            float ABrc = 0;
            for (int i = 0; i < TENSOR_INPUT_SHAPE; i++) {
                ABrc += tensor_7[r][i] * tensor_q_net_0_weight[c][i];
            }
            tensor_8[r][c] = ABrc + tensor_q_net_0_bias[c];
        }
    }
}

static inline void node_Relu_2(const float tensor_8[1][TENSOR_HIDDEN_SHAPE], float tensor_9[1][TENSOR_HIDDEN_SHAPE]) {
    for (int i = 0; i < TENSOR_HIDDEN_SHAPE; i++) {
        tensor_9[0][i] = fmaxf(tensor_8[0][i], 0);
    }
}

static inline void node_Gemm_3(const float tensor_9[1][TENSOR_HIDDEN_SHAPE], float tensor_10[1][TENSOR_HIDDEN_SHAPE]) {
    for (int r = 0; r < 1; r++) {
        for (int c = 0; c < TENSOR_HIDDEN_SHAPE; c++) {
            float ABrc = 0;
            for (int i = 0; i < TENSOR_HIDDEN_SHAPE; i++) {
                ABrc += tensor_9[r][i] * tensor_q_net_2_weight[c][i];
            }
            tensor_10[r][c] = ABrc + tensor_q_net_2_bias[c];
        }
    }
}

static inline void node_Relu_4(const float tensor_10[1][TENSOR_HIDDEN_SHAPE], float tensor_11[1][TENSOR_HIDDEN_SHAPE]) {
    for (int i = 0; i < TENSOR_HIDDEN_SHAPE; i++) {
        tensor_11[0][i] = fmaxf(tensor_10[0][i], 0);
    }
}

static inline void node_Gemm_5(const float tensor_11[1][TENSOR_HIDDEN_SHAPE], float tensor_output[1][TENSOR_OUTPUT_SHAPE]) {
    for (int r = 0; r < 1; r++) {
        for (int c = 0; c < TENSOR_OUTPUT_SHAPE; c++) {
            float ABrc = 0;
            for (int i = 0; i < TENSOR_HIDDEN_SHAPE; i++) {
                ABrc += tensor_11[r][i] * tensor_q_net_4_weight[c][i];
            }
            tensor_output[r][c] = ABrc + tensor_q_net_4_bias[c];
        }
    }
}

void entry(const float tensor_input[1][TENSOR_INPUT_SHAPE], float tensor_output[1][TENSOR_OUTPUT_SHAPE]) {
    node_Flatten_0(tensor_input, tu0.tensor_7);
    node_Gemm_1(tu0.tensor_7, tu1.tensor_8);
    node_Relu_2(tu1.tensor_8, tu0.tensor_9);
    node_Gemm_3(tu0.tensor_9, tu1.tensor_10);
    node_Relu_4(tu1.tensor_10, tu0.tensor_11);
    node_Gemm_5(tu0.tensor_11, tensor_output);
}

int main() {
    float tensor_input[1][TENSOR_INPUT_SHAPE] = {
        {-0.7687555f, 0.025014433f, -3.2973022f, -0.060635928f, -0.059486385f, -0.07658547f, 1.000f, 1.000f},
    };
    float tensor_output[1][TENSOR_OUTPUT_SHAPE];

    entry(tensor_input, tensor_output);

    printf("Tensor output values:\n");
    for (int i = 0; i < TENSOR_OUTPUT_SHAPE; i++) {
        printf("[%d]: %f\n", i, tensor_output[0][i]);
    }

    assert(!(tensor_output[0][2] <= tensor_output[0][3])); // Ensures output condition holds

    return 0;
}