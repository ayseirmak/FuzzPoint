#include <stdio.h>
#include <math.h>
#include <stdint.h>
#include <stdbool.h>

// Declare constants.
static const float tensor_q_net_0_weight[64][4] = {
    {0.15721032023429870605f, 0.11475459486246109009f, -0.63993811607360839844f, -0.069510847330093383789f},
    {0.17542746663093566895f, 0.037346746772527694702f, 0.11804900318384170532f, -0.42608326673507690430f},
    // ...
    // [more weight values]
};

static const float tensor_q_net_0_bias[64] = {
    -0.038480948656797409058f, 0.12814424932003021240f, 0.49260348081588745117f, // ... [more bias values]
};

static const float tensor_q_net_2_weight[64][64] = {
    {-0.081372834742069244385f, 0.024248756468296051025f, 0.085219748318195343018f, -0.020931074395775794983f}, 
    // ...
    // [more weight values]
};

static const float tensor_q_net_2_bias[64] = {
    0.0096521666273474693298f, 0.033651806414127349854f, 0.039734158664941787720f, // ... [more bias values]
};

static const float tensor_q_net_4_weight[2][64] = {
    {-0.10003891587257385254f, -0.22389468550682067871f, -0.24801196157932281494f, 0.11498097330331802368f}, 
    // ...
    // [more weight values]
};

static const float tensor_q_net_4_bias[2] = {
    0.020197313278913497925f, 0.00082921260036528110504f
};

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

static inline void node_Flatten_0(const float tensor_input[1][4], float tensor_7[1][4]) {
    // Flatten
    float *input = (float*)tensor_input;
    float *output = (float*)tensor_7;
    for(uint32_t i = 0; i < 4; i++) output[i] = input[i];
}

// ... [other similar node functions: node_Gemm_1, node_Relu_2, etc.]

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
        {-0.2400f, -0.0510f, -0.0850f, -0.3790f}
    }; // Use specific deterministic values
    float tensor_output[1][2];
    
    entry(tensor_input, tensor_output);

    // Assertion logic translated to a simple condition check for demonstration
    if (!(tensor_output[0][0] > tensor_output[0][1])) {
        printf("Assertion failed: tensor_output[0][0] <= tensor_output[0][1]\n");
        return 1;
    } else {
        printf("Assertion passed.\n");
    }
    
    return 0;
}