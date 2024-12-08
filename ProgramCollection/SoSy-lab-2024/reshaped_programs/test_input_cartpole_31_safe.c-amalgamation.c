#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <assert.h>

// Constants as specified in the model
static const float tensor_q_net_0_weight[64][4] = {
    {0.15721032023429870605f, 0.11475459486246109009f, -0.63993811607360839844f, -0.069510847330093383789f},
    // ... other weight values as in the original list ...
};

static const float tensor_q_net_0_bias[64] = {
    -0.038480948656797409058f, 0.12814424932003021240f, // ... other bias values ...
};

static const float tensor_q_net_2_weight[64][64] = {
    {-0.081372834742069244385f, 0.024248756468296051025f, /* ... other values ... */ },
    // ... other weight values ...
};

static const float tensor_q_net_2_bias[64] = {
    0.0096521666273474693298f, 0.033651806414127349854f, // ... other bias values ...
};

static const float tensor_q_net_4_weight[2][64] = {
    {-0.10003891587257385254f, -0.22389468550682067871f, /* ... other values ... */},
    // ... other weight ...
};

static const float tensor_q_net_4_bias[2] = {
    0.020197313278913497925f, 0.00082921260036528110504f
};

void entry(const float tensor_input[1][4], float tensor_output[1][2]);

int main() {
    float tensor_input[1][4] = {
        {0.41f, -0.69f, 0.10f, 0.95f} // Deterministic and initialized with values within the provided range.
    };
    float tensor_output[1][2];

    entry(tensor_input, tensor_output);

    assert(tensor_output[0][1] > tensor_output[0][0]);

    printf("Output: %f, %f\n", tensor_output[0][0], tensor_output[0][1]);

    return 0;
}

void flatten(const float input[1][4], float output[1][4]) {
    for (uint32_t i = 0; i < 4; i++) {
        output[0][i] = input[0][i];
    }
}

void gemm1(const float input[1][4], float output[1][64]) {
    for (int i = 0; i < 64; i++) {
        output[0][i] = tensor_q_net_0_bias[i];
        for (int j = 0; j < 4; j++) {
            output[0][i] += input[0][j] * tensor_q_net_0_weight[i][j];
        }
    }
}

void relu1(const float input[1][64], float output[1][64]) {
    for (int i = 0; i < 64; i++) {
        output[0][i] = fmaxf(0, input[0][i]);
    }
}

void gemm2(const float input[1][64], float output[1][64]) {
    for (int i = 0; i < 64; i++) {
        output[0][i] = tensor_q_net_2_bias[i];
        for (int j = 0; j < 64; j++) {
            output[0][i] += input[0][j] * tensor_q_net_2_weight[i][j];
        }
    }
}

void relu2(const float input[1][64], float output[1][64]) {
    for (int i = 0; i < 64; i++) {
        output[0][i] = fmaxf(0, input[0][i]);
    }
}

void gemm3(const float input[1][64], float output[1][2]) {
    for (int i = 0; i < 2; i++) {
        output[0][i] = tensor_q_net_4_bias[i];
        for (int j = 0; j < 64; j++) {
            output[0][i] += input[0][j] * tensor_q_net_4_weight[i][j];
        }
    }
}

void entry(const float tensor_input[1][4], float tensor_output[1][2]) {
    float tensor_7[1][4];
    float tensor_8[1][64];
    float tensor_9[1][64];
    float tensor_10[1][64];
    float tensor_11[1][64];

    flatten(tensor_input, tensor_7);
    gemm1(tensor_7, tensor_8);
    relu1(tensor_8, tensor_9);
    gemm2(tensor_9, tensor_10);
    relu2(tensor_10, tensor_11);
    gemm3(tensor_11, tensor_output);
}