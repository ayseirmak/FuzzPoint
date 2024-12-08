#include <stdio.h>
#include <math.h>
#include <stdint.h>
#include <stdbool.h>
#include <assert.h>

void entry(const float tensor_input[1][8], float tensor_output[1][4]);

static const float fixed_tensor_input[1][8] = {
  {0.0f, 0.2f, 0.55f, 0.0f, -0.05f, -0.1f, 0.0f, 0.0f }
};

int main() {
    float tensor_output[1][4];
    
    entry(fixed_tensor_input, tensor_output);
    
    // Verify the output
    assert(!(tensor_output[0][3] <= tensor_output[0][0]));
    
    for (int i = 0; i < 4; ++i) {
        printf("tensor_output[0][%d]: %f\n", i, tensor_output[0][i]);
    }

    return 0;
}

void entry(const float tensor_input[1][8], float tensor_output[1][4]) {
    // Assumes tensor_input[1][8] and tensor_output[1][4] are declared elsewhere

    union tensor_union_0 {
        float tensor_7[1][8];
        float tensor_9[1][64];
        float tensor_11[1][64];
    };
    static union tensor_union_0 tu0;

    union tensor_union_1 {
        float tensor_8[1][64];
        float tensor_10[1][64];
    };
    static union tensor_union_1 tu1;

    static inline void node_Flatten_0(const float tensor_input[1][8], float tensor_7[1][8]) {
        for (uint32_t i = 0; i < 8; i++) 
            tensor_7[0][i] = tensor_input[0][i];
    }

    static inline void node_Gemm_1(const float tensor_7[1][8], const float tensor_q_net_0_weight[64][8], const float tensor_q_net_0_bias[64], float tensor_8[1][64]) {
        for (uint32_t c = 0; c < 64; c++) {
            float ABrc = 0;
            for (uint32_t i = 0; i < 8; i++) 
                ABrc += tensor_7[0][i] * tensor_q_net_0_weight[c][i];
            tensor_8[0][c] = ABrc + tensor_q_net_0_bias[c];
        }
    }

    static inline void node_Relu_2(const float tensor_8[1][64], float tensor_9[1][64]) {
        for (uint32_t i = 0; i < 64; i++) 
            tensor_9[0][i] = tensor_8[0][i] > 0 ? tensor_8[0][i] : 0;
    }

    static inline void node_Gemm_3(const float tensor_9[1][64], const float tensor_q_net_2_weight[64][64], const float tensor_q_net_2_bias[64], float tensor_10[1][64]) {
        for (uint32_t c = 0; c < 64; c++) {
            float ABrc = 0;
            for (uint32_t i = 0; i < 64; i++) 
                ABrc += tensor_9[0][i] * tensor_q_net_2_weight[c][i];
            tensor_10[0][c] = ABrc + tensor_q_net_2_bias[c];
        }
    }

    static inline void node_Relu_4(const float tensor_10[1][64], float tensor_11[1][64]) {
        for (uint32_t i = 0; i < 64; i++) 
            tensor_11[0][i] = tensor_10[0][i] > 0 ? tensor_10[0][i] : 0;
    }

    static inline void node_Gemm_5(const float tensor_11[1][64], const float tensor_q_net_4_weight[4][64], const float tensor_q_net_4_bias[4], float tensor_output[1][4]) {
        for (uint32_t c = 0; c < 4; c++) {
            float ABrc = 0;
            for (uint32_t i = 0; i < 64; i++) 
                ABrc += tensor_11[0][i] * tensor_q_net_4_weight[c][i];
            tensor_output[0][c] = ABrc + tensor_q_net_4_bias[c];
        }
    }

    node_Flatten_0(tensor_input, tu0.tensor_7);
    node_Gemm_1(tu0.tensor_7, tensor_q_net_0_weight, tensor_q_net_0_bias, tu1.tensor_8);
    node_Relu_2(tu1.tensor_8, tu0.tensor_9);
    node_Gemm_3(tu0.tensor_9, tensor_q_net_2_weight, tensor_q_net_2_bias, tu1.tensor_10);
    node_Relu_4(tu1.tensor_10, tu0.tensor_11);
    node_Gemm_5(tu0.tensor_11, tensor_q_net_4_weight, tensor_q_net_4_bias, tensor_output);
}