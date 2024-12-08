#include <stdio.h>
#include <math.h>
#include <stdint.h>
#include <assert.h>

// Predefined tensor weights and biases
static const float tensor_q_net_0_weight[64][4] = {
    {0.15721032023429870605f, 0.11475459486246109009f, -0.63993811607360839844f, -0.069510847330093383789f},
    // ... (remaining elements omitted for brevity)
};

static const float tensor_q_net_0_bias[64] = {
    -0.038480948656797409058f, 0.12814424932003021240f, // ...
};

static const float tensor_q_net_2_weight[64][64] = {
    {-0.081372834742069244385f, 0.024248756468296051025f, // ...
    },
    // ... (remaining elements omitted for brevity)
};

static const float tensor_q_net_2_bias[64] = {
    0.0096521666273474693298f, 0.033651806414127349854f, // ...
};

static const float tensor_q_net_4_weight[2][64] = {
    {-0.10003891587257385254f, -0.22389468550682067871f, // ...
    },
    // ... (remaining elements omitted for brevity)
};

static const float tensor_q_net_4_bias[2] = {0.020197313278913497925f, 0.00082921260036528110504f};

// Data structures for intermediate computations
union tensor_union_0 {
    float tensor_7[1][4];
    float tensor_9[1][64];
    float tensor_11[1][64];
};

union tensor_union_1 {
    float tensor_8[1][64];
    float tensor_10[1][64];
};

// Function implementations
static void node_Flatten_0(const float tensor_input[1][4], float tensor_7[1][4]) {
    for (uint32_t i = 0; i < 4; i++)
        tensor_7[0][i] = tensor_input[0][i];
}

static void node_Gemm_1(const float tensor_7[1][4], float tensor_8[1][64]) {
    for (uint32_t c = 0; c < 64; c++) {
        float ABrc = 0;
        for (uint32_t i = 0; i < 4; i++) {
            ABrc += tensor_7[0][i] * tensor_q_net_0_weight[c][i];
        }
        tensor_8[0][c] = ABrc + tensor_q_net_0_bias[c];
    }
}

static void node_Relu_2(const float tensor_8[1][64], float tensor_9[1][64]) {
    for (uint32_t i = 0; i < 64; i++)
        tensor_9[0][i] = tensor_8[0][i] > 0 ? tensor_8[0][i] : 0;
}

static void node_Gemm_3(const float tensor_9[1][64], float tensor_10[1][64]) {
    for (uint32_t c = 0; c < 64; c++) {
        float ABrc = 0;
        for (uint32_t i = 0; i < 64; i++) {
            ABrc += tensor_9[0][i] * tensor_q_net_2_weight[c][i];
        }
        tensor_10[0][c] = ABrc + tensor_q_net_2_bias[c];
    }
}

static void node_Relu_4(const float tensor_10[1][64], float tensor_11[1][64]) {
    for (uint32_t i = 0; i < 64; i++)
        tensor_11[0][i] = tensor_10[0][i] > 0 ? tensor_10[0][i] : 0;
}

static void node_Gemm_5(const float tensor_11[1][64], float tensor_output[1][2]) {
    for (uint32_t c = 0; c < 2; c++) {
        float ABrc = 0;
        for (uint32_t i = 0; i < 64; i++) {
            ABrc += tensor_11[0][i] * tensor_q_net_4_weight[c][i];
        }
        tensor_output[0][c] = ABrc + tensor_q_net_4_bias[c];
    }
}

void entry(const float tensor_input[1][4], float tensor_output[1][2]) {
    union tensor_union_0 tu0;
    union tensor_union_1 tu1;

    node_Flatten_0(tensor_input, tu0.tensor_7);
    node_Gemm_1(tu0.tensor_7, tu1.tensor_8);
    node_Relu_2(tu1.tensor_8, tu0.tensor_9);
    node_Gemm_3(tu0.tensor_9, tu1.tensor_10);
    node_Relu_4(tu1.tensor_10, tu0.tensor_11);
    node_Gemm_5(tu0.tensor_11, tensor_output);
}

int main() {
    float tensor_input[1][4] = {{-0.033f, 0.15f, -0.048f, -0.406f}};  // Static input values
    float tensor_output[1][2];

    entry(tensor_input, tensor_output);

    // Assert the condition using standard C assert
    assert(!(tensor_output[0][0] <= tensor_output[0][1]));

    printf("Assertion passed.\n");
    return 0;
}