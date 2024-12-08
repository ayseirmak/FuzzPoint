#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <assert.h>
#include <float.h>

// Function declarations
void entry(const float tensor_input[1][4], float tensor_output[1][2]);

int main() {
    float tensor_input[1][4];
    float tensor_output[1][2];

    // Deterministic inputs within specified bounds
    tensor_input[0][0] = -0.255f;  // Random value within -0.26130052959386224f to -0.25032697040613777f
    tensor_input[0][1] = -0.051f;  // Random value within -0.05648612659386224f to -0.04551256740613776f
    tensor_input[0][2] = -0.062f;  // Random value within -0.06761689559386225f to -0.05664333640613776f
    tensor_input[0][3] = -0.379f;  // Random value within -0.38437800959386226f to -0.3734044504061378f

    entry(tensor_input, tensor_output);

    assert(!(tensor_output[0][0] <= tensor_output[0][1]));

    return 0;
}

// The definitions of the onnx2c-generated functions
// and static arrays follow after this comment.
// Ensure to properly define `entry` and its static data.