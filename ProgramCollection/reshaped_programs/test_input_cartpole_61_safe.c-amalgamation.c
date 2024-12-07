#include <stdio.h>
#include <math.h>
#include <stdint.h>
#include <assert.h>

// Neural network model weights and bias are predefined to ensure deterministic behavior.
static const float tensor_q_net_0_weight[64][4] = {
    {0.15721032023429870605f, 0.11475459486246109009f, -0.63993811607360839844f, -0.069510847330093383789f},
    // ....(remaining weights)....
    {-0.019190063700079917908f, -0.032159797847270965576f, 0.082331359386444091797f, -0.028866052627563476562f}
};

static const float tensor_q_net_0_bias[64] = {
    -0.038480948656797409058f, 0.12814424932003021240f, 0.49260348081588745117f,
    // ....(remaining biases)....
    -0.0215315f
};

// ... include definitions for all weights and biases like the two samples above ...

static const float tensor_q_net_4_bias[2] = {
    0.020197313278913497925f, 0.00082921260036528110504f
};

union tensor_union_0 {
    float tensor_7[1][4];
    float tensor_9[1][64];
    float tensor_11[1][64];
};
static union tensor_union_0 tu0;

union tensor_union_1 {
    float tensor_8[1][64];
    float tensor_10[1][64];
};
static union tensor_union_1 tu1;

static inline void node_Flatten_0(const float tensor_input[1][4], float tensor_7[1][4]) {
    // Flatten
    for(uint32_t i = 0; i < 4; i++)
        tensor_7[0][i] = tensor_input[0][i];
}

static inline void node_Gemm_1(const float tensor_7[1][4], const float tensor_q_net_0_weight[64][4], const float tensor_q_net_0_bias[64], float tensor_8[1][64]) {
    // Gemm
    const int M = 1, K = 4, N = 64;
    float alpha = 1.0f, beta = 1.0f;
    for(uint32_t r = 0; r < M; r++)
        for(uint32_t c = 0; c < N; c++) {
            float ABrc = 0;
            for(uint32_t i = 0; i < K; i++) {
                ABrc += tensor_7[r][i] * tensor_q_net_0_weight[c][i];
            }
            tensor_8[r][c] = alpha * ABrc + beta * tensor_q_net_0_bias[c];
        }
}

static inline void node_Relu_2(const float tensor_8[1][64], float tensor_9[1][64]) {
    // ReLU
    for(uint32_t i = 0; i < 64; i++)
        tensor_9[0][i] = tensor_8[0][i] > 0 ? tensor_8[0][i] : 0;
}

static inline void node_Gemm_3(const float tensor_9[1][64], const float tensor_q_net_2_weight[64][64], const float tensor_q_net_2_bias[64], float tensor_10[1][64]) {
    // Gemm
    const int M = 1, K = 64, N = 64;
    float alpha = 1.0f, beta = 1.0f;
    for(uint32_t r = 0; r < M; r++)
        for(uint32_t c = 0; c < N; c++) {
            float ABrc = 0;
            for(uint32_t i = 0; i < K; i++) {
                ABrc += tensor_9[r][i] * tensor_q_net_2_weight[c][i];
            }
            tensor_10[r][c] = alpha * ABrc + beta * tensor_q_net_2_bias[c];
        }
}

static inline void node_Relu_4(const float tensor_10[1][64], float tensor_11[1][64]) {
    // ReLU
    for(uint32_t i = 0; i < 64; i++)
        tensor_11[0][i] = tensor_10[0][i] > 0 ? tensor_10[0][i] : 0;
}

static inline void node_Gemm_5(const float tensor_11[1][64], const float tensor_q_net_4_weight[2][64], const float tensor_q_net_4_bias[2], float tensor_output[1][2]) {
    // Gemm
    const int M = 1, K = 64, N = 2;
    float alpha = 1.0f, beta = 1.0f;
    for(uint32_t r = 0; r < M; r++)
        for(uint32_t c = 0; c < N; c++) {
            float ABrc = 0;
            for(uint32_t i = 0; i < K; i++) {
                ABrc += tensor_11[r][i] * tensor_q_net_4_weight[c][i];
            }
            tensor_output[r][c] = alpha * ABrc + beta * tensor_q_net_4_bias[c];
        }
}

void entry(const float tensor_input[1][4], float tensor_output[1][2]) {
    node_Flatten_0(tensor_input, tu0.tensor_7);
    node_Gemm_1(tu0.tensor_7, tensor_q_net_0_weight, tensor_q_net_0_bias, tu1.tensor_8);
    node_Relu_2(tu1.tensor_8, tu0.tensor_9);
    node_Gemm_3(tu0.tensor_9, tensor_q_net_2_weight, tensor_q_net_2_bias, tu1.tensor_10);
    node_Relu_4(tu1.tensor_10, tu0.tensor_11);
    node_Gemm_5(tu0.tensor_11, tensor_q_net_4_weight, tensor_q_net_4_bias, tensor_output);
}

int main() {
    float tensor_input[1][4] = {
        {-0.2558f, -0.44113794f, -0.06213012f, 0.20523617f}  // Within the allowed range
    };
    float tensor_output[1][2];

    entry(tensor_input, tensor_output);

    // Ensure the model outputs are valid as per the original constraint
    assert(!(tensor_output[0][1] <= tensor_output[0][0]));
    
    printf("Model outputs are valid, tensor_output[0][0]: %f, tensor_output[0][1]: %f\n", tensor_output[0][0], tensor_output[0][1]);

    return 0;
}