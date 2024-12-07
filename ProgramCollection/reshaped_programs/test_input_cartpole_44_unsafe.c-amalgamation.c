#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <stdint.h>

void entry(const float tensor_input[1][4], float tensor_output[1][2]);

static const float tensor_q_net_0_weight[64][4] = {
  {0.15721032023429870605f, 0.11475459486246109009f, -0.63993811607360839844f, -0.069510847330093383789f},
  // ...(rest of the array elements remain the same)
};

static const float tensor_q_net_0_bias[64] = {
  -0.038480948656797409058f, 0.12814424932003021240f, 0.49260348081588745117f, // ...(rest of the array elements remain the same)
};

static const float tensor_q_net_2_weight[64][64] = {
  {-0.081372834742069244385f, 0.024248756468296051025f, 0.085219748318195343018f, -0.020931074395775794983f, 
  // ...(rest of the array elements remain the same)
};

static const float tensor_q_net_2_bias[64] = {
  0.0096521666273474693298f, 0.033651806414127349854f, 0.039734158664941787720f, 0.20449157059192657471f, // ...(rest of the array elements remain the same)
};

static const float tensor_q_net_4_weight[2][64] = {
  {-0.10003891587257385254f, -0.22389468550682067871f, -0.24801196157932281494f, 0.11498097330331802368f, 
  // ...(rest of the array elements remain the same)
};

static const float tensor_q_net_4_bias[2] = {0.020197313278913497925f, 0.00082921260036528110504f};


void entry(const float tensor_input[1][4], float tensor_output[1][2]) {
  float tensor_7[1][4];
  float tensor_8[1][64];
  float tensor_9[1][64];
  float tensor_10[1][64];
  float tensor_11[1][64];

  // Flatten operation
  for (int i = 0; i < 4; i++) {
    tensor_7[0][i] = tensor_input[0][i];
  }

  // Gemm operation 1
  for (int i = 0; i < 64; i++) {
    tensor_8[0][i] = tensor_q_net_0_bias[i];
    for (int j = 0; j < 4; j++) {
      tensor_8[0][i] += tensor_7[0][j] * tensor_q_net_0_weight[i][j];
    }
  }

  // ReLU operation
  for (int i = 0; i < 64; i++) {
    tensor_9[0][i] = fmaxf(tensor_8[0][i], 0.0f);
  }

  // Gemm operation 2
  for (int i = 0; i < 64; i++) {
    tensor_10[0][i] = tensor_q_net_2_bias[i];
    for (int j = 0; j < 64; j++) {
      tensor_10[0][i] += tensor_9[0][j] * tensor_q_net_2_weight[i][j];
    }
  }

  // ReLU operation
  for (int i = 0; i < 64; i++) {
    tensor_11[0][i] = fmaxf(tensor_10[0][i], 0.0f);
  }

  // Gemm operation 3
  for (int i = 0; i < 2; i++) {
    tensor_output[0][i] = tensor_q_net_4_bias[i];
    for (int j = 0; j < 64; j++) {
      tensor_output[0][i] += tensor_11[0][j] * tensor_q_net_4_weight[i][j];
    }
  }
}

int main() {
  // Deterministic fixed inputs matching initial assumed ranges
  float tensor_input[1][4] = {
    {-0.05156f, -0.43216f, -0.03369f, 0.40742f}
  };
  float tensor_output[1][2];

  entry(tensor_input, tensor_output);

  // Assert the output condition as in the original assert
  assert(!(tensor_output[0][1] <= tensor_output[0][0]));

  // Print outputs for verification
  printf("tensor_output[0][0]: %f\n", tensor_output[0][0]);
  printf("tensor_output[0][1]: %f\n", tensor_output[0][1]);

  return 0;
}