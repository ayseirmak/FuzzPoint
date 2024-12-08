#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <assert.h>

#define MAX(X,Y) ((X) > (Y) ? (X) : (Y))
#define MIN(X,Y) ((X) < (Y) ? (X) : (Y))
#define CLIP(X,L) (MAX(MIN(X,L), -L))

// Constants are initialized as specified in the original code
static const float tensor_q_net_0_weight[64][4] = {
    // Values here...
};
static const float tensor_q_net_0_bias[64] = {
    // Values here...
};
static const float tensor_q_net_2_weight[64][64] = {
    // Values here...
};
static const float tensor_q_net_2_bias[64] = {
    // Values here...
};
static const float tensor_q_net_4_weight[2][64] = {
    // Values here...
};
static const float tensor_q_net_4_bias[2] = {
    // Values here...
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

static inline void flatten(const float tensor_input[1][4], float tensor_7[1][4]) {
    for (uint32_t i = 0; i < 4; i++) {
        tensor_7[0][i] = tensor_input[0][i];
    }
}

static inline void gemm1(const float tensor_7[1][4], float tensor_8[1][64]) {
    const int M = 1;
    const int K = 4;
    const int N = 64;

    for (uint32_t r = 0; r < M; r++) {
        for (uint32_t c = 0; c < N; c++) {
            float result = tensor_q_net_0_bias[c];
            for (uint32_t i = 0; i < K; i++) {
                result += tensor_7[r][i] * tensor_q_net_0_weight[c][i];
            }
            tensor_8[r][c] = result;
        }
    }
}

static inline void relu2(const float tensor_8[1][64], float tensor_9[1][64]) {
    for (uint32_t i = 0; i < 64; i++) {
        tensor_9[0][i] = tensor_8[0][i] > 0 ? tensor_8[0][i] : 0;
    }
}

static inline void gemm3(const float tensor_9[1][64], float tensor_10[1][64]) {
    const int M = 1;
    const int K = 64;
    const int N = 64;

    for (uint32_t r = 0; r < M; r++) {
        for (uint32_t c = 0; c < N; c++) {
            float result = tensor_q_net_2_bias[c];
            for (uint32_t i = 0; i < K; i++) {
                result += tensor_9[r][i] * tensor_q_net_2_weight[c][i];
            }
            tensor_10[r][c] = result;
        }
    }
}

static inline void relu4(const float tensor_10[1][64], float tensor_11[1][64]) {
    for (uint32_t i = 0; i < 64; i++) {
        tensor_11[0][i] = tensor_10[0][i] > 0 ? tensor_10[0][i] : 0;
    }
}

static inline void gemm5(const float tensor_11[1][64], float tensor_output[1][2]) {
    const int M = 1;
    const int K = 64;
    const int N = 2;

    for (uint32_t r = 0; r < M; r++) {
        for (uint32_t c = 0; c < N; c++) {
            float result = tensor_q_net_4_bias[c];
            for (uint32_t i = 0; i < K; i++) {
                result += tensor_11[r][i] * tensor_q_net_4_weight[c][i];
            }
            tensor_output[r][c] = result;
        }
    }
}

void entry(const float tensor_input[1][4], float tensor_output[1][2]) {
    flatten(tensor_input, tu0.tensor_7);
    gemm1(tu0.tensor_7, tu1.tensor_8);
    relu2(tu1.tensor_8, tu0.tensor_9);
    gemm3(tu0.tensor_9, tu1.tensor_10);
    relu4(tu1.tensor_10, tu0.tensor_11);
    gemm5(tu0.tensor_11, tensor_output);
}

int main() {
    float tensor_input[1][4] = {
        {-0.25f, -0.05f, -0.07f, -0.38f}
    };
    float tensor_output[1][2];

    entry(tensor_input, tensor_output);

    assert(!(tensor_output[0][0] <= tensor_output[0][1]));

    return 0;
}