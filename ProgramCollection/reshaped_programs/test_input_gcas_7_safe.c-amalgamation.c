#include <stdio.h>
#include <math.h>
#include <stdint.h>
#include <assert.h>

void entry(const float tensor_input[1][14], float tensor_output[1][14]);

int main()
{
    float tensor_input[1][14];
    float tensor_output[1][14];

    // Deterministic and fixed inputs
    tensor_input[0][0] = 0.0f;
    tensor_input[0][1] = 0.1f;
    tensor_input[0][2] = -0.1f;
    tensor_input[0][3] = 1.0f;
    tensor_input[0][4] = 0.5f;
    tensor_input[0][5] = -0.5f;
    tensor_input[0][6] = 2.0f;
    tensor_input[0][7] = -1.0f;
    tensor_input[0][8] = 3.0f;
    tensor_input[0][9] = -3.0f;
    tensor_input[0][10] = 0.3f;
    tensor_input[0][11] = -0.3f;
    tensor_input[0][12] = 0.2f;
    tensor_input[0][13] = -0.2f;

    entry(tensor_input, tensor_output);

    // Convert verifier assertions to standard assertions
    assert(!((tensor_output[0][12] <= -2.2838113986655717) && (tensor_output[0][0] >= -0.0)));

    // Logging the output for verification
    printf("Tensor output: \n");
    for (int i = 0; i < 14; i++) {
        printf("%.5f ", tensor_output[0][i]);
    }
    printf("\n");

    return 0;
}

// The rest of your model code remains unchanged
// This includes the function entry and all its dependencies