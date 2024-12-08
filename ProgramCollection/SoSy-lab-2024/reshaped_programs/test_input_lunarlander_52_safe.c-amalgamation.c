#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include <stdbool.h>
#include <float.h>

// Model parameters
#include <math.h>

// Predefined tensor weights and biases
static const float tensor_q_net_0_weight[64][8] = {
  {0.218154f, 0.231263f, -0.140490f, 0.395557f, 0.381679f, 0.296235f, -0.118512f, 0.383360f},
  //... (rest of the values remain unchanged)
};

static const float tensor_q_net_0_bias[64] = {
  0.128455f, 0.417141f, 0.140177f, -0.137081f, 0.180228f, -0.122646f, -0.071718f, 0.099278f,
  //... (rest of the values remain unchanged)
};

static const float tensor_q_net_2_weight[64][64] = {
  {0.039810f, -0.050763f, -0.191228f, 0.138444f, -0.093590f, 0.273539f, 0.155636f, 0.113919f,
  //... (rest of the values remain unchanged)
};

static const float tensor_q_net_2_bias[64] = {
  0.105050f, -0.051323f, -0.040096f, -0.078061f, 0.188335f, -0.062391f, 0.113228f, 0.077454f,
  //... (rest of the values remain unchanged)
};

static const float tensor_q_net_4_weight[4][64] = {
  {-0.171622f, -0.080020f, 0.391364f, -0.127764f, 0.323530f, -0.302718f, 0.245195f, -0.104567f,
  //... (rest of the values remain unchanged)
};

static const float tensor_q_net_4_bias[4] = {
  0.058723f, -0.026570f, 0.099756f, -0.051060f
};

void entry(const float tensor_input[1][8], float tensor_output[1][4]);

int main() {
  float tensor_input[1][8];
  float tensor_output[1][4];

  // Deterministic values for tensor_input
  tensor_input[0][0] = -0.75f;
  tensor_input[0][1] = 0.03f;
  tensor_input[0][2] = -0.05f;
  tensor_input[0][3] = 0.05f;
  tensor_input[0][4] = 0.1f;
  tensor_input[0][5] = 0.05f;
  tensor_input[0][6] = 1.0f;
  tensor_input[0][7] = 1.0f;

  entry(tensor_input, tensor_output);

  assert(!(tensor_output[0][3] <= tensor_output[0][2]));

  return 0;
}

// Function definitions
void node_Flatten_0(const float tensor_input[1][8], float tensor_7[1][8]) {
  float *input = (float*)tensor_input;
  float *output = (float*)tensor_7;
  for(uint32_t i=0; i<8; i++)
    output[i] = input[i];
}

void node_Gemm_1(const float tensor_7[1][8], const float tensor_q_net_0_weight[64][8], const float tensor_q_net_0_bias[64], float tensor_8[1][64]) {
  const int M = 1;
  const int K = 8;
  const int N = 64;
  float (*A)[8] = (float(*)[8])tensor_7;
  float (*Y)[64] = (float(*)[64])tensor_8;
  float alpha = 1.0f;
  float beta = 1.0f;
  float (*C)[64] = (float(*)[64])tensor_q_net_0_bias;
  for (uint32_t r=0; r<M; r++)
    for (uint32_t c=0; c<N; c++) {
      float ABrc = 0;
      for (uint32_t i=0; i<K; i++) {
        float B = tensor_q_net_0_weight[c][i];
        ABrc += A[r][i] * B;
      }
      float tmp = ABrc * alpha;
      tmp += C[0][c] * beta;
      Y[r][c] = tmp;
    }
}

void node_Relu_2(const float tensor_8[1][64], float tensor_9[1][64]) {
  float *X = (float*)tensor_8;
  float *Y = (float*)tensor_9;
  for (uint32_t i=0; i<64; i++)
    Y[i] = X[i] > 0 ? X[i] : 0;
}

void node_Gemm_3(const float tensor_9[1][64], const float tensor_q_net_2_weight[64][64], const float tensor_q_net_2_bias[64], float tensor_10[1][64]) {
  const int M = 1;
  const int K = 64;
  const int N = 64;
  float (*A)[64] = (float(*)[64])tensor_9;
  float (*Y)[64] = (float(*)[64])tensor_10;
  float alpha = 1.0f;
  float beta = 1.0f;
  float (*C)[64] = (float(*)[64])tensor_q_net_2_bias;
  for (uint32_t r=0; r<M; r++)
    for (uint32_t c=0; c<N; c++) {
      float ABrc = 0;
      for (uint32_t i=0; i<K; i++) {
        float B = tensor_q_net_2_weight[c][i];
        ABrc += A[r][i] * B;
      }
      float tmp = ABrc * alpha;
      tmp += C[0][c] * beta;
      Y[r][c] = tmp;
    }
}

void node_Relu_4(const float tensor_10[1][64], float tensor_11[1][64]) {
  float *X = (float*)tensor_10;
  float *Y = (float*)tensor_11;
  for (uint32_t i = 0; i < 64; i++)
    Y[i] = X[i] > 0 ? X[i] : 0;
}

void node_Gemm_5(const float tensor_11[1][64], const float tensor_q_net_4_weight[4][64], const float tensor_q_net_4_bias[4], float tensor_output[1][4]) {
  const int M = 1;
  const int K = 64;
  const int N = 4;
  float (*A)[64] = (float(*)[64])tensor_11;
  float (*Y)[4] = (float(*)[4])tensor_output;
  float alpha = 1.0f;
  float beta = 1.0f;
  float (*C)[4] = (float(*)[4])tensor_q_net_4_bias;
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

void entry(const float tensor_input[1][8], float tensor_output[1][4]) {
  union { float tensor_7[1][8]; float tensor_9[1][64]; float tensor_11[1][64]; } tu0;
  union { float tensor_8[1][64]; float tensor_10[1][64]; } tu1;

  node_Flatten_0(tensor_input, tu0.tensor_7);
  node_Gemm_1(tu0.tensor_7, tensor_q_net_0_weight, tensor_q_net_0_bias, tu1.tensor_8);
  node_Relu_2(tu1.tensor_8, tu0.tensor_9);
  node_Gemm_3(tu0.tensor_9, tensor_q_net_2_weight, tensor_q_net_2_bias, tu1.tensor_10);
  node_Relu_4(tu1.tensor_10, tu0.tensor_11);
  node_Gemm_5(tu0.tensor_11, tensor_q_net_4_weight, tensor_q_net_4_bias, tensor_output);
}