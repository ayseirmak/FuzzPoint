#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <stdint.h>

// Constants from the original model
static const float tensor_q_net_0_weight[64][8] = {
    // (truncated for brevity...)
    {0.21815462410449981689f, 0.23126253485679626465f, -0.14049024879932403564f, 0.39555677771568298340f, 0.38167867064476013184f, 0.29623535275459289551f, -0.11851222068071365356f, 0.38335996866226196289f},
    // (Other elements of the 64x8 matrix)
};

static const float tensor_q_net_0_bias[64] = {
    // (truncated for brevity...)
    0.12845531105995178223f, 0.41714116930961608887f, 0.14017663896083831787f, -0.13708075881004333496f
    // (Other elements of the 64-element array)
};

static const float tensor_q_net_2_weight[64][64] = {
    // (truncated for brevity...)
    {0.039809726178646087646f, -0.050762739032506942749f, -0.19122810661792755127f, 0.13844394683837890625f, -0.093590117990970611572f, 0.27353912591934204102f, 0.15563592314720153809f, 0.11391936242580413818f},
    // (Other elements of the 64x64 matrix)
};

static const float tensor_q_net_2_bias[64] = {
    // (truncated for brevity...)
    0.10505031049251556396f, -0.051322553306818008423f, -0.040096297860145568848f
    // (Other elements of the 64-element array)
};

static const float tensor_q_net_4_weight[4][64] = {
    // (truncated for brevity...)
    {-0.17162241041660308838f, -0.080019518733024597168f, 0.39136415719985961914f},
    // (Other elements of the 4x64 matrix)
};

static const float tensor_q_net_4_bias[4] = {0.058722577989101409912f, -0.026569778099656105042f, 0.099756106734275817871f, -0.051060039550065994263f};

// Forward declaration of functions
void entry(const float tensor_input[1][8], float tensor_output[1][4]);

int main() {
    float tensor_input[1][8];
    float tensor_output[1][4];

    // Deterministic input values within the specified ranges
    tensor_input[0][0] = -0.7f;
    tensor_input[0][1] = 0.075f;
    tensor_input[0][2] = 0.03f;
    tensor_input[0][3] = -0.03f;
    tensor_input[0][4] = -0.05f;
    tensor_input[0][5] = -0.05f;
    tensor_input[0][6] = 1.0f;
    tensor_input[0][7] = 1.0f;

    entry(tensor_input, tensor_output);

    assert(!(tensor_output[0][2] <= tensor_output[0][3]));

    return 0;
}

void entry(const float tensor_input[1][8], float tensor_output[1][4]) {
    // Stored computations
    float tensor_7[1][8];
    float tensor_9[1][64];
    float tensor_11[1][64];
    float tensor_8[1][64];
    float tensor_10[1][64];

    for (int i = 0; i < 8; ++i) {
        tensor_7[0][i] = tensor_input[0][i];
    }

    for (int i = 0; i < 64; ++i) {
        tensor_8[0][i] = tensor_q_net_0_bias[i];
        for (int j = 0; j < 8; ++j) {
            tensor_8[0][i] += tensor_7[0][j] * tensor_q_net_0_weight[i][j];
        }
        tensor_9[0][i] = fmaxf(tensor_8[0][i], 0.0f);
    }

    for (int i = 0; i < 64; ++i) {
        tensor_10[0][i] = tensor_q_net_2_bias[i];
        for (int j = 0; j < 64; ++j) {
            tensor_10[0][i] += tensor_9[0][j] * tensor_q_net_2_weight[i][j];
        }
        tensor_11[0][i] = fmaxf(tensor_10[0][i], 0.0f);
    }

    for (int i = 0; i < 4; ++i) {
        tensor_output[0][i] = tensor_q_net_4_bias[i];
        for (int j = 0; j < 64; ++j) {
            tensor_output[0][i] += tensor_11[0][j] * tensor_q_net_4_weight[i][j];
        }
    }
}