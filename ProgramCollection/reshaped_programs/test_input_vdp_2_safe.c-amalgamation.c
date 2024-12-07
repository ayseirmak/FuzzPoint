#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <math.h>
#include <assert.h>

// Define constants for tensor weights and biases
#define MAX(X,Y) ((X) > (Y) ? (X) : (Y))
#define MIN(X,Y) ((X) < (Y) ? (X) : (Y))
#define CLIP(X,L) (MAX(MIN((X), (L)), -(L)))

static const float tensor_linear_list_0_weight[32][3] = {
    {-0.8817f, -0.7046f, -0.5437f}, {0.6489f, 0.0035f, -0.3709f}, {-0.7411f, -1.0338f, 0.0312f},
    // ... (remaining elements are truncated for brevity)
};

static const float tensor_linear_list_0_bias[32] = {
    -0.0342f, 1.8475f, 0.6460f, // ... (remaining elements truncated)
};

static const float tensor_linear_list_1_weight[32][32] = {
    {0.195957f, 0.096428f, -0.012698f, // ... (truncated for brevity) 
};

static const float tensor_linear_list_1_bias[32] = {
    0.013307f, -0.208249f, 0.146041f, // ... (remaining elements truncated)
};

static const float tensor_linear_list_2_weight[3][32] = {
    {0.205850f, 0.109978f, 0.322448f, // ... (truncated for brevity)
};

static const float tensor_linear_list_2_bias[3] = {
    -0.587041f, 0.024315f, 0.356075f
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

// Function declarations
void node_Gemm_0(const float tensor_input[1][3], const float tensor_linear_list_0_weight[32][3], const float tensor_linear_list_0_bias[32], float tensor_7[1][32]);
void node_Relu_1(const float tensor_7[1][32], float tensor_8[1][32]);
void node_Gemm_2(const float tensor_8[1][32], const float tensor_linear_list_1_weight[32][32], const float tensor_linear_list_1_bias[32], float tensor_9[1][32]);
void node_Relu_3(const float tensor_9[1][32], float tensor_10[1][32]);
void node_Gemm_4(const float tensor_10[1][32], const float tensor_linear_list_2_weight[3][32], const float tensor_linear_list_2_bias[3], float tensor_output[1][3]);

void entry(const float tensor_input[1][3], float tensor_output[1][3]) {
    node_Gemm_0(tensor_input, tensor_linear_list_0_weight, tensor_linear_list_0_bias, tu0.tensor_7);
    node_Relu_1(tu0.tensor_7, tu1.tensor_8);
    node_Gemm_2(tu1.tensor_8, tensor_linear_list_1_weight, tensor_linear_list_1_bias, tu0.tensor_9);
    node_Relu_3(tu0.tensor_9, tu1.tensor_10);
    node_Gemm_4(tu1.tensor_10, tensor_linear_list_2_weight, tensor_linear_list_2_bias, tensor_output);
}

int main() {
    float tensor_input[1][3] = {{0.5f, -1.0f, 3.0f}}; // Initialized with fixed values
    float tensor_output[1][3];

    // Verify input assumptions
    assert(tensor_input[0][0] >= -2.5f && tensor_input[0][0] <= 2.5f);
    assert(tensor_input[0][1] >= -2.5f && tensor_input[0][1] <= 2.5f);
    assert(tensor_input[0][2] >= 0.0f && tensor_input[0][2] <= 5.0f);

    // Run the main computation
    entry(tensor_input, tensor_output);

    // Assert the expected output condition
    assert(!((tensor_output[0][1] <= 0.69417093575195) && (tensor_output[0][1] >= -0.69417093575195) && (tensor_output[0][2] <= 0.69417093575195) && (tensor_output[0][2] >= -0.69417093575195) && (tensor_output[0][0] >= 0.29409921696577157)));

    printf("Output: [%f, %f, %f]\n", tensor_output[0][0], tensor_output[0][1], tensor_output[0][2]);

    return 0;
}

// Function implementations
void node_Gemm_0(const float tensor_input[1][3], const float tensor_linear_list_0_weight[32][3], const float tensor_linear_list_0_bias[32], float tensor_7[1][32]) {
    const int M = 1;
    const int K = 3;
    const int N = 32;
    float (*A)[3] = (float(*)[3])tensor_input;
    float (*Y)[32] = (float(*)[32])tensor_7;
    float alpha = 1.0f;
    float beta = 1.0f;
    float (*C)[32] = (float(*)[32])tensor_linear_list_0_bias;

    for (uint32_t r = 0; r < M; r++) {
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
}

void node_Relu_1(const float tensor_7[1][32], float tensor_8[1][32]) {
    float *X = (float *)tensor_7;
    float *Y = (float *)tensor_8;
    for (uint32_t i = 0; i < 32; i++) {
        Y[i] = X[i] > 0 ? X[i] : 0;
    }
}

void node_Gemm_2(const float tensor_8[1][32], const float tensor_linear_list_1_weight[32][32], const float tensor_linear_list_1_bias[32], float tensor_9[1][32]) {
    const int M = 1;
    const int K = 32;
    const int N = 32;
    float (*A)[32] = (float(*)[32])tensor_8;
    float (*Y)[32] = (float(*)[32])tensor_9;
    float alpha = 1.0f;
    float beta = 1.0f;
    float (*C)[32] = (float(*)[32])tensor_linear_list_1_bias;

    for (uint32_t r = 0; r < M; r++) {
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
}

void node_Relu_3(const float tensor_9[1][32], float tensor_10[1][32]) {
    float *X = (float *)tensor_9;
    float *Y = (float *)tensor_10;
    for (uint32_t i = 0; i < 32; i++) {
        Y[i] = X[i] > 0 ? X[i] : 0;
    }
}

void node_Gemm_4(const float tensor_10[1][32], const float tensor_linear_list_2_weight[3][32], const float tensor_linear_list_2_bias[3], float tensor_output[1][3]) {
    const int M = 1;
    const int K = 32;
    const int N = 3;
    float (*A)[32] = (float(*)[32])tensor_10;
    float (*Y)[3] = (float(*)[3])tensor_output;
    float alpha = 1.0f;
    float beta = 1.0f;
    float (*C)[3] = (float(*)[3])tensor_linear_list_2_bias;

    for (uint32_t r = 0; r < M; r++) {
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
}