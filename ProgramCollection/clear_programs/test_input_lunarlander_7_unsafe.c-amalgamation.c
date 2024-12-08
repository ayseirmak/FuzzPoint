#include <assert.h>
#include <stdio.h>
#include <stdint.h>

// Helper macros for mathematical operations
#define MAX(X,Y) ( X > Y ? X : Y)
#define MIN(X,Y) ( X < Y ? X : Y)
#define CLIP(X,L) ( MAX(MIN(X,L), -L) )

// Constants for neural network weights and biases
static const float tensor_q_net_0_weight[64][8] = {
    {0.21815462410449981689f, 0.23126253485679626465f, -0.14049024879932403564f, 0.39555677771568298340f, 0.38167867064476013184f, 0.29623535275459289551f, -0.11851222068071365356f, 0.38335996866226196289f},
    // ... Remaining weight initializations ...
};
static const float tensor_q_net_0_bias[64] = {
    0.12845531105995178223f, 0.41714116930961608887f, 0.14017663896083831787f, -0.13708075881004333496f,
    // ... Remaining bias initializations ...
};
static const float tensor_q_net_2_weight[64][64] = {
    {0.039809726178646087646f, -0.050762739032506942749f, -0.19122810661792755127f, 0.13844394683837890625f, -0.093590117990970611572f, 0.27353912591934204102f, 0.15563592314720153809f, 0.11391936242580413818f},
    // ... Remaining weight initializations ...
};
static const float tensor_q_net_2_bias[64] = {
    0.10505031049251556396f, -0.051322553306818008423f, -0.040096297860145568848f, -0.078061111271381378174f,
    // ... Remaining bias initializations ...
};
static const float tensor_q_net_4_weight[4][64] = {
    {-0.17162241041660308838f, -0.080019518733024597168f, 0.39136415719985961914f, -0.12776407599449157715f},
    // ... Remaining weight initializations ...
};
static const float tensor_q_net_4_bias[4] = {0.058722577989101409912f, -0.026569778099656105042f, 0.099756106734275817871f, -0.051060039550065994263f};

// Helper unions for tensor storage
union tensor_union_0 {
    float tensor_7[1][8];
    float tensor_9[1][64];
    float tensor_11[1][64];
};

union tensor_union_1 {
    float tensor_8[1][64];
    float tensor_10[1][64];
};

static union tensor_union_0 tu0;
static union tensor_union_1 tu1;

static inline void node_Flatten_0(const float tensor_input[1][8], float tensor_7[1][8]) {
    float *input = (float *)tensor_input;
    float *output = (float *)tensor_7;
    for (uint32_t i = 0; i < 8; i++)
        output[i] = input[i];
}

static inline void node_Gemm_1(const float tensor_7[1][8], const float tensor_q_net_0_weight[64][8], const float tensor_q_net_0_bias[64], float tensor_8[1][64]) {
    const int M = 1, K = 8, N = 64;
    float (*A)[8] = (float (*)[8])tensor_7;
    float (*Y)[64] = (float (*)[64])tensor_8;
    float alpha = 1.0f, beta = 1.0f;
    for (uint32_t r = 0; r < M; r++) {
        for (uint32_t c = 0; c < N; c++) {
            float ABrc = 0;
            for (uint32_t i = 0; i < K; i++) {
                ABrc += A[r][i] * tensor_q_net_0_weight[c][i];
            }
            Y[r][c] = ABrc * alpha + tensor_q_net_0_bias[c] * beta;
        }
    }
}

static inline void node_Relu_2(const float tensor_8[1][64], float tensor_9[1][64]) {
    float *X = (float *)tensor_8;
    float *Y = (float *)tensor_9;
    for (uint32_t i = 0; i < 64; i++)
        Y[i] = X[i] > 0 ? X[i] : 0;
}

static inline void node_Gemm_3(const float tensor_9[1][64], const float tensor_q_net_2_weight[64][64], const float tensor_q_net_2_bias[64], float tensor_10[1][64]) {
    const int M = 1, K = 64, N = 64;
    float (*A)[64] = (float (*)[64])tensor_9;
    float (*Y)[64] = (float (*)[64])tensor_10;
    float alpha = 1.0f, beta = 1.0f;
    for (uint32_t r = 0; r < M; r++) {
        for (uint32_t c = 0; c < N; c++) {
            float ABrc = 0;
            for (uint32_t i = 0; i < K; i++) {
                ABrc += A[r][i] * tensor_q_net_2_weight[c][i];
            }
            Y[r][c] = ABrc * alpha + tensor_q_net_2_bias[c] * beta;
        }
    }
}

static inline void node_Relu_4(const float tensor_10[1][64], float tensor_11[1][64]) {
    float *X = (float *)tensor_10;
    float *Y = (float *)tensor_11;
    for (uint32_t i = 0; i < 64; i++)
        Y[i] = X[i] > 0 ? X[i] : 0;
}

static inline void node_Gemm_5(const float tensor_11[1][64], const float tensor_q_net_4_weight[4][64], const float tensor_q_net_4_bias[4], float tensor_output[1][4]) {
    const int M = 1, K = 64, N = 4;
    float (*A)[64] = (float (*)[64])tensor_11;
    float (*Y)[4] = (float (*)[4])tensor_output;
    float alpha = 1.0f, beta = 1.0f;
    for (uint32_t r = 0; r < M; r++) {
        for (uint32_t c = 0; c < N; c++) {
            float ABrc = 0;
            for (uint32_t i = 0; i < K; i++) {
                ABrc += A[r][i] * tensor_q_net_4_weight[c][i];
            }
            Y[r][c] = ABrc * alpha + tensor_q_net_4_bias[c] * beta;
        }
    }
}

// Entry function of the neural network
void entry(const float tensor_input[1][8], float tensor_output[1][4]) {
    node_Flatten_0(tensor_input, tu0.tensor_7);
    node_Gemm_1(tu0.tensor_7, tensor_q_net_0_weight, tensor_q_net_0_bias, tu1.tensor_8);
    node_Relu_2(tu1.tensor_8, tu0.tensor_9);
    node_Gemm_3(tu0.tensor_9, tensor_q_net_2_weight, tensor_q_net_2_bias, tu1.tensor_10);
    node_Relu_4(tu1.tensor_10, tu0.tensor_11);
    node_Gemm_5(tu0.tensor_11, tensor_q_net_4_weight, tensor_q_net_4_bias, tensor_output);
}

// Main function to demonstrate the usage of the entry function with deterministic input
int main() {
    float tensor_input[1][8] = {
        {-0.881256640f, 0.0500f, 0.8000f, -0.231181310f, -0.408875000f, 0.0f, 1.0f, 1.0f} // Deterministic input for demonstration
    };
    float tensor_output[1][4];

    entry(tensor_input, tensor_output);

    assert(!(tensor_output[0][2] <= tensor_output[0][3]));

    printf("Output: [%.6f, %.6f, %.6f, %.6f]\n", tensor_output[0][0], tensor_output[0][1], tensor_output[0][2], tensor_output[0][3]);

    return 0;
}