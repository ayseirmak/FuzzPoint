#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdint.h>

// Ensure all static data and weights are declared in advance

static const float tensor_q_net_0_weight[64][8] = {
  {0.21815462410449981689f, 0.23126253485679626465f, -0.14049024879932403564f, 0.39555677771568298340f, 0.38167867064476013184f, 0.29623535275459289551f, -0.11851222068071365356f, 0.38335996866226196289f},
  /*... (other values omitted for brevity) ...*/
};

static const float tensor_q_net_0_bias[64] = {0.12845531105995178223f, 0.41714116930961608887f, 0.14017663896083831787f, /*...*/};

static const float tensor_q_net_2_weight[64][64] = {
  {0.039809726178646087646f, -0.050762739032506942749f, /*...*/},
  /*... (other values omitted for brevity) ...*/
};

static const float tensor_q_net_2_bias[64] = {0.10505031049251556396f, -0.051322553306818008423f, /*...*/};

static const float tensor_q_net_4_weight[4][64] = {
  {-0.17162241041660308838f, -0.080019518733024597168f, /*...*/},
  /*... (other values omitted for brevity) ...*/
};

static const float tensor_q_net_4_bias[4] = {0.058722577989101409912f, -0.026569778099656105042f, /*...*/};

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

static inline void node_Flatten_0(const float input[1][8], float output[1][8]) {
    for (uint32_t i = 0; i < 8; i++)
        output[0][i] = input[0][i];
}

static inline void node_Gemm(const float input[1][8], const float weight[64][8], const float bias[64], float output[1][64]) {
    const int M = 1;
    const int K = 8;
    const int N = 64;
    for (uint32_t r = 0; r < M; r++) {
        for (uint32_t c = 0; c < N; c++) {
            float sum = 0.0f;
            for (uint32_t i = 0; i < K; i++)
                sum += input[r][i] * weight[c][i];
            output[r][c] = sum + bias[c];
        }
    }
}

static inline void node_Relu_2(const float input[1][64], float output[1][64]) {
    for (uint32_t i = 0; i < 64; i++)
        output[0][i] = input[0][i] > 0 ? input[0][i] : 0;
}

static inline void node_Gemm_3(const float input[1][64], const float weight[64][64], const float bias[64], float output[1][64]) {
    const int M = 1;
    const int K = 64;
    const int N = 64;
    for (uint32_t r = 0; r < M; r++) {
        for (uint32_t c = 0; c < N; c++) {
            float sum = 0.0f;
            for (uint32_t i = 0; i < K; i++)
                sum += input[r][i] * weight[c][i];
            output[r][c] = sum + bias[c];
        }
    }
}

static inline void node_Relu_4(const float input[1][64], float output[1][64]) {
    for (uint32_t i = 0; i < 64; i++)
        output[0][i] = input[0][i] > 0 ? input[0][i] : 0;
}

static inline void node_Gemm_5(const float input[1][64], const float weight[4][64], const float bias[4], float output[1][4]) {
    const int M = 1;
    const int K = 64;
    const int N = 4;
    for (uint32_t r = 0; r < M; r++) {
        for (uint32_t c = 0; c < N; c++) {
            float sum = 0.0f;
            for (uint32_t i = 0; i < K; i++)
                sum += input[r][i] * weight[c][i];
            output[r][c] = sum + bias[c];
        }
    }
}

void entry(const float tensor_input[1][8], float tensor_output[1][4]) {
    node_Flatten_0(tensor_input, tu0.tensor_7);
    node_Gemm(tu0.tensor_7, tensor_q_net_0_weight, tensor_q_net_0_bias, tu1.tensor_8);
    node_Relu_2(tu1.tensor_8, tu0.tensor_9);
    node_Gemm_3(tu0.tensor_9, tensor_q_net_2_weight, tensor_q_net_2_bias, tu1.tensor_10);
    node_Relu_4(tu1.tensor_10, tu0.tensor_11);
    node_Gemm_5(tu0.tensor_11, tensor_q_net_4_weight, tensor_q_net_4_bias, tensor_output);
}

int main() {
    float tensor_input[1][8] = {
        {-0.85f, 0.07f, 0.02f, -0.05f, -0.01f, -0.02f, 1.0f, 1.0f}
    };
    float tensor_output[1][4];

    entry(tensor_input, tensor_output);

    printf("Output tensor:\n");
    for (int i = 0; i < 4; i++) {
        printf("%f ", tensor_output[0][i]);
    }
    printf("\n");

    assert(tensor_output[0][2] > tensor_output[0][3]);

    return 0;
}