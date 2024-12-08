#include <stdio.h>
#include <stdint.h>

void entry(const float tensor_input[1][8], float tensor_output[1][4]);

int main()
{
    float tensor_input[1][8] = {
        {-0.8843f, 0.052f, 0.592f, -0.171f, -0.409f, 0.0f, 1.0f, 1.0f}
    };
    float tensor_output[1][4];

    // Assuming that there are previously set conditions
    entry(tensor_input, tensor_output);

    if (!(tensor_output[0][2] <= tensor_output[0][3])) {
        printf("Assertion passed: tensor_output[0][2] > tensor_output[0][3]\n");
    } else {
        printf("Assertion failed: tensor_output[0][2] <= tensor_output[0][3]\n");
    }

    return 0;
}

// The content of the `entry` function and the related network weights, biases, etc. are unchanged.
// Paste the full content from the original function and its dependencies here.