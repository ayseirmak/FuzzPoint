#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <stdint.h>
#include <stdbool.h>

// Function prototypes
void entry(const float tensor_input[1][14], float tensor_output[1][14]);

// Predefined fixed input values for deterministic behavior.
#define FIXED_INPUT_VALUES {1.0f, 0.5f, -0.5f, 1.0f, 2.0f, -1.0f, 0.0f, -0.3f, 1.2f, -1.2f, 0.3f, 0.7f, -0.7f, 0.0f}

int main() {
    float tensor_input[1][14] = {FIXED_INPUT_VALUES};
    float tensor_output[1][14];
    
    // Ensure input values meet the original constraints.
    assert(tensor_input[0][0] >= -1.7492930226200185f && tensor_input[0][0] <= 1.7312612073369356f);
    assert(tensor_input[0][1] >= -1.7306896924315087f && tensor_input[0][1] <= 1.7194907929960244f);
    assert(tensor_input[0][2] >= -3.359414996589872f && tensor_input[0][2] <= 3.367266173681808f);
    assert(tensor_input[0][3] >= -1.7108058693099715f && tensor_input[0][3] <= 1.7638442067420586f);
    assert(tensor_input[0][4] >= 1.4415085045840699f && tensor_input[0][4] <= 5.195179481948719f);
    assert(tensor_input[0][5] >= -3.334380760870031f && tensor_input[0][5] <= 3.4008826971678072f);
    assert(tensor_input[0][6] >= -3.3616632850454944f && tensor_input[0][6] <= 3.3501583868482725f);
    assert(tensor_input[0][7] >= -3.4221160697420228f && tensor_input[0][7] <= 3.411999063629498f);
    assert(tensor_input[0][8] >= -3.369382595451911f && tensor_input[0][8] <= 3.3375981202712888f);
    assert(tensor_input[0][9] >= -3.39326059708603f && tensor_input[0][9] <= 3.3906320398249936f);
    assert(tensor_input[0][10] >= -3.3564859131746307f && tensor_input[0][10] <= 3.329886939000958f);
    assert(tensor_input[0][11] >= -5.117915489174584f && tensor_input[0][11] <= 1.7230633312097163f);
    assert(tensor_input[0][12] >= -1.7504824551751277f && tensor_input[0][12] <= 1.7192793482457187f);
    assert(tensor_input[0][13] >= 0.0f && tensor_input[0][13] <= 3.5f);

    entry(tensor_input, tensor_output);

    assert(!((tensor_output[0][12] <= -2.2838113986655717) && (tensor_output[0][0] >= -0.0)));
    
    printf("Assertion passed.\n");
    return 0;
}

// Include the pre-existing complex machinery for processing, such as node_Gemm_N, node_Relu_N etc.
// Omitted for brevity.