#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdint.h>

#define MAX(X,Y) ( (X) > (Y) ? (X) : (Y))
#define MIN(X,Y) ( (X) < (Y) ? (X) : (Y))
#define CLIP(X,L) ( MAX(MIN(X,L), -L) )

// Declare static constants here (as provided in the original code)
// ... [tensor_q_net_0_weight, tensor_q_net_0_bias, tensor_q_net_2_weight, tensor_q_net_2_bias, tensor_q_net_4_weight, tensor_q_net_4_bias] ...

typedef union {
    float tensor_7[1][4];
    float tensor_9[1][64];
    float tensor_11[1][64];
} tensor_union_0;

typedef union {
    float tensor_8[1][64];
    float tensor_10[1][64];
} tensor_union_1;

static tensor_union_0 tu0;
static tensor_union_1 tu1;

static inline void node_Flatten_0(const float tensor_input[1][4], float tensor_7[1][4]) {
    /* Flatten*/
    float *input = (float*)tensor_input;
    float *output = (float*)tensor_7;
    for (uint32_t i = 0; i < 4; i++)
        output[i] = input[i];
}

//... [Rest of the node functions remain unchanged, just as in the original code] ...

void entry(const float tensor_input[1][4], float tensor_output[1][2]) {
    node_Flatten_0(tensor_input, tu0.tensor_7);
    node_Gemm_1(tu0.tensor_7, tensor_q_net_0_weight, tensor_q_net_0_bias, tu1.tensor_8);
    node_Relu_2(tu1.tensor_8, tu0.tensor_9);
    node_Gemm_3(tu0.tensor_9, tensor_q_net_2_weight, tensor_q_net_2_bias, tu1.tensor_10);
    node_Relu_4(tu1.tensor_10, tu0.tensor_11);
    node_Gemm_5(tu0.tensor_11, tensor_q_net_4_weight, tensor_q_net_4_bias, tensor_output);
}

int main() {
    float tensor_input[1][4] = {
        {0.442, -0.688, 0.061, 0.945} // Fixed values within the __VERIFIER_assume bounds for each index
    };
    float tensor_output[1][2];

    entry(tensor_input, tensor_output);

    assert(!(tensor_output[0][1] <= tensor_output[0][0]));
    printf("Tensor output[0][0]: %f\n", tensor_output[0][0]);
    printf("Tensor output[0][1]: %f\n", tensor_output[0][1]);
    
    return 0;
}