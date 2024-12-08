#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdint.h>

// Model parameters
static const float tensor_q_net_0_weight[64][8] = {
    // Include tensor weights here...
};

static const float tensor_q_net_0_bias[64] = {
    // Include tensor biases here...
};

static const float tensor_q_net_2_weight[64][64] = {
    // Include tensor weights here...
};

static const float tensor_q_net_2_bias[64] = {
    // Include tensor biases here...
};

static const float tensor_q_net_4_weight[4][64] = {
    // Include tensor weights here...
};

static const float tensor_q_net_4_bias[4] = {
    // Include tensor biases here...
};

// Support functions
static inline void node_Flatten_0(const float tensor_input[1][8], float tensor_7[1][8]) {
    float *input = (float*)tensor_input;
    for(uint32_t i = 0; i < 8; i++) {
        tensor_7[0][i] = input[i];
    }
}

static inline void node_Gemm_1(const float tensor_7[1][8], float tensor_8[1][64]) {
    const int M = 1;
    const int K = 8;
    const int N = 64;
    float alpha = 1.0f;
    float beta = 1.0f;
    
    for(uint32_t r = 0; r < M; r++) {
        for(uint32_t c = 0; c < N; c++) {
            float ABrc = 0;
            for(uint32_t i = 0; i < K; i++) {
                ABrc += tensor_7[r][i] * tensor_q_net_0_weight[c][i];
            }
            tensor_8[r][c] = (ABrc * alpha) + (tensor_q_net_0_bias[c] * beta);
        }
    }
}

static inline void node_Relu_2(const float tensor_8[1][64], float tensor_9[1][64]) {
    for(uint32_t i = 0; i < 64; i++) {
        tensor_9[0][i] = tensor_8[0][i] > 0 ? tensor_8[0][i] : 0;
    }
}

static inline void node_Gemm_3(const float tensor_9[1][64], float tensor_10[1][64]) {
    const int M = 1;
    const int K = 64;
    const int N = 64;
    float alpha = 1.0f;
    float beta = 1.0f;
    
    for(uint32_t r = 0; r < M; r++) {
        for(uint32_t c = 0; c < N; c++) {
            float ABrc = 0;
            for(uint32_t i = 0; i < K; i++) {
                ABrc += tensor_9[r][i] * tensor_q_net_2_weight[c][i];
            }
            tensor_10[r][c] = (ABrc * alpha) + (tensor_q_net_2_bias[c] * beta);
        }
    }
}

static inline void node_Relu_4(const float tensor_10[1][64], float tensor_11[1][64]) {
    for(uint32_t i = 0; i < 64; i++) {
        tensor_11[0][i] = tensor_10[0][i] > 0 ? tensor_10[0][i] : 0;
    }
}

static inline void node_Gemm_5(const float tensor_11[1][64], float tensor_output[1][4]) {
    const int M = 1;
    const int K = 64;
    const int N = 4;
    float alpha = 1.0f;
    float beta = 1.0f;
    
    for(uint32_t r = 0; r < M; r++) {
        for(uint32_t c = 0; c < N; c++) {
            float ABrc = 0;
            for(uint32_t i = 0; i < K; i++) {
                ABrc += tensor_11[r][i] * tensor_q_net_4_weight[c][i];
            }
            tensor_output[r][c] = (ABrc * alpha) + (tensor_q_net_4_bias[c] * beta);
        }
    }
}

void entry(const float tensor_input[1][8], float tensor_output[1][4]) {
    float tensor_7[1][8];
    float tensor_8[1][64];
    float tensor_9[1][64];
    float tensor_10[1][64];
    float tensor_11[1][64];
    
    node_Flatten_0(tensor_input, tensor_7);
    node_Gemm_1(tensor_7, tensor_8);
    node_Relu_2(tensor_8, tensor_9);
    node_Gemm_3(tensor_9, tensor_10);
    node_Relu_4(tensor_10, tensor_11);
    node_Gemm_5(tensor_11, tensor_output);
}

int main() {
    // Define fixed tensor inputs
    float tensor_input[1][8] = {
        {-0.786292, 0.0457, 0.024, -0.0467, -0.1186, -0.0738, 1.0, 1.0}
    };

    float tensor_output[1][4];
    
    // Execute model entry function
    entry(tensor_input, tensor_output);

    // Custom assertion equivalent
    assert(!(tensor_output[0][2] <= tensor_output[0][3]));

    // Print output for demonstration
    for (int i = 0; i < 4; i++) {
        printf("tensor_output[0][%d] = %.5f\n", i, tensor_output[0][i]);
    }

    return 0;
}