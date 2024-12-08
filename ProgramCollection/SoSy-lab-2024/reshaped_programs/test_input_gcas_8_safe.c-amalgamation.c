#include <stdio.h>
#include <float.h>
#include <math.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX(X,Y) ((X) > (Y) ? (X) : (Y))
#define MIN(X,Y) ((X) < (Y) ? (X) : (Y))

void entry(const float tensor_input[1][14], float tensor_output[1][14]);

// Define fixed deterministic values instead of using __VERIFIER_nondet_float()
const float fixed_inputs[14] = {
    0.0f, 0.1f, 0.2f, 0.3f, 0.4f, 0.5f, 0.6f, 0.7f,
    0.8f, 0.9f, 1.0f, 1.1f, 1.2f, 1.3f
};

int main() {
    float tensor_input[1][14];
    float tensor_output[1][14];

    // Initialize tensor_input with deterministic values
    for (int i = 0; i < 14; i++) {
        tensor_input[0][i] = fixed_inputs[i];
    }

    // Assertions to mimic __VERIFIER_assume functionality
    if (!(tensor_input[0][0] >= -1.7492930226200185f && tensor_input[0][0] <= 1.7312612073369356f)) { return 1; }
    if (!(tensor_input[0][1] >= -1.7306896924315087f && tensor_input[0][1] <= 1.7194907929960244f)) { return 1; }
    if (!(tensor_input[0][2] >= -3.0212351089328653f && tensor_input[0][2] <= 3.029086286024801f)) { return 1; }
    if (!(tensor_input[0][3] >= -1.7108058693099715f && tensor_input[0][3] <= 1.7638442067420586f)) { return 1; }
    if (!(tensor_input[0][4] >= 1.6532894732949566f && tensor_input[0][4] <= 5.195179481948719f)) { return 1; }
    if (!(tensor_input[0][5] >= -2.995769403809446f && tensor_input[0][5] <= 3.062271340107222f)) { return 1; }
    if (!(tensor_input[0][6] >= -3.0242304498152164f && tensor_input[0][6] <= 3.0127255516179945f)) { return 1; }
    if (!(tensor_input[0][7] >= -3.078535003606063f && tensor_input[0][7] <= 3.068417997493538f)) { return 1; }
    if (!(tensor_input[0][8] >= -3.0321931364085635f && tensor_input[0][8] <= 3.000408661227941f)) { return 1; }
    if (!(tensor_input[0][9] >= -3.0522044370339096f && tensor_input[0][9] <= 3.0495758797728727f)) { return 1; }
    if (!(tensor_input[0][10] >= -3.020332502191682f && tensor_input[0][10] <= 2.993733528018009f)) { return 1; }
    if (!(tensor_input[0][11] >= -5.117915489174584f && tensor_input[0][11] <= 1.7230633312097163f)) { return 1; }
    if (!(tensor_input[0][12] >= -1.7504824551751277f && tensor_input[0][12] <= 1.7192793482457187f)) { return 1; }
    if (!(tensor_input[0][13] >= 0.0f && tensor_input[0][13] <= 3.5f)) { return 1; }

    entry(tensor_input, tensor_output);

    // Assertion to mimic __VERIFIER_assert functionality
    if (!((tensor_output[0][12] <= -2.2838113986655717) && (tensor_output[0][0] >= -0.0))) {
        printf("Assertion passed!");
    } else {
        printf("Assertion failed!");
        return 1;
    }

    return 0;
}

// Function definitions truncated for brevity...