#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

// Function prototypes
void entry(const float tensor_input[1][8], float tensor_output[1][4]);

// Initialize constants
static const float tensor_q_net_0_weight[64][8] = {
  {0.21815462410449981689f, 0.23126253485679626465f, -0.14049024879932403564f, 0.39555677771568298340f, 0.38167867064476013184f, 0.29623535275459289551f, -0.11851222068071365356f, 0.38335996866226196289f},
  //... (truncated for brevity)
};
static const float tensor_q_net_0_bias[64] = {
  0.12845531105995178223f, 0.41714116930961608887f, 0.14017663896083831787f,
  //... (truncated for brevity)
};
static const float tensor_q_net_2_weight[64][64] = {
  {0.039809726178646087646f, -0.050762739032506942749f, -0.19122810661792755127f, 0.13844394683837890625f,
  //... (truncated for brevity)
};
static const float tensor_q_net_2_bias[64] = {
  0.10505031049251556396f, -0.051322553306818008423f, -0.040096297860145568848f,
  //... (truncated for brevity)
};
static const float tensor_q_net_4_weight[4][64] = {
  {-0.17162241041660308838f, -0.080019518733024597168f, 0.39136415719985961914f, -0.12776407599449157715f,
  //... (truncated for brevity)
};
static const float tensor_q_net_4_bias[4] = {
  0.058722577989101409912f, -0.026569778099656105042f, 0.099756106734275817871f,
  //... (truncated for brevity)
};

// Define unified tensors for transformation
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

// Define the computational functions
static inline void node_Flatten_0(const float tensor_input[1][8], float tensor_7[1][8]){
    memcpy(tensor_7, tensor_input, sizeof(tensor_7));
}

static inline void node_Gemm_1(const float tensor_7[1][8], const float tensor_q_net_0_weight[64][8], const float tensor_q_net_0_bias[64], float tensor_8[1][64]){
    for (int r = 0; r < 1; r++){
        for (int c = 0; c < 64; c++) {
            float ABrc = 0;
            for (int i = 0; i < 8; i++) {
                ABrc += tensor_7[r][i] * tensor_q_net_0_weight[c][i];
            }
            tensor_8[r][c] = ABrc + tensor_q_net_0_bias[c];
        }
    }
}

static inline void node_Relu_2(const float tensor_8[1][64], float tensor_9[1][64]){
    for (int i = 0; i < 64; i++){
        tensor_9[0][i] = fmax(tensor_8[0][i], 0);
    }
}

static inline void node_Gemm_3(const float tensor_9[1][64], const float tensor_q_net_2_weight[64][64], const float tensor_q_net_2_bias[64], float tensor_10[1][64]){
    for (int r = 0; r < 1; r++){
        for (int c = 0; c < 64; c++) {
            float ABrc = 0;
            for (int i = 0; i < 64; i++) {
                ABrc += tensor_9[r][i] * tensor_q_net_2_weight[c][i];
            }
            tensor_10[r][c] = ABrc + tensor_q_net_2_bias[c];
        }
    }
}

static inline void node_Relu_4(const float tensor_10[1][64], float tensor_11[1][64]){
    for (int i = 0; i < 64; i++){
        tensor_11[0][i] = fmax(tensor_10[0][i], 0);
    }
}

static inline void node_Gemm_5(const float tensor_11[1][64], const float tensor_q_net_4_weight[4][64], const float tensor_q_net_4_bias[4], float tensor_output[1][4]){
    for (int r = 0; r < 1; r++){
        for (int c = 0; c < 4; c++) {
            float ABrc = 0;
            for (int i = 0; i < 64; i++) {
                ABrc += tensor_11[r][i] * tensor_q_net_4_weight[c][i];
            }
            tensor_output[r][c] = ABrc + tensor_q_net_4_bias[c];
        }
    }
}

void entry(const float tensor_input[1][8], float tensor_output[1][4]) {
    node_Flatten_0(tensor_input, tu0.tensor_7);
    node_Gemm_1(tu0.tensor_7, tensor_q_net_0_weight, tensor_q_net_0_bias, tu1.tensor_8);
    node_Relu_2(tu1.tensor_8, tu0.tensor_9);
    node_Gemm_3(tu0.tensor_9, tensor_q_net_2_weight, tensor_q_net_2_bias, tu1.tensor_10);
    node_Relu_4(tu1.tensor_10, tu0.tensor_11);
    node_Gemm_5(tu0.tensor_11, tensor_q_net_4_weight, tensor_q_net_4_bias, tensor_output);
}

int main() {
    float tensor_input[1][8] = {
        {-0.7f, 0.0f, 0.0f, 0.05f, -0.08f, 0.05f, 1.0f, 1.0f}
    };
    float tensor_output[1][4];

    entry(tensor_input, tensor_output);

    // Output check
    assert(!(tensor_output[0][3] <= tensor_output[0][2]));

    return 0;
}