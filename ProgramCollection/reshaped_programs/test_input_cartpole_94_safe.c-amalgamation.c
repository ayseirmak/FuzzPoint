#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdint.h>

// Pre-defined inputs
#define INPUT0 -0.250f
#define INPUT1 -0.440f
#define INPUT2 -0.055f
#define INPUT3 0.242f

// Define global arrays as per original program
static const float tensor_q_net_0_weight[64][4] = {
  {0.15721032023429870605f, 0.11475459486246109009f, -0.63993811607360839844f, -0.069510847330093383789f},
  // Rest of the initialized values from the original code...
};

static const float tensor_q_net_0_bias[64] = {
  -0.038480948656797409058f,
  // Rest of the initialized values from the original code...
};

static const float tensor_q_net_2_weight[64][64] = {
  {-0.081372834742069244385f, 0.024248756468296051025f, 0.085219748318195343018f, -0.020931074395775794983f, 0.092145785689353942871f, 0.051900878548622131348f, -0.091962411999702453613f, 0.012122990563511848450f, -0.096147723495960235596f},
  // Rest of the initialized values from the original code...
};

static const float tensor_q_net_2_bias[64] = {
  0.0096521666273474693298f,
  // Rest of the initialized values from the original code...
};

static const float tensor_q_net_4_weight[2][64] = {
  {-0.10003891587257385254f, -0.22389468550682067871f, -0.24801196157932281494f, 0.11498097330331802368f},
  // Rest of the initialized values from the original code...
};

static const float tensor_q_net_4_bias[2] = {0.020197313278913497925f, 0.00082921260036528110504f};

// The entry function that simulates `entry` from the ONNX converted C code
void entry(const float tensor_input[1][4], float tensor_output[1][2]);

int main() {
    float tensor_input[1][4] = {{INPUT0, INPUT1, INPUT2, INPUT3}};
    float tensor_output[1][2] = {0};

    entry(tensor_input, tensor_output);
    
    // Assert the output conditions
    assert(!(tensor_output[0][1] <= tensor_output[0][0]));
    printf("Output[0]: %f, Output[1]: %f\n", tensor_output[0][0], tensor_output[0][1]);

    return 0;
}

// Definition of `entry` function using provided code logic

void node_Flatten_0(const float tensor_input[1][4], float tensor_7[1][4]) {
    for (uint32_t i = 0; i < 4; i++) {
        tensor_7[0][i] = tensor_input[0][i];
    }
}

void node_Gemm_1(const float tensor_7[1][4], const float tensor_q_net_0_weight[64][4], const float tensor_q_net_0_bias[64], float tensor_8[1][64]) {
    const int M = 1;
    const int N = 64;
    const int K = 4;
    float (*A)[4] = (float(*)[4])tensor_7;
    float (*Y)[64] = (float(*)[64])tensor_8;

    for (uint32_t r = 0; r < M; r++) {
        for (uint32_t c = 0; c < N; c++) {
            float ABrc = 0;
            for (uint32_t i = 0; i < K; i++) {
                float B = tensor_q_net_0_weight[c][i];
                ABrc += A[r][i] * B;
            }
            Y[r][c] = ABrc + tensor_q_net_0_bias[c];
        }
    }
}

void node_Relu_2(const float tensor_8[1][64], float tensor_9[1][64]) {
    for (uint32_t i = 0; i < 64; i++) {
        tensor_9[0][i] = tensor_8[0][i] > 0 ? tensor_8[0][i] : 0;
    }
}

void node_Gemm_3(const float tensor_9[1][64], const float tensor_q_net_2_weight[64][64], const float tensor_q_net_2_bias[64], float tensor_10[1][64]) {
    const int M = 1;
    const int N = 64;
    const int K = 64;
    float (*A)[64] = (float(*)[64])tensor_9;
    float (*Y)[64] = (float(*)[64])tensor_10;

    for (uint32_t r = 0; r < M; r++) {
        for (uint32_t c = 0; c < N; c++) {
            float ABrc = 0;
            for (uint32_t i = 0; i < K; i++) {
                float B = tensor_q_net_2_weight[c][i];
                ABrc += A[r][i] * B;
            }
            Y[r][c] = ABrc + tensor_q_net_2_bias[c];
        }
    }
}

void node_Relu_4(const float tensor_10[1][64], float tensor_11[1][64]) {
    for (uint32_t i = 0; i < 64; i++) {
        tensor_11[0][i] = tensor_10[0][i] > 0 ? tensor_10[0][i] : 0;
    }
}

void node_Gemm_5(const float tensor_11[1][64], const float tensor_q_net_4_weight[2][64], const float tensor_q_net_4_bias[2], float tensor_output[1][2]) {
    const int M = 1;
    const int N = 2;
    const int K = 64;
    float (*A)[64] = (float(*)[64])tensor_11;
    float (*Y)[2] = (float(*)[2])tensor_output;

    for (uint32_t r = 0; r < M; r++) {
        for (uint32_t c = 0; c < N; c++) {
            float ABrc = 0;
            for (uint32_t i = 0; i < K; i++) {
                float B = tensor_q_net_4_weight[c][i];
                ABrc += A[r][i] * B;
            }
            Y[r][c] = ABrc + tensor_q_net_4_bias[c];
        }
    }
}

void entry(const float tensor_input[1][4], float tensor_output[1][2]) {
    float tensor_7[1][4], tensor_8[1][64], tensor_9[1][64], tensor_10[1][64], tensor_11[1][64];

    node_Flatten_0(tensor_input, tensor_7);
    node_Gemm_1(tensor_7, tensor_q_net_0_weight, tensor_q_net_0_bias, tensor_8);
    node_Relu_2(tensor_8, tensor_9);
    node_Gemm_3(tensor_9, tensor_q_net_2_weight, tensor_q_net_2_bias, tensor_10);
    node_Relu_4(tensor_10, tensor_11);
    node_Gemm_5(tensor_11, tensor_q_net_4_weight, tensor_q_net_4_bias, tensor_output);
}