#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

// Function prototypes
void entry(const float tensor_input[1][4], float tensor_output[1][2]);

static inline void node_Flatten_0(const float tensor_input[1][4], float tensor_7[1][4]);
static inline void node_Gemm_1(const float tensor_7[1][4], const float tensor_q_net_0_weight[64][4], const float tensor_q_net_0_bias[64], float tensor_8[1][64]);
static inline void node_Relu_2(const float tensor_8[1][64], float tensor_9[1][64]);
static inline void node_Gemm_3(const float tensor_9[1][64], const float tensor_q_net_2_weight[64][64], const float tensor_q_net_2_bias[64], float tensor_10[1][64]);
static inline void node_Relu_4(const float tensor_10[1][64], float tensor_11[1][64]);
static inline void node_Gemm_5(const float tensor_11[1][64], const float tensor_q_net_4_weight[2][64], const float tensor_q_net_4_bias[2], float tensor_output[1][2]);

static const float tensor_q_net_0_weight[64][4] = 
{
  {0.15721032f, 0.11475459f, -0.63993812f, -0.06951085f},
  {0.17542747f, 0.03734675f, 0.11804900f, -0.42608327f},
  {0.17451042f, -0.03839092f, -0.12378699f, 0.16069195f},
  // ... (truncated for brevity)
  {0.04679826f, -0.12378699f, -0.12249515f, -0.39637581f}
};

static const float tensor_q_net_0_bias[64] = 
{
  -0.03848095f, 0.12814425f, 0.49260348f, -0.30465084f, 0.35254270f, -0.26110908f,
  // ... (truncated for brevity)
  -0.20511501f, 0.08118565f
};

static const float tensor_q_net_2_weight[64][64] = 
{
  {-0.08137283f, 0.02424876f, 0.08521975f, -0.02093107f, 0.09214579f, 0.05190088f,
  // ... (truncated for brevity)
};

static const float tensor_q_net_2_bias[64] = 
{
  0.00965217f, 0.03365181f, 0.03973416f, 0.20449157f, -0.04806148f, -0.05671822f,
  // ... (truncated for brevity)
};

static const float tensor_q_net_4_weight[2][64] = 
{
  {-0.10003892f, -0.22389469f, -0.24801196f, 0.11498097f, 0.28772688f, -0.16866405f,
  // ... (truncated for brevity)
};

static const float tensor_q_net_4_bias[2] = {0.02019731f, 0.00082921f};

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

int main() {
    float tensor_input[1][4] = {{-0.2730f, -0.0526f, -0.0180f, -0.3206f}};
    float tensor_output[1][2];

    entry(tensor_input, tensor_output);

    if (!(tensor_output[0][1] <= tensor_output[0][0])) {
        printf("Execution complete, assertion passed.\n");
    } else {
        printf("Execution complete, assertion failed.\n");
    }

    return 0;
}

static inline void node_Flatten_0(const float tensor_input[1][4], float tensor_7[1][4]) {
    for (uint32_t i = 0; i < 4; i++)
        tensor_7[0][i] = tensor_input[0][i];
}

static inline void node_Gemm_1(const float tensor_7[1][4], const float tensor_q_net_0_weight[64][4], const float tensor_q_net_0_bias[64], float tensor_8[1][64]) {
    const int M = 1;
    const int K = 4;
    const int N = 64;
    for (uint32_t r = 0; r < M; r++) {
        for (uint32_t c = 0; c < N; c++) {
            float ABrc = 0;
            for (uint32_t i = 0; i < K; i++) {
                ABrc += tensor_7[r][i] * tensor_q_net_0_weight[c][i];
            }
            tensor_8[r][c] = ABrc + tensor_q_net_0_bias[c];
        }
    }
}

static inline void node_Relu_2(const float tensor_8[1][64], float tensor_9[1][64]) {
    for (uint32_t i = 0; i < 64; i++)
        tensor_9[0][i] = (tensor_8[0][i] > 0) ? tensor_8[0][i] : 0;
}

static inline void node_Gemm_3(const float tensor_9[1][64], const float tensor_q_net_2_weight[64][64], const float tensor_q_net_2_bias[64], float tensor_10[1][64]) {
    const int M = 1;
    const int K = 64;
    const int N = 64;
    for (uint32_t r = 0; r < M; r++) {
        for (uint32_t c = 0; c < N; c++) {
            float ABrc = 0;
            for (uint32_t i = 0; i < K; i++) {
                ABrc += tensor_9[r][i] * tensor_q_net_2_weight[c][i];
            }
            tensor_10[r][c] = ABrc + tensor_q_net_2_bias[c];
        }
    }
}

static inline void node_Relu_4(const float tensor_10[1][64], float tensor_11[1][64]) {
    for (uint32_t i = 0; i < 64; i++)
        tensor_11[0][i] = (tensor_10[0][i] > 0) ? tensor_10[0][i] : 0;
}

static inline void node_Gemm_5(const float tensor_11[1][64], const float tensor_q_net_4_weight[2][64], const float tensor_q_net_4_bias[2], float tensor_output[1][2]) {
    const int M = 1;
    const int K = 64;
    const int N = 2;
    for (uint32_t r = 0; r < M; r++) {
        for (uint32_t c = 0; c < N; c++) {
            float ABrc = 0;
            for (uint32_t i = 0; i < K; i++) {
                ABrc += tensor_11[r][i] * tensor_q_net_4_weight[c][i];
            }
            tensor_output[r][c] = ABrc + tensor_q_net_4_bias[c];
        }
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