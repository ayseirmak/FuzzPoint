#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <assert.h>

#define MAX(X, Y) ((X) > (Y) ? (X) : (Y))
#define MIN(X, Y) ((X) < (Y) ? (X) : (Y))
#define CLIP(X, L) (MAX(MIN(X, L), -(L)))

// Declare static weights and biases for the test
static const float tensor_linear_list_0_weight[32][3] = {
    {-0.88176542520523071289f, -0.70463490486145019531f, -0.54373848438262939453f},
    {0.64892828464508056641f, 0.0034874209668487310410f, -0.37089416384696960449f},
    // Truncated for brevity...
};

static const float tensor_linear_list_0_bias[32] = {
    -0.034172810614109039307f, 1.8474619388580322266f, 0.64596593379974365234f,
    // Truncated for brevity...
};

static const float tensor_linear_list_1_weight[32][32] = {
    // Full weight data is truncated for brevity...
};

static const float tensor_linear_list_1_bias[32] = {
    0.013307446613907814026f, -0.20824897289276123047f, 0.14604136347770690918f,
    // Truncated for brevity...
};

static const float tensor_linear_list_2_weight[3][32] = {
    // Full weight data is truncated for brevity...
};

static const float tensor_linear_list_2_bias[3] = {
    -0.58704066276550292969f, 0.024314835667610168457f, 0.35607513785362243652f
};

union tensor_union_0 {
    float tensor_7[1][32];
    float tensor_9[1][32];
};

static union tensor_union_0 tu0;

union tensor_union_1 {
    float tensor_8[1][32];
    float tensor_10[1][32];
};

static union tensor_union_1 tu1;


static inline void node_Gemm_0( const float tensor_input[1][3], const float tensor_linear_list_0_weight[32][3], const float tensor_linear_list_0_bias[32], float tensor_7[1][32] )
{
    const int M = 1;
    const int K = 3;
    const int N = 32;
    float (*A)[3]  = (float(*)[3])tensor_input;
    float (*Y)[32]  = (float(*)[32])tensor_7;
    float alpha = 1.0f;
    float beta = 1.0f;
    float (*C)[32]  = (float(*)[32])tensor_linear_list_0_bias;
    for (uint32_t r = 0; r < M; r++)
        for (uint32_t c = 0; c < N; c++) {
            float ABrc = 0;
            for (uint32_t i = 0; i < K; i++) {
                float B = tensor_linear_list_0_weight[c][i];
                ABrc += A[r][i] * B;
            }
            float tmp = ABrc * alpha;
            tmp += C[0][c] * beta;
            Y[r][c] = tmp;
        }
}

static inline void node_Relu_1(const float tensor_7[1][32], float tensor_8[1][32]) {
    float *X = (float*)tensor_7;
    float *Y = (float*)tensor_8;
    for (uint32_t i = 0; i < 32; i++)
        Y[i] = X[i] > 0 ? X[i] : 0;
}

static inline void node_Gemm_2(const float tensor_8[1][32], const float tensor_linear_list_1_weight[32][32], const float tensor_linear_list_1_bias[32], float tensor_9[1][32])
{
    const int M = 1;
    const int K = 32;
    const int N = 32;
    float (*A)[32]  = (float(*)[32])tensor_8;
    float (*Y)[32]  = (float(*)[32])tensor_9;
    float alpha = 1.0f;
    float beta = 1.0f;
    float (*C)[32]  = (float(*)[32])tensor_linear_list_1_bias;
    for (uint32_t r = 0; r < M; r++)
        for (uint32_t c = 0; c < N; c++) {
            float ABrc = 0;
            for (uint32_t i = 0; i < K; i++) {
                float B = tensor_linear_list_1_weight[c][i];
                ABrc += A[r][i] * B;
            }
            float tmp = ABrc * alpha;
            tmp += C[0][c] * beta;
            Y[r][c] = tmp;
        }
}

static inline void node_Relu_3(const float tensor_9[1][32], float tensor_10[1][32])
{
    float *X = (float*)tensor_9;
    float *Y = (float*)tensor_10;
    for (uint32_t i = 0; i < 32; i++)
        Y[i] = X[i] > 0 ? X[i] : 0;
}

static inline void node_Gemm_4(const float tensor_10[1][32], const float tensor_linear_list_2_weight[3][32], const float tensor_linear_list_2_bias[3], float tensor_output[1][3])
{
    const int M = 1;
    const int K = 32;
    const int N = 3;
    float (*A)[32]  = (float(*)[32])tensor_10;
    float (*Y)[3]  = (float(*)[3])tensor_output;
    float alpha = 1.0f;
    float beta = 1.0f;
    float (*C)[3]  = (float(*)[3])tensor_linear_list_2_bias;
    for (uint32_t r = 0; r < M; r++)
        for (uint32_t c = 0; c < N; c++) {
            float ABrc = 0;
            for (uint32_t i = 0; i < K; i++) {
                float B = tensor_linear_list_2_weight[c][i];
                ABrc += A[r][i] * B;
            }
            float tmp = ABrc * alpha;
            tmp += C[0][c] * beta;
            Y[r][c] = tmp;
        }
}

void entry(const float tensor_input[1][3], float tensor_output[1][3]) {
    node_Gemm_0(tensor_input, tensor_linear_list_0_weight, tensor_linear_list_0_bias, tu0.tensor_7);
    node_Relu_1(tu0.tensor_7, tu1.tensor_8);
    node_Gemm_2(tu1.tensor_8, tensor_linear_list_1_weight, tensor_linear_list_1_bias, tu0.tensor_9);
    node_Relu_3(tu0.tensor_9, tu1.tensor_10);
    node_Gemm_4(tu1.tensor_10, tensor_linear_list_2_weight, tensor_linear_list_2_bias, tensor_output);
}

int main() {
    float tensor_input[1][3] = {{-1.0f, 0.0f, 2.5f}}; // Fixed deterministic input
    float tensor_output[1][3];

    entry(tensor_input, tensor_output);

    assert(!((tensor_output[0][1] <= 0.6753632844882149f) && (tensor_output[0][1] >= -0.6753632844882149f) &&
             (tensor_output[0][2] <= 0.6753632844882149f) && (tensor_output[0][2] >= -0.6753632844882149f) &&
             (tensor_output[0][0] >= 0.27808111751725895f)));

    return 0;
}