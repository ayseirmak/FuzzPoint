#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <stdint.h>

// Define the function signatures
void node_Flatten_0(const float tensor_input[1][4], float tensor_7[1][4]);
void node_Gemm_1(const float tensor_7[1][4], const float tensor_q_net_0_weight[64][4], const float tensor_q_net_0_bias[64], float tensor_8[1][64]);
void node_Relu_2(const float tensor_8[1][64], float tensor_9[1][64]);
void node_Gemm_3(const float tensor_9[1][64], const float tensor_q_net_2_weight[64][64], const float tensor_q_net_2_bias[64], float tensor_10[1][64]);
void node_Relu_4(const float tensor_10[1][64], float tensor_11[1][64]);
void node_Gemm_5(const float tensor_11[1][64], const float tensor_q_net_4_weight[2][64], const float tensor_q_net_4_bias[2], float tensor_output[1][2]);

void entry(const float tensor_input[1][4], float tensor_output[1][2]);

int main()
{
    // Fixed values for deterministic input
    float tensor_input[1][4] = {
        {-0.245, -0.250, -0.053, -0.035}
    };

    float tensor_output[1][2];

    // Calling the entry point function
    entry(tensor_input, tensor_output);

    // Asserting that the second output is greater than the first output
    assert(!(tensor_output[0][1] <= tensor_output[0][0]));

    printf("Test Passed: tensor_output[0][0] = %f, tensor_output[0][1] = %f\n", tensor_output[0][0], tensor_output[0][1]);
    
    return 0;
}

// Place other function implementations here (node functions)