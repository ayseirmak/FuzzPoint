#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

// Function prototypes
void entry(const float tensor_input[1][5], float tensor_output[1][5]);
void node_Gemm_0(const float tensor_input[1][5], const float tensor_linear_list_0_weight[64][5], const float tensor_linear_list_0_bias[64], float tensor_9[1][64]);
void node_Relu_1(const float tensor_9[1][64], float tensor_10[1][64]);
void node_Gemm_2(const float tensor_10[1][64], const float tensor_linear_list_1_weight[64][64], const float tensor_linear_list_1_bias[64], float tensor_11[1][64]);
void node_Relu_3(const float tensor_11[1][64], float tensor_12[1][64]);
void node_Gemm_4(const float tensor_12[1][64], const float tensor_linear_list_2_weight[64][64], const float tensor_linear_list_2_bias[64], float tensor_13[1][64]);
void node_Relu_5(const float tensor_13[1][64], float tensor_14[1][64]);
void node_Gemm_6(const float tensor_14[1][64], const float tensor_linear_list_3_weight[5][64], const float tensor_linear_list_3_bias[5], float tensor_output[1][5]);

static const float tensor_linear_list_0_weight[64][5] = {
  {-0.0091603128239512443542f, -0.58216774463653564453f, -0.69003760814666748047f, 0.25509926676750183105f, 0.14821812510490417480f}, /* ... additional rows omitted for brevity ... */ };

static const float tensor_linear_list_0_bias[64] = 
{0.063785068690776824951f, 0.33931511640548706055f, /* ... additional elements omitted for brevity ... */ };

static const float tensor_linear_list_1_weight[64][64] = {
  {0.029085977002978324890f, -0.099531978368759155273f, /* ... additional elements omitted for brevity ... */ }, /* ... additional rows omitted for brevity ... */ };

static const float tensor_linear_list_1_bias[64] = 
{-0.11281843483448028564f, 0.087034560739994049072f, /* ... additional elements omitted for brevity ... */ };

// Additional static variables for weights and biases (ellipsis indicate shortened content for brevity)
// tensor_linear_list_2_weight, tensor_linear_list_2_bias, tensor_linear_list_3_weight, tensor_linear_list_3_bias

int main() {
    float tensor_input[1][5] = { {-1.5f, -1.5f, 0.785398163F, 1.25f, 1.25f} };  // Deterministic input
    float tensor_output[1][5];

    entry(tensor_input, tensor_output);

    bool condition = !((tensor_output[0][1] <= 0.04889690792887813) &&
                       (tensor_output[0][1] >= -0.04889690792887813) &&
                       (tensor_output[0][2] <= 0.04889690792887813) &&
                       (tensor_output[0][2] >= -0.04889690792887813) &&
                       (tensor_output[0][0] >= 0.2430583183337539));
                       
    assert(condition);

    return 0;
}

// Function implementations for Gemm and Relu nodes
// ... (Same as provided in the original code; ellipsed here for brevity) ...