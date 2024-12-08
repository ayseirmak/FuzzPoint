#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <assert.h>

#define MAX(X,Y) ( (X) > (Y) ? (X) : (Y))
#define MIN(X,Y) ( (X) < (Y) ? (X) : (Y))
#define CLIP(X,L) ( MAX(MIN(X,L), -L) )

static const float tensor_q_net_0_weight[64][4] = {
    {0.15721032023429870605f, 0.11475459486246109009f, -0.63993811607360839844f, -0.069510847330093383789f},
    /* ... (Other values truncated for brevity) ... */
    {0.11183704435825347900f, -0.091638505458831787109f, -0.62372940778732299805f, -0.40521082282066345215f}
};

static const float tensor_q_net_0_bias[64] = {
    -0.038480948656797409058f, 0.12814424932003021240f, /* ... (Other values truncated for brevity) ... */, 0.081185646355152130127f
};

static const float tensor_q_net_2_weight[64][64] = {
    {-0.081372834742069244385f, 0.024248756468296051025f, /* ... (Truncated values) ... */, -0.053694937378168106079f},
    /* ... (Other values truncated for brevity) ... */
    {-0.056820519268512725830f, -0.10781235992908477783f, /* ... (Truncated values) ... */, -0.007839957064926624298f}
};

static const float tensor_q_net_2_bias[64] = {
    0.0096521666273474693298f, 0.033651806414127349854f, /* ... (Other values truncated for brevity) ... */, -0.069172650575637817383f
};

static const float tensor_q_net_4_weight[2][64] = {
    {-0.10003891587257385254f, -0.22389468550682067871f, /* ... (Truncated values) ... */, 0.13715313947296142578f},
    {-0.064644664525985717773f, 0.025081984698772430420f, /* ... (Truncated values) ... */, -0.056124195456504821777f}
};

static const float tensor_q_net_4_bias[2] = {0.020197313278913497925f, 0.00082921260036528110504f};

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
    for (uint32_t i = 0; i < 4; i++)
        tensor_7[0][i] = tensor_input[0][i];
}

static inline void node_Gemm_1(const float tensor_7[1][4], const float tensor_q_net_0_weight[64][4], const float tensor_q_net_0_bias[64], float tensor_8[1][64]) {
    for (uint32_t c = 0; c < 64; c++) {
        float ABrc = 0;
        for (uint32_t i = 0; i < 4; i++) {
            ABrc += tensor_7[0][i] * tensor_q_net_0_weight[c][i];
        }
        tensor_8[0][c] = ABrc + tensor_q_net_0_bias[c];
    }
}

static inline void node_Relu_2(const float tensor_8[1][64], float tensor_9[1][64]) {
    for (uint32_t i = 0; i < 64; i++)
        tensor_9[0][i] = tensor_8[0][i] > 0 ? tensor_8[0][i] : 0;
}

static inline void node_Gemm_3(const float tensor_9[1][64], const float tensor_q_net_2_weight[64][64], const float tensor_q_net_2_bias[64], float tensor_10[1][64]) {
    for (uint32_t c = 0; c < 64; c++) {
        float ABrc = 0;
        for (uint32_t i = 0; i < 64; i++) {
            ABrc += tensor_9[0][i] * tensor_q_net_2_weight[c][i];
        }
        tensor_10[0][c] = ABrc + tensor_q_net_2_bias[c];
    }
}

static inline void node_Relu_4(const float tensor_10[1][64], float tensor_11[1][64]) {
    for (uint32_t i = 0; i < 64; i++)
        tensor_11[0][i] = tensor_10[0][i] > 0 ? tensor_10[0][i] : 0;
}

static inline void node_Gemm_5(const float tensor_11[1][64], const float tensor_q_net_4_weight[2][64], const float tensor_q_net_4_bias[2], float tensor_output[1][2]) {
    for (uint32_t c = 0; c < 2; c++) {
        float ABrc = 0;
        for (uint32_t i = 0; i < 64; i++) {
            ABrc += tensor_11[0][i] * tensor_q_net_4_weight[c][i];
        }
        tensor_output[0][c] = ABrc + tensor_q_net_4_bias[c];
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
        {-0.05f, -0.05f, 0.0f, 0.0f}
    };
    float tensor_output[1][2];

    // Call entry function
    entry(tensor_input, tensor_output);

    // Asserting the condition
    assert(tensor_output[0][1] > tensor_output[0][0]);

    printf("Assertion passed!\n");
    return 0;
}