#include <stdio.h>
#include <math.h>
#include <stdint.h>
#include <assert.h>

#define MAX(X,Y) ( X > Y ? X : Y)
#define MIN(X,Y) ( X < Y ? X : Y)
#define CLIP(X,L) ( MAX(MIN(X,L), -L) )

// Declare arrays as static to avoid redeclaration
static const float tensor_q_net_0_weight[64][4] = {
    // Only a portion of the actual data is shown here to improve readability
    {0.15721032023429870605f, 0.11475459486246109009f, -0.63993811607360839844f, -0.069510847330093383789f},
    // ... (rest of the array)
};
static const float tensor_q_net_0_bias[64] = {
   // Static array initialization
   -0.038480948656797409058f, 0.12814424932003021240f, // ... (rest of the array)
};
static const float tensor_q_net_2_weight[64][64] = {
   // Static array initialization
   {-0.081372834742069244385f, 0.024248756468296051025f, // ... (rest of the array)
};
static const float tensor_q_net_2_bias[64] = {
   // Static array initialization
   0.0096521666273474693298f, 0.033651806414127349854f, // ... (rest of the array)
};
static const float tensor_q_net_4_weight[2][64] = {
    // Static array initialization
    {-0.10003891587257385254f, -0.22389468550682067871f, // ... (rest of the array)
};
static const float tensor_q_net_4_bias[2] = {
    // Static array initialization
    0.020197313278913497925f, 0.00082921260036528110504f,
};

// Static union to manage data across functions
static union {
    float tensor_7[1][4];
    float tensor_9[1][64];
    float tensor_11[1][64];
} tu0;

static union {
    float tensor_8[1][64];
    float tensor_10[1][64];
} tu1;

static void node_Flatten_0(const float tensor_input[1][4], float tensor_7[1][4]) {
    float *input = (float *)tensor_input;
    float *output = (float *)tensor_7;
    for (uint32_t i = 0; i < 4; i++)
        output[i] = input[i];
}

static void node_Gemm_1(const float tensor_7[1][4], const float tensor_q_net_0_weight[64][4], const float tensor_q_net_0_bias[64], float tensor_8[1][64]) {
    const int M = 1, K = 4, N = 64;
    float (*A)[4] = (float(*)[4])tensor_7;
    float (*Y)[64] = (float(*)[64])tensor_8;
    float alpha = 1.0, beta = 1.0;
    float (*C)[64] = (float(*)[64])tensor_q_net_0_bias;

    for (uint32_t r = 0; r < M; r++)
        for (uint32_t c = 0; c < N; c++) {
            float ABrc = 0;
            for (uint32_t i = 0; i < K; i++) {
                float B = tensor_q_net_0_weight[c][i];
                ABrc += A[r][i] * B;
            }
            float tmp = ABrc * alpha;
            tmp += C[0][c] * beta;
            Y[r][c] = tmp;
        }
}

static void node_Relu_2(const float tensor_8[1][64], float tensor_9[1][64]) {
    float *X = (float *)tensor_8;
    float *Y = (float *)tensor_9;
    for (uint32_t i = 0; i < 64; i++)
        Y[i] = X[i] > 0 ? X[i] : 0;
}

static void node_Gemm_3(const float tensor_9[1][64], const float tensor_q_net_2_weight[64][64], const float tensor_q_net_2_bias[64], float tensor_10[1][64]) {
    const int M = 1, K = 64, N = 64;
    float (*A)[64] = (float(*)[64])tensor_9;
    float (*Y)[64] = (float(*)[64])tensor_10;
    float alpha = 1.0, beta = 1.0;
    float (*C)[64] = (float(*)[64])tensor_q_net_2_bias;

    for (uint32_t r = 0; r < M; r++)
        for (uint32_t c = 0; c < N; c++) {
            float ABrc = 0;
            for (uint32_t i = 0; i < K; i++) {
                float B = tensor_q_net_2_weight[c][i];
                ABrc += A[r][i] * B;
            }
            float tmp = ABrc * alpha;
            tmp += C[0][c] * beta;
            Y[r][c] = tmp;
        }
}

static void node_Relu_4(const float tensor_10[1][64], float tensor_11[1][64]) {
    float *X = (float *)tensor_10;
    float *Y = (float *)tensor_11;
    for (uint32_t i = 0; i < 64; i++)
        Y[i] = X[i] > 0 ? X[i] : 0;
}

static void node_Gemm_5(const float tensor_11[1][64], const float tensor_q_net_4_weight[2][64], const float tensor_q_net_4_bias[2], float tensor_output[1][2]) {
    const int M = 1, K = 64, N = 2;
    float (*A)[64] = (float(*)[64])tensor_11;
    float (*Y)[2] = (float(*)[2])tensor_output;
    float alpha = 1.0, beta = 1.0;
    float (*C)[2] = (float(*)[2])tensor_q_net_4_bias;

    for (uint32_t r = 0; r < M; r++)
        for (uint32_t c = 0; c < N; c++) {
            float ABrc = 0;
            for (uint32_t i = 0; i < K; i++) {
                float B = tensor_q_net_4_weight[c][i];
                ABrc += A[r][i] * B;
            }
            float tmp = ABrc * alpha;
            tmp += C[0][c] * beta;
            Y[r][c] = tmp;
        }
}

void entry(const float tensor_input[1][4], float tensor_output[1][2]) {
    node_Flatten_0(tensor_input, tu0.tensor_7);
    node_Gemm_1(tu0.tensor_7, tensor_q_net_0_weight, tensor_q_net_0_bias, tu1.tensor_8);
    node_Relu_2(tu1.tensor_8, tu0.tensor_9);
    node_Gemm_3(tu0.tensor_9, tensor_q_net_2_weight, tensor_q_net_2_bias, tu1.tensor_10);
    node_Relu_4(tu1.tensor_10, tu0.tensor_11);
    node_Gemm_5(tu0.tensor_11, tensor_q_net_4_weight, tensor_q_net_4_bias, tensor_output);
}

int main()
{
    float tensor_input[1][4] = {
        {-0.255f, 0.338f, -0.070f, -0.945f} // fixed input within specified ranges
    };
    float tensor_output[1][2];

    entry(tensor_input, tensor_output);

    // Assert to check condition post model processing
    assert(!(tensor_output[0][0] <= tensor_output[0][1]));

    printf("Assertion passed successfully. Tensor output[0]: %f, Tensor output[1]: %f\n", tensor_output[0][0], tensor_output[0][1]);
    
    return 0;
}