#include <stdio.h>
#include <assert.h>

// Forward declaration of the entry function
void entry(const float tensor_input[1][4], float tensor_output[1][2]);

int main()
{
    // Initialize input and output tensors
    float tensor_input[1][4];
    float tensor_output[1][2];

    // Set deterministic values for tensor_input
    tensor_input[0][0] = -0.25316144f;  // A value within the specified range
    tensor_input[0][1] = 0.14139313f;   // A value within the specified range
    tensor_input[0][2] = -0.04145561f;  // A value within the specified range
    tensor_input[0][3] = -0.61110246f;  // A value within the specified range

    // Call the entry function
    entry(tensor_input, tensor_output);

    // Assert the condition that should hold true according to the original logic
    assert(!(tensor_output[0][0] <= tensor_output[0][1]));

    return 0;
}

// The entry function and its dependencies
union tensor_union_0 {
    float tensor_7[1][4];
    float tensor_9[1][64];
    float tensor_11[1][64];
};

union tensor_union_1 {
    float tensor_8[1][64];
    float tensor_10[1][64];
};

static union tensor_union_0 tu0;
static union tensor_union_1 tu1;

// Function prototypes
static inline void node_Flatten_0(const float tensor_input[1][4], float tensor_7[1][4]);
static inline void node_Gemm_1(const float tensor_7[1][4], const float tensor_q_net_0_weight[64][4], const float tensor_q_net_0_bias[64], float tensor_8[1][64]);
static inline void node_Relu_2(const float tensor_8[1][64], float tensor_9[1][64]);
static inline void node_Gemm_3(const float tensor_9[1][64], const float tensor_q_net_2_weight[64][64], const float tensor_q_net_2_bias[64], float tensor_10[1][64]);
static inline void node_Relu_4(const float tensor_10[1][64], float tensor_11[1][64]);
static inline void node_Gemm_5(const float tensor_11[1][64], const float tensor_q_net_4_weight[2][64], const float tensor_q_net_4_bias[2], float tensor_output[1][2]);

static inline void node_Flatten_0(const float tensor_input[1][4], float tensor_7[1][4]) {
    for (uint32_t i = 0; i < 4; i++)
        tensor_7[0][i] = tensor_input[0][i];
}

static inline void node_Gemm_1(const float tensor_7[1][4], const float tensor_q_net_0_weight[64][4], const float tensor_q_net_0_bias[64], float tensor_8[1][64]) {
    for (uint32_t c = 0; c < 64; c++) {
        float result = 0.0f;
        for (uint32_t i = 0; i < 4; i++) {
            result += tensor_7[0][i] * tensor_q_net_0_weight[c][i];
        }
        tensor_8[0][c] = result + tensor_q_net_0_bias[c];
    }
}

static inline void node_Relu_2(const float tensor_8[1][64], float tensor_9[1][64]) {
    for (uint32_t i = 0; i < 64; i++) {
        tensor_9[0][i] = tensor_8[0][i] > 0 ? tensor_8[0][i] : 0.0f;
    }
}

static inline void node_Gemm_3(const float tensor_9[1][64], const float tensor_q_net_2_weight[64][64], const float tensor_q_net_2_bias[64], float tensor_10[1][64]) {
    for (uint32_t c = 0; c < 64; c++) {
        float result = 0.0f;
        for (uint32_t i = 0; i < 64; i++) {
            result += tensor_9[0][i] * tensor_q_net_2_weight[c][i];
        }
        tensor_10[0][c] = result + tensor_q_net_2_bias[c];
    }
}

static inline void node_Relu_4(const float tensor_10[1][64], float tensor_11[1][64]) {
    for (uint32_t i = 0; i < 64; i++) {
        tensor_11[0][i] = tensor_10[0][i] > 0 ? tensor_10[0][i] : 0.0f;
    }
}

static inline void node_Gemm_5(const float tensor_11[1][64], const float tensor_q_net_4_weight[2][64], const float tensor_q_net_4_bias[2], float tensor_output[1][2]) {
    for (uint32_t c = 0; c < 2; c++) {
        float result = 0.0f;
        for (uint32_t i = 0; i < 64; i++) {
            result += tensor_11[0][i] * tensor_q_net_4_weight[c][i];
        }
        tensor_output[0][c] = result + tensor_q_net_4_bias[c];
    }
}

// ... (include constants data like tensor_q_net_0_weight, tensor_q_net_0_bias, ...)