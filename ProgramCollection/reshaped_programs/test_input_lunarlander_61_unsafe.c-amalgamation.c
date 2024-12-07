#include <stdio.h>
#include <math.h>
#include <assert.h>

// ONNX model transformed functions and data
void entry(const float tensor_input[1][8], float tensor_output[1][4]);

int main()
{
    float tensor_input[1][8] = {
        {-0.9053f, 0.0622f, 0.7754f, -0.2240f, -0.4089f, 0.000f, 1.000f, 0.000f}
    };
    float tensor_output[1][4] = {0};

    // Assume equivalent: Check if tensor_input values are within the expected range
    assert(tensor_input[0][0] >= -0.9369f && tensor_input[0][0] <= -0.8637f);
    assert(tensor_input[0][1] >= 0.0256f && tensor_input[0][1] <= 0.0988f);
    assert(tensor_input[0][2] >= 0.7388f && tensor_input[0][2] <= 0.8120f);
    assert(tensor_input[0][3] >= -0.2606f && tensor_input[0][3] <= -0.1875f);
    assert(tensor_input[0][4] >= -0.4454f && tensor_input[0][4] <= -0.3723f);
    assert(tensor_input[0][5] >= -0.0366f && tensor_input[0][5] <= 0.0366f);
    assert(tensor_input[0][6] >= 0.9634f && tensor_input[0][6] <= 1.0366f);
    assert(tensor_input[0][7] >= -0.0366f && tensor_input[0][7] <= 0.0366f);

    entry(tensor_input, tensor_output);

    // Assert or condition to verify output
    assert(!(tensor_output[0][3] <= tensor_output[0][0]));

    return 0;
}