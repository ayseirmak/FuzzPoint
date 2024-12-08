#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define MIN(X,Y) ((X) < (Y) ? (X) : (Y))
#define MAX(X,Y) ((X) > (Y) ? (X) : (Y))

// Pre-generated model weights and biases (truncated for brevity)
static const float tensor_linear_list_0_weight[64][5] = {/* Weights go here */ };
static const float tensor_linear_list_0_bias[64] = {/* Biases go here */ };
static const float tensor_linear_list_1_weight[64][64] = {/* Weights go here */ };
static const float tensor_linear_list_1_bias[64] = {/* Biases go here */ };
static const float tensor_linear_list_2_weight[64][64] = {/* Weights go here */ };
static const float tensor_linear_list_2_bias[64] = {/* Biases go here */ };
static const float tensor_linear_list_3_weight[5][64] = {/* Weights go here */ };
static const float tensor_linear_list_3_bias[5] = {/* Biases go here */ };

void gemm(const float* A, const float* B, const float* C, float* Y, int M, int N, int K, float alpha, float beta, bool transB) {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            float acc = 0.0f;
            for (int k = 0; k < K; k++) {
                acc += A[i * K + k] * (transB ? B[j * K + k] : B[k * N + j]);
            }
            Y[i * N + j] = acc * alpha + C[j] * beta;
        }
    }
}

void relu(float* X, float* Y, int size) {
    for (int i = 0; i < size; i++) {
        Y[i] = fmaxf(0, X[i]);
    }
}

void entry(const float tensor_input[1][5], float tensor_output[1][5]) {
    float tensor_9[64], tensor_10[64], tensor_11[64], tensor_12[64], tensor_13[64], tensor_14[64];

    gemm(&tensor_input[0][0], &tensor_linear_list_0_weight[0][0], tensor_linear_list_0_bias, tensor_9, 1, 64, 5, 1.0f, 1.0f, true);
    relu(tensor_9, tensor_10, 64);
    gemm(tensor_10, &tensor_linear_list_1_weight[0][0], tensor_linear_list_1_bias, tensor_11, 1, 64, 64, 1.0f, 1.0f, true);
    relu(tensor_11, tensor_12, 64);
    gemm(tensor_12, &tensor_linear_list_2_weight[0][0], tensor_linear_list_2_bias, tensor_13, 1, 64, 64, 1.0f, 1.0f, true);
    relu(tensor_13, tensor_14, 64);
    gemm(tensor_14, &tensor_linear_list_3_weight[0][0], tensor_linear_list_3_bias, &tensor_output[0][0], 1, 5, 64, 1.0f, 1.0f, true);
}

int main() {
    float tensor_input[1][5] = { {-1.5f, -1.5f, 0.7853f, 1.25f, 1.25f} };
    float tensor_output[1][5];

    entry(tensor_input, tensor_output);

    bool condition = !(tensor_output[0][1] <= 0.030230712 && tensor_output[0][1] >= -0.030230712 &&
                       tensor_output[0][2] <= 0.030230712 && tensor_output[0][2] >= -0.030230712 &&
                       tensor_output[0][0] >= 0.159978677);

    if (condition) {
        printf("Assertion failed\n");
    } else {
        printf("Output met condition\n");
    }

    return 0;
}