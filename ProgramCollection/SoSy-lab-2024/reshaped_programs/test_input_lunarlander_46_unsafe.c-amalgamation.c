#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdint.h>

// Define the `entry` function as provided in the original code.
void entry(const float tensor_input[1][8], float tensor_output[1][4]);

int main() {
    // Initialize inputs
    float tensor_input[1][8] = {
        {-0.72f, 0.03f, 0.05f, -0.06f, -0.01f, -0.04f, 1.0f, 1.0f}
    };

    float tensor_output[1][4] = {0};

    // Call the entry function
    entry(tensor_input, tensor_output);

    // Assert condition as per the original logic
    assert(!(tensor_output[0][2] <= tensor_output[0][3]));

    // Print output tensor
    printf("Output tensor: [%f, %f, %f, %f]\n",
           tensor_output[0][0], tensor_output[0][1], 
           tensor_output[0][2], tensor_output[0][3]);

    return 0;
}

// The 'entry' function implementation as provided is assumed to be added here ...