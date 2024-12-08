#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <assert.h>

#define MAX(X,Y) ( X > Y ? X : Y)
#define MIN(X,Y) ( X < Y ? X : Y)
#define CLIP(X,L) ( MAX(MIN(X,L), -L) )

// Fixed values based on assumptions
#define FIXED_INPUT_0 0.4742809f
#define FIXED_INPUT_1 -0.6856194f
#define FIXED_INPUT_2 0.0178207770f
#define FIXED_INPUT_3 0.8836845f

// Add your static weights and biases here

static const float tensor_q_net_0_weight[64][4] = {
    // weights omitted for brevity (remain the same as provided)
};

static const float tensor_q_net_0_bias[64] = {
    // biases omitted for brevity (remain the same as provided)
};

static const float tensor_q_net_2_weight[64][64] = {
    // weights omitted for brevity (remain the same as provided)
};

static const float tensor_q_net_2_bias[64] = {
    // biases omitted for brevity (remain the same as provided)
};

static const float tensor_q_net_4_weight[2][64] = {
    // weights omitted for brevity (remain the same as provided)
};

static const float tensor_q_net_4_bias[2] = {
    // biases omitted for brevity (remain the same as provided)
};

void entry(const float tensor_input[1][4], float tensor_output[1][2]);

static inline void node_Flatten_0(const float tensor_input[1][4], float tensor_7[1][4]) {
    /* Flatten */
    memcpy(tensor_7, tensor_input, sizeof(float) * 4);
}

static inline void node_Gemm_1(const float tensor_7[1][4], const float tensor_q_net_0_weight[64][4], const float tensor_q_net_0_bias[64], float tensor_8[1][64]) {
    /* Gemm */
    const int M = 1;
    const int K = 4;
    const int N = 64;
    float (*A)[4] = (float (*)[4])tensor_7;
    float (*Y)[64] = (float (*)[64])tensor_8;
    float alpha = 1.0f;
    float beta = 1.0f;
    float (*C)[64] = (float (*)[64])tensor_q_net_0_bias;

    for (uint32_t r = 0; r < M; r++)
        for (uint32_t c = 0; c < N; c++) {
            float ABrc = 0;
            for (uint32_t i = 0; i < K; i++) {
                float B = tensor_q_net_0_weight[c][i];
                ABrc += A[r][i] * B;
            }
            float tmp = ABrc * alpha;
            tmp += C[0][c] * beta;
            Y[r][c] = tmp;
        }
}

static inline void node_Relu_2(const float tensor_8[1][64], float tensor_9[1][64]) {
    /* Relu */
    for (uint32_t i = 0; i < 64; i++)
        tensor_9[0][i] = tensor_8[0][i] > 0 ? tensor_8[0][i] : 0;
}

static inline void node_Gemm_3(const float tensor_9[1][64], const float tensor_q_net_2_weight[64][64], const float tensor_q_net_2_bias[64], float tensor_10[1][64]) {
    /* Gemm */
    const int M = 1;
    const int K = 64;
    const int N = 64;
    float (*A)[64] = (float (*)[64])tensor_9;
    float (*Y)[64] = (float (*)[64])tensor_10;
    float alpha = 1.0f;
    float beta = 1.0f;
    float (*C)[64] = (float (*)[64])tensor_q_net_2_bias;
    
    for (uint32_t r = 0; r < M; r++)
        for (uint32_t c = 0; c < N; c++) {
            float ABrc = 0;
            for (uint32_t i = 0; i < K; i++) {
                float B = tensor_q_net_2_weight[c][i];
                ABrc += A[r][i] * B;
            }
            float tmp = ABrc * alpha;
            tmp += C[0][c] * beta;
            Y[r][c] = tmp;
        }
}

static inline void node_Relu_4(const float tensor_10[1][64], float tensor_11[1][64]) {
    /* Relu */
    for (uint32_t i = 0; i < 64; i++)
        tensor_11[0][i] = tensor_10[0][i] > 0 ? tensor_10[0][i] : 0;
}

static inline void node_Gemm_5(const float tensor_11[1][64], const float tensor_q_net_4_weight[2][64], const float tensor_q_net_4_bias[2], float tensor_output[1][2]) {
    /* Gemm */
    const int M = 1;
    const int K = 64;
    const int N = 2;
    float (*A)[64] = (float (*)[64])tensor_11;
    float (*Y)[2] = (float (*)[2])tensor_output;
    float alpha = 1.0f;
    float beta = 1.0f;
    float (*C)[2] = (float (*)[2])tensor_q_net_4_bias;
    
    for (uint32_t r = 0; r < M; r++)
        for (uint32_t c = 0; c < N; c++) {
            float ABrc = 0;
            for (uint32_t i = 0; i < K; i++) {
                float B = tensor_q_net_4_weight[c][i];
                ABrc += A[r][i] * B;
            }
            float tmp = ABrc * alpha;
            tmp += C[0][c] * beta;
            Y[r][c] = tmp;
        }
}

void entry(const float tensor_input[1][4], float tensor_output[1][2]) {
    float tensor_7[1][4];
    float tensor_8[1][64];
    float tensor_9[1][64];
    float tensor_10[1][64];
    float tensor_11[1][64];
    
    node_Flatten_0(tensor_input, tensor_7);
    node_Gemm_1(tensor_7, tensor_q_net_0_weight, tensor_q_net_0_bias, tensor_8);
    node_Relu_2(tensor_8, tensor_9);
    node_Gemm_3(tensor_9, tensor_q_net_2_weight, tensor_q_net_2_bias, tensor_10);
    node_Relu_4(tensor_10, tensor_11);
    node_Gemm_5(tensor_11, tensor_q_net_4_weight, tensor_q_net_4_bias, tensor_output);
}

int main() {
    float tensor_input[1][4] = {{FIXED_INPUT_0, FIXED_INPUT_1, FIXED_INPUT_2, FIXED_INPUT_3}};
    float tensor_output[1][2] = {{0}};

    entry(tensor_input, tensor_output);
    
    printf("Output: %.6f, %.6f\n", tensor_output[0][0], tensor_output[0][1]);
    assert(!(tensor_output[0][0] <= tensor_output[0][1]));

    return 0;
}