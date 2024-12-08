#include <stdio.h>
#include <assert.h>

// Function prototypes
void entry(const float tensor_input[1][5], float tensor_output[1][5]);

// Node functions
static inline void node_Gemm_0( 
    const float tensor_input[1][5], 
    const float tensor_linear_list_0_weight[64][5], 
    const float tensor_linear_list_0_bias[64], 
    float tensor_9[1][64] 
) {
    const int M = 1;
    const int K = 5;
    const int N = 64;
    float (*A)[5] = (float(*)[5])tensor_input;
    float (*Y)[64] = (float(*)[64])tensor_9;
    float alpha = 1.0;
    float beta = 1.0;
    float (*C)[64] = (float(*)[64])tensor_linear_list_0_bias;
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

static inline void node_Relu_1(const float tensor_9[1][64], float tensor_10[1][64]) {
    float *X = (float*)tensor_9;
    float *Y = (float*)tensor_10;
    for (uint32_t i = 0; i < 64; i++)
        Y[i] = X[i] > 0 ? X[i] : 0;
}

// Define other node functions (node_Gemm_2, node_Relu_3, node_Gemm_4, node_Relu_5, node_Gemm_6) similarly

// Union for tensors to reduce stack memory usage
union tensor_union_0 {
    float tensor_9[1][64];
    float tensor_11[1][64];
    float tensor_13[1][64];
};

union tensor_union_1 {
    float tensor_10[1][64];
    float tensor_12[1][64];
    float tensor_14[1][64];
};

// Function to execute the neural network model
void entry(const float tensor_input[1][5], float tensor_output[1][5]) {
    // Inter-layer tensors
    union tensor_union_0 tu0;
    union tensor_union_1 tu1;
    
    node_Gemm_0(tensor_input, tensor_linear_list_0_weight, tensor_linear_list_0_bias, tu0.tensor_9);
    node_Relu_1(tu0.tensor_9, tu1.tensor_10);
    node_Gemm_2(tu1.tensor_10, tensor_linear_list_1_weight, tensor_linear_list_1_bias, tu0.tensor_11);
    node_Relu_3(tu0.tensor_11, tu1.tensor_12);
    node_Gemm_4(tu1.tensor_12, tensor_linear_list_2_weight, tensor_linear_list_2_bias, tu0.tensor_13);
    node_Relu_5(tu0.tensor_13, tu1.tensor_14);
    node_Gemm_6(tu1.tensor_14, tensor_linear_list_3_weight, tensor_linear_list_3_bias, tensor_output);
}

int main() {
    float tensor_input[1][5] = {
        {-1.5f, -1.5f, 0.785398163f, 1.25f, 1.25f}
    };
    float tensor_output[1][5] = { 0 };

    entry(tensor_input, tensor_output);

    assert(!((tensor_output[0][1] <= 0.24500044796545045) && (tensor_output[0][1] >= -0.24500044796545045) &&
             (tensor_output[0][2] <= 0.24500044796545045) && (tensor_output[0][2] >= -0.24500044796545045) &&
             (tensor_output[0][0] >= 0.22185339654566427)));

    for (int i = 0; i < 5; ++i) {
        printf("Output[%d]: %f\n", i, tensor_output[0][i]);
    }

    return 0;
}