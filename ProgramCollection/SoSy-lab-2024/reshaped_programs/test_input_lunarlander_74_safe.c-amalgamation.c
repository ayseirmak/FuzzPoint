#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

// Define macros for mathematical operations
#define MAX(X, Y) ((X) > (Y) ? (X) : (Y))
#define MIN(X, Y) ((X) < (Y) ? (X) : (Y))

// Initialize fixed deterministic values for tensor_input
const float fixed_tensor_input[1][8] = {
  {-0.75f, 0.2f, 0.0f, 0.0f, 0.05f, 0.0f, 0.0f, 0.0f}
};

// Declaration of functions
void entry(const float tensor_input[1][8], float tensor_output[1][4]);

int main()
{
    float tensor_output[1][4] = {0};  // Initialize output

    // Call the entry function with fixed, deterministic input
    entry(fixed_tensor_input, tensor_output);

    // Use assert to check conditions - similar to the original program
    if (!(tensor_output[0][3] > tensor_output[0][1])) {
        printf("Assertion failed: tensor_output[0][3] <= tensor_output[0][1]\n");
    }

    return 0;
}

// Definitions omitted for simplicity, assume they are the same as original