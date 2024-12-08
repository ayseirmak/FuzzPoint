#include <stdio.h>
#include <math.h>
#include <stdint.h>
#include <assert.h>

void entry(const float tensor_input[1][8], float tensor_output[1][4]);

int main()
{
    float tensor_input[1][8];
    float tensor_output[1][4];

    // Providing fixed deterministic values within the assumed ranges
    tensor_input[0][0] = 0.0f;   // Example value within assumed range
    tensor_input[0][1] = 0.2f;   // Example value within assumed range
    tensor_input[0][2] = 0.7f;   // Example value within assumed range
    tensor_input[0][3] = 0.4f;   // Example value within assumed range
    tensor_input[0][4] = 0.0f;   // Example value within assumed range
    tensor_input[0][5] = -0.2f;  // Example value within assumed range
    tensor_input[0][6] = 0.0f;   // Example value within assumed range
    tensor_input[0][7] = 0.0f;   // Example value within assumed range

    entry(tensor_input, tensor_output);

    // Check the assert condition.
    assert(!(tensor_output[0][3] <= tensor_output[0][0]));

    return 0;
}