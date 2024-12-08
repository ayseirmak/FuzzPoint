#include <stdio.h>
#include <math.h>
#include <stdint.h>

// Standard C headers
#include <assert.h>

// Functions for the entry processing
void entry(const float tensor_input[1][8], float tensor_output[1][4]);

// Replace nondeterministic inputs with fixed, deterministic values
float fixed_tensor_input[1][8] = {
    {-0.73f, 0.05f, 0.03f, -0.05f, -0.06f, -0.07f, 1.0f, 1.0f}
};

float tensor_output[1][4];

// Main function to call the entry processing function
int main() {
    entry(fixed_tensor_input, tensor_output);

    // Assert or print statements to verify program behavior
    for(int i = 0; i < 4; i++) {
        printf("tensor_output[0][%d] = %f\n", i, tensor_output[0][i]);
    }

    // Replacing __VERIFIER_assert with standard assert function
    assert(!(tensor_output[0][2] <= tensor_output[0][3]));

    return 0;
}

// [Include all necessary code and functions here exactly as they are necessary for the entry function.]

// Insert all the static arrays and entry function below