// SPDX-FileCopyrightText: 2023 Edoardo Manino
// SPDX-License-Identifier: MIT

#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdint.h>

// Function prototype
void entry(const float tensor_input[1][4], float tensor_output[1][2]);

int main()
{
    float tensor_input[1][4];
    float tensor_output[1][2];

    // Fixed input values within the assumed bounds
    tensor_input[0][0] = -0.38f;  // Within [-0.4163068504743891, -0.3443856895256109]
    tensor_input[0][1] = 1.08f;   // Within [1.0451431195256107, 1.117064280474389]
    tensor_input[0][2] = -0.16f;  // Within [-0.19274238047438913, -0.12082121952561088]
    tensor_input[0][3] = -1.60f;  // Within [-1.6365536804743892, -1.5646325195256108]

    entry(tensor_input, tensor_output);

    // Assert output condition
    assert(!(tensor_output[0][0] <= tensor_output[0][1]));

    return 0;
}

// Rest of the code (entry function and its dependencies)

// Add the code for the function `entry` here

// `entry` and related functions are lengthy because of the weights and biases and should be inserted here.