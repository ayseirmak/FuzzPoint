#include <stdio.h>
#include <math.h>
#include <stdint.h>
#include <stdbool.h>

// Define constants
#define NUM_INPUTS 8
#define NUM_OUTPUTS 4
#define NUM_HIDDEN_1 64
#define NUM_HIDDEN_2 64

// Define fixed inputs
float fixed_tensor_input[1][NUM_INPUTS] = {
    {-0.9f, 0.05f, 0.06f, -0.02f, -0.4f, 0.01f, 1.0f, 1.0f}
};

// Define weights and biases (example values, need to be filled with actual model data)
static const float tensor_q_net_0_weight[NUM_HIDDEN_1][NUM_INPUTS] = {/* Fill with weights */};
static const float tensor_q_net_0_bias[NUM_HIDDEN_1] = {/* Fill with biases */};
static const float tensor_q_net_2_weight[NUM_HIDDEN_2][NUM_HIDDEN_1] = {/* Fill with weights */};
static const float tensor_q_net_2_bias[NUM_HIDDEN_2] = {/* Fill with biases */};
static const float tensor_q_net_4_weight[NUM_OUTPUTS][NUM_HIDDEN_2] = {/* Fill with weights */};
static const float tensor_q_net_4_bias[NUM_OUTPUTS] = {/* Fill with biases */};

void flatten(const float input[1][NUM_INPUTS], float output[1][NUM_INPUTS]) {
    for (uint32_t i = 0; i < NUM_INPUTS; i++) {
        output[0][i] = input[0][i];
    }
}

void gemm(int M, int K, int N, const float A[M][K], const float B[N][K], const float bias[N], float Y[M][N]) {
    for (uint32_t r = 0; r < M; r++) {
        for (uint32_t c = 0; c < N; c++) {
            float sum = bias[c];
            for (uint32_t i = 0; i < K; i++) {
                sum += A[r][i] * B[c][i];
            }
            Y[r][c] = sum;
        }
    }
}

void relu(int M, int N, const float X[M][N], float Y[M][N]) {
    for (uint32_t r = 0; r < M; r++) {
        for (uint32_t c = 0; c < N; c++) {
            Y[r][c] = X[r][c] > 0 ? X[r][c] : 0;
        }
    }
}

void entry(const float tensor_input[1][NUM_INPUTS], float tensor_output[1][NUM_OUTPUTS]) {
    float tensor_7[1][NUM_INPUTS];
    float tensor_8[1][NUM_HIDDEN_1];
    float tensor_9[1][NUM_HIDDEN_1];
    float tensor_10[1][NUM_HIDDEN_2];
    float tensor_11[1][NUM_HIDDEN_2];

    flatten(tensor_input, tensor_7);
    gemm(1, NUM_INPUTS, NUM_HIDDEN_1, tensor_7, tensor_q_net_0_weight, tensor_q_net_0_bias, tensor_8);
    relu(1, NUM_HIDDEN_1, tensor_8, tensor_9);
    gemm(1, NUM_HIDDEN_1, NUM_HIDDEN_2, tensor_9, tensor_q_net_2_weight, tensor_q_net_2_bias, tensor_10);
    relu(1, NUM_HIDDEN_2, tensor_10, tensor_11);
    gemm(1, NUM_HIDDEN_2, NUM_OUTPUTS, tensor_11, tensor_q_net_4_weight, tensor_q_net_4_bias, tensor_output);
}

int main() {
    float tensor_output[1][NUM_OUTPUTS];
    entry(fixed_tensor_input, tensor_output);

    printf("Output tensor values:\n");
    for (int i = 0; i < NUM_OUTPUTS; i++) {
        printf("%f\n", tensor_output[0][i]);
    }

    return 0;
}